#include "dynamicArray.h"
#include <iostream>
#include <string>

using namespace std;


//linker error
//need to use inline functions
int main()
{
  DynamicArray<int> da1;
  da1.addEntry(0);
  da1.addEntry(7);
  da1.addEntry(4);
  cout << da1.getEntry(1) << endl;

  DynamicArray<int> da2(da1);
  cout << da2.getEntry(1) << endl;
  da2.deleteEntry(1);
  cout << da2.getEntry(1) << endl;
  return 0;
}
