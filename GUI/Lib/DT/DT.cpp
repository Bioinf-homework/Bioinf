#include "builtin.hpp"
#include "csv.hpp"
#include "math.hpp"
#include "DT.hpp"

namespace __DT__ {

str *const_0, *const_1, *const_2, *const_3, *const_4, *const_5;

using __math__::log;

list<str *> *y;
file *f;
str *__name__;
list<list<str *> *> *x;
pyiter<str *> *mytree;
tuple2<list<list<str *> *> *, list<str *> *> *__49;


static inline list<str *> *list_comp_0(__ss_int i, list<list<str *> *> *dataSet);
static inline list<str *> *list_comp_1(list<list<str *> *> *dataSet);
static inline list<str *> *list_comp_2(__ss_int bestFeat, list<list<str *> *> *dataSet);

static inline list<str *> *list_comp_0(__ss_int i, list<list<str *> *> *dataSet) {
    __iter<list<str *> *> *__29;
    list<str *> *example;
    list<list<str *> *> *__28;
    __ss_int __30;
    list<list<str *> *>::for_in_loop __31;

    list<str *> *__ss_result = new list<str *>();

    __ss_result->resize(len(dataSet));
    FOR_IN(example,dataSet,28,30,31)
        __ss_result->units[__30] = example->__getfast__(i);
    END_FOR

    return __ss_result;
}

static inline list<str *> *list_comp_1(list<list<str *> *> *dataSet) {
    __iter<list<str *> *> *__37;
    list<str *> *example;
    list<list<str *> *> *__36;
    __ss_int __38;
    list<list<str *> *>::for_in_loop __39;

    list<str *> *__ss_result = new list<str *>();

    __ss_result->resize(len(dataSet));
    FOR_IN(example,dataSet,36,38,39)
        __ss_result->units[__38] = example->__getfast__((-1));
    END_FOR

    return __ss_result;
}

static inline list<str *> *list_comp_2(__ss_int bestFeat, list<list<str *> *> *dataSet) {
    __iter<list<str *> *> *__41;
    list<str *> *example;
    list<list<str *> *> *__40;
    __ss_int __42;
    list<list<str *> *>::for_in_loop __43;

    list<str *> *__ss_result = new list<str *>();

    __ss_result->resize(len(dataSet));
    FOR_IN(example,dataSet,40,42,43)
        __ss_result->units[__42] = example->__getfast__(bestFeat);
    END_FOR

    return __ss_result;
}

tuple2<list<list<str *> *> *, list<str *> *> *read_data() {
    list<str *> *labels, *line;
    __iter<list<str *> *> *__1;
    file *myFile;
    __csv__::reader *__0, *lines;
    __ss_int __2;
    list<list<str *> *> *data;
    __csv__::reader::for_in_loop __3;

    WITH_VAR(open(const_0, const_1),myFile,0)
        lines = (new __csv__::reader(myFile, NULL, NULL, NULL, (-1), (-1), NULL, (-1), NULL, (-1)));
        labels = lines->next();
        data = (new list<list<str *> *>());

        FOR_IN(line,lines,0,2,3)
            data->append(line);
        END_FOR

    END_WITH
    return (new tuple2<list<list<str *> *> *, list<str *> *>(2,data,labels));
}

double calcShannonEnt(list<list<str *> *> *dataSet) {
    list<str *> *featVec;
    list<list<str *> *>::for_in_loop __7;
    dict<str *, __ss_int> *__8, *labelCounts;
    double prob, shannonEnt;
    __iter<str *> *__9;
    __iter<list<str *> *> *__5;
    str *currentLabel, *key;
    dict<str *, __ss_int>::for_in_loop __11;
    list<list<str *> *> *__4;
    __ss_int __10, __6, numEntries;

    numEntries = len(dataSet);
    labelCounts = (new dict<str *, __ss_int>());

    FOR_IN(featVec,dataSet,4,6,7)
        currentLabel = featVec->__getfast__((-1));
        labelCounts->__setitem__(currentLabel, (labelCounts->get(currentLabel, 0)+1));
    END_FOR

    shannonEnt = 0.0;

    FOR_IN(key,labelCounts,8,10,11)
        prob = (__float(labelCounts->__getitem__(key))/numEntries);
        shannonEnt = (shannonEnt-(prob*log(prob, 2)));
    END_FOR

    return shannonEnt;
}

list<list<str *> *> *splitDataSet(list<list<str *> *> *dataSet, __ss_int axis, str *value) {
    /**
    切分非离散特征
    :param dataSet:
    :param axis:
    :param value:
    :return:
    */
    list<str *> *featVec, *reducedFeatVec;
    __iter<list<str *> *> *__13;
    list<list<str *> *> *__12, *retDataSet;
    __ss_int __14;
    list<list<str *> *>::for_in_loop __15;

    retDataSet = (new list<list<str *> *>());

    FOR_IN(featVec,dataSet,12,14,15)
        if (__eq(featVec->__getfast__(axis), value)) {
            reducedFeatVec = featVec->__slice__(2, 0, axis, 0);
            reducedFeatVec->extend(featVec->__slice__(1, (axis+1), 0, 0));
            retDataSet->append(reducedFeatVec);
        }
    END_FOR

    return retDataSet;
}

str *majorityCnt(list<str *> *classList) {
    list<str *> *__16;
    dict<str *, __ss_int> *__20, *__22, *classCount;
    __iter<str *> *__17, *__23;
    list<str *>::for_in_loop __19;
    str *__21, *i, *maxn, *vote;
    dict<str *, __ss_int>::for_in_loop __25;
    __ss_int __18, __24, maxc;

    classCount = (new dict<str *, __ss_int>());

    FOR_IN(vote,classList,16,18,19)
        if ((!(classCount->keys())->__contains__(vote))) {
            classCount->__setitem__(vote, 0);
        }
        classCount->__addtoitem__(vote, 1);
    END_FOR

    print2(NULL,0,1, classCount);
    maxc = 0;
    maxn = const_2;

    FOR_IN(i,classCount,22,24,25)
        if ((classCount->__getitem__(i)>maxc)) {
            maxc = classCount->__getitem__(i);
            maxn = i;
        }
    END_FOR

    return maxn;
}

__ss_int chooseBestFeatureToSplit(list<list<str *> *> *dataSet) {
    list<str *> *featList;
    double baseEntropy, bestInfoGain, infoGain, newEntropy, prob;
    __iter<str *> *__33;
    set<str *>::for_in_loop __35;
    str *value;
    set<str *> *__32, *uniqueVals;
    list<list<str *> *> *subDataSet;
    __ss_int __26, __27, __34, bestFeature, i, numFeatures;

    numFeatures = (len(dataSet->__getfast__(0))-1);
    baseEntropy = calcShannonEnt(dataSet);
    print2(NULL,1,1, const_3);
    print2(NULL,0,1, ___box(baseEntropy));
    bestInfoGain = 0.0;
    bestFeature = (-1);

    FAST_FOR(i,0,numFeatures,1,26,27)
        featList = list_comp_0(i, dataSet);
        uniqueVals = (new set<str *>(featList));
        newEntropy = 0.0;

        FOR_IN(value,uniqueVals,32,34,35)
            subDataSet = splitDataSet(dataSet, i, value);
            prob = (len(subDataSet)/__float(len(dataSet)));
            newEntropy = (newEntropy+(prob*calcShannonEnt(subDataSet)));
        END_FOR

        print2(NULL,0,1, uniqueVals);
        print2(NULL,0,1, ___box(newEntropy));
        infoGain = (baseEntropy-newEntropy);
        if ((infoGain>bestInfoGain)) {
            bestInfoGain = infoGain;
            bestFeature = i;
        }
    END_FOR

    return bestFeature;
}

pyiter<str *> *createTree(list<list<str *> *> *dataSet, list<str *> *labels) {
    list<str *> *classList, *featValues, *subLabels;
    dict<str *, dict<str *, pyiter<str *> *> *> *myTree;
    set<str *>::for_in_loop __47;
    str *bestFeatLabel, *value;
    __iter<str *> *__45;
    dict<str *, pyiter<str *> *> *__48;
    set<str *> *__44, *uniqueVals;
    __ss_int __46, bestFeat;

    classList = list_comp_1(dataSet);
    if ((classList->count(classList->__getfast__(0))==len(classList))) {
        return classList->__getfast__(0);
    }
    if ((len(dataSet->__getfast__(0))==1)) {
        return majorityCnt(classList);
    }
    bestFeat = chooseBestFeatureToSplit(dataSet);
    bestFeatLabel = labels->__getfast__(bestFeat);
    myTree = (new dict<str *, dict<str *, pyiter<str *> *> *>(1, (new tuple2<str *, dict<str *, pyiter<str *> *> *>(2,bestFeatLabel,(new dict<str *, pyiter<str *> *>())))));
    labels->__delitem__(bestFeat);
    featValues = list_comp_2(bestFeat, dataSet);
    uniqueVals = (new set<str *>(featValues));

    FOR_IN(value,uniqueVals,44,46,47)
        subLabels = labels->__slice__(0, 0, 0, 0);
        myTree->__getitem__(bestFeatLabel)->__setitem__(value, createTree(splitDataSet(dataSet, bestFeat, value), subLabels));
    END_FOR

    return ((pyiter<str *> *)(myTree));
}

void __init() {
    const_0 = new str("data.csv");
    const_1 = new str("rb");
    const_2 = new str("");
    const_3 = new str("root:");
    const_4 = new str("re.txt");
    const_5 = __char_cache[119];;

    __name__ = new str("__main__");

    __49 = read_data();
    x = __49->__getfirst__();
    y = __49->__getsecond__();
    mytree = createTree(x, y);
    WITH_VAR(open(const_4, const_5),f,1)
        f->write(__str(mytree));
    END_WITH
}

} // module namespace

int main(int, char **) {
    __shedskin__::__init();
    __math__::__init();
    __csv__::__init();
    __shedskin__::__start(__DT__::__init);
}
