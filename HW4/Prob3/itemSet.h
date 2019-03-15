#ifndef ITEMSET_H
#define ITEMSET_H

template <class anyType>
class ItemSet
{
public:
  ItemSet();
  ItemSet(int arrSize);
  void addToSet(anyType thing);
  anyType getItem(int index) {return item[index];}
  int getItemArrSize() {return itemArrSize;}
  ~ItemSet();
private:
  anyType *item;
  int itemArrSize;

};

//inline implimentation for templates
#include "itemSet.inl" //implementation

#endif //ITEMSET_H
