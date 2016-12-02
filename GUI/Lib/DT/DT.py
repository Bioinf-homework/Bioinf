# coding=utf-8
from math import log
import csv
# import json

def read_data():
    with open('data.csv', 'rb') as myFile:
        lines = csv.reader(myFile)
        labels = lines.next()
        data = []
        for line in lines:
            data.append(line)
    return data, labels


def calcShannonEnt(dataSet):
    numEntries = len(dataSet)
    labelCounts = {}
    for featVec in dataSet:
        currentLabel = featVec[-1]
        labelCounts[currentLabel] = labelCounts.get(currentLabel, 0) + 1
    shannonEnt = 0.0
    for key in labelCounts:
        prob = float(labelCounts[key]) / numEntries
        shannonEnt -= prob * log(prob, 2)  # 首先计算熵，它的作用是要用它计算每个特征的信息增益
    return shannonEnt  # 熵越高混合的数据也越多


def splitDataSet(dataSet, axis, value):
    """
    切分非离散特征
    :param dataSet:
    :param axis:
    :param value:
    :return:
    """
    retDataSet = []
    for featVec in dataSet:
        if featVec[axis] == value:
            reducedFeatVec = featVec[:axis]
            reducedFeatVec.extend(featVec[axis + 1:])
            retDataSet.append(reducedFeatVec)
    # print(retDataSet)
    return retDataSet

# 返回出现次数最多的分类名称
def majorityCnt(classList):
    classCount = {}
    for vote in classList:
        if vote not in classCount.keys(): classCount[vote] = 0
        classCount[vote] += 1
    print(classCount)
    maxc = 0
    maxn = ""
    for i in classCount:
        if classCount[i] > maxc:
            maxc = classCount[i]
            maxn = i
        # print classCount[i]
    return maxn
    # sortedClassCount = sorted(classCount.iteritems(), key=operator.itemgetter(1), reverse=True)
    # return sortedClassCount[0][0]


# 选取特征，划分数据集，计算得出最好的划分数据集的特征
def chooseBestFeatureToSplit(dataSet):
    numFeatures = len(dataSet[0]) - 1  # 剩下的是特征的个数
    baseEntropy = calcShannonEnt(dataSet)  # 计算数据集的熵，放到baseEntropy中
    print "root:",
    print baseEntropy
    bestInfoGain = 0.0;
    bestFeature = -1
    # todo:如果是连续型的，计算出最佳的划分点，再对比信息增益选择最佳特征
    for i in range(numFeatures):
        featList = [example[i] for example in dataSet]
        uniqueVals = set(featList)
        newEntropy = 0.0
        for value in uniqueVals:  # 下面是计算每种划分方式的信息熵,特征i个，每个特征value个值
            subDataSet = splitDataSet(dataSet, i, value)
            prob = len(subDataSet) / float(len(dataSet))
            newEntropy += prob * calcShannonEnt(subDataSet)
        print uniqueVals
        print newEntropy
        infoGain = baseEntropy - newEntropy  # 计算i个特征的信息熵
        # print(infoGain)
        if (infoGain > bestInfoGain):
            bestInfoGain = infoGain
            bestFeature = i
    return bestFeature


def createTree(dataSet, labels):
    classList = [example[-1] for example in dataSet]  # 将最后一行的数据放到classList中

    # 当前数据集中只有一种类型，直接返回
    if classList.count(classList[0]) == len(classList):
        return classList[0]

    # 当前数据集没有特征，直接返回剩余最大可能性的类型
    if len(dataSet[0]) == 1:  # 只剩一维的分类
        return majorityCnt(classList)

    bestFeat = chooseBestFeatureToSplit(dataSet)

    bestFeatLabel = labels[bestFeat]
    myTree = {bestFeatLabel: {}}
    del (labels[bestFeat])
    featValues = [example[bestFeat] for example in dataSet]  # 取出所有特征取值
    uniqueVals = set(featValues)
    for value in uniqueVals:
        subLabels = labels[:]
        myTree[bestFeatLabel][value] = createTree(splitDataSet(dataSet, bestFeat, value), subLabels)

    return myTree

x, y = read_data()



mytree = createTree(x, y)
with open("re.txt","w") as f:
    f.write(str(mytree))
# print(str(mytree))
