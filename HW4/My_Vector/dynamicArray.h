#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

template <class anyType>
class DynamicArray
{
public:
  DynamicArray();
  DynamicArray(const DynamicArray &otherArray);
  DynamicArray& operator= (const DynamicArray &otherArray);
  int getSize() const {return size;}
  void addEntry(const anyType &objAdded);
  void deleteEntry(const anyType &deleteThis);
  anyType getEntry (const int &index) const;
  ~DynamicArray();
private:
  anyType *dynArray;
  int size;
  void search(int first, int last, anyType key,
    int& location);
};

//inline implementation for templates
#include "dynamicArray.inl" //implimentation

#endif //DYNAMICARRAY_H
