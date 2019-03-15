//#include "dynamicArray.h"
#include <new>
#include <iostream>

template <class anyType>
DynamicArray<anyType>::DynamicArray() : size(0)
{
  dynArray = nullptr;
}

template <class anyType>
DynamicArray<anyType>::DynamicArray(const DynamicArray &otherArray)
{
  *this = otherArray;
}

template <class anyType>
DynamicArray<anyType>& DynamicArray<anyType>::operator =(const DynamicArray &otherArray)
{
  size = otherArray.getSize();
  dynArray = new anyType[size];
  for(int index = 0; index < size; index++)
  {
    dynArray[index] = otherArray.getEntry(index);
  }


  return *this;
}

template <class anyType>
void DynamicArray<anyType>::addEntry(const anyType &objAdded)
{

  //realloc
  anyType *temp;
  temp = new anyType[size];
  for (int index = 0; index < size; index++)
  {
    temp[index] = dynArray[index];
  }

  size++; //size increases by one
  delete[] dynArray;
  dynArray = new anyType[size];
  dynArray = temp;  //dynamicArrry point to temp

  dynArray[size - 1] = objAdded;
}

//acts as pushback for a vector
template <class anyType>
void DynamicArray<anyType>::deleteEntry(const anyType &deleteThis)
{
  if (size > 0)
  {
    int deleteIndex = 0;
    search(0, size, deleteThis, deleteIndex); //finds the index to delete


    //realloc to temp without deleteIndex
    anyType *temp;
    temp = new anyType[size-1];
    for (int index = 0; index < size; index++)
    {
      if(index >= deleteIndex)  //if found after index then skip deletedIndex and keep inserting
      {
        temp[index] = dynArray[index+1];
      }
      else
      {
        temp[index] = dynArray[index];
      }
    }

    //realloc back to dynArray
    size--;
    delete[] dynArray;
    dynArray = new anyType[size];
    dynArray = temp;  //dynamicArrry point to temp
  }
}

//get a certain index of an array
template <class anyType>
anyType DynamicArray<anyType>::getEntry (const int &index) const
{
  if (index < size)
  {
    return dynArray[index];
  }
  else
  {
    std::cout << "ERROR: INDEX OUT OF RANGE" << std::endl;
    return 0;
  }
}


//-------------------------
//private functions

//recursive binary search
template <class anyType>
void DynamicArray<anyType>::search(int first, int last,
                          anyType key, int& location)
{
    int mid;

    if (first > last)
    {
        return;
    }
    else
    {
        mid = (first + last)/2;

        if (key == dynArray[mid])
        {
            location = mid;
            return;
        }
        else if (key < dynArray[mid])
        {
            search(first, mid - 1, key, location);
        }
        else if (key > dynArray[mid])
        {
            search(mid + 1, last, key, location);
        }
    }
}

//-----------------
//destructor
template <class anyType>
DynamicArray<anyType>::~DynamicArray()
{
  delete[] dynArray;
}
