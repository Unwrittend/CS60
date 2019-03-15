//#include "itemSet.h"
#include <new>

using namespace std;

//default
//initializes it with one spot
template <class anyType>
ItemSet<anyType>::ItemSet() : itemArrSize(0)
{
  item = new anyType [itemArrSize];
}

//constructs dynamic array of size arrSize
template <class anyType>
ItemSet<anyType>::ItemSet(int arrSize) : itemArrSize(arrSize)
{
  item = new anyType [itemArrSize];
}


//working on
template <class anyType>
void ItemSet<anyType>::addToSet(anyType thing)
{

    itemArrSize++;
    item[itemArrSize - 1] = thing;

}

template <class anyType>
ItemSet<anyType>::~ItemSet()
{
  delete[] item;
}
