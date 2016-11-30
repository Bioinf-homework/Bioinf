#ifndef __DT_HPP
#define __DT_HPP

using namespace __shedskin__;
namespace __DT__ {

extern str *const_0, *const_1, *const_2, *const_3, *const_4;



extern tuple2<list<list<str *> *> *, list<str *> *> *__49;
extern pyiter<str *> *mytree;
extern list<list<str *> *> *x;
extern str *__name__;
extern list<str *> *y;
extern file *f;


tuple2<list<list<str *> *> *, list<str *> *> *read_data();
double calcShannonEnt(list<list<str *> *> *dataSet);
list<list<str *> *> *splitDataSet(list<list<str *> *> *dataSet, __ss_int axis, str *value);
str *majorityCnt(list<str *> *classList);
__ss_int chooseBestFeatureToSplit(list<list<str *> *> *dataSet);
pyiter<str *> *createTree(list<list<str *> *> *dataSet, list<str *> *labels);

} // module namespace
#endif
