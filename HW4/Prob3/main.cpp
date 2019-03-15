#include <iostream>
#include "itemSet.h"

using namespace std;

int main()
{
  //test by changing the values in addToSet()
  ItemSet<double> it;
  it.addToSet(6);
  it.addToSet(4);
  it.addToSet(5);
  it.addToSet(8);
  cout << it.getItem(1) << endl;


  return 0;
}
