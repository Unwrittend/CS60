#include "lbiguint.h"
#include <iostream>

using namespace std;

int main()
{
  lbiguint test;
  cout << test[1] << endl;


  lbiguint otherVar("3472");
  cout << otherVar[3] << endl;
  cout << otherVar[2] << endl;
  cout << otherVar[1] << endl;
  cout << otherVar[0] << endl;
  cout << otherVar << endl;

  return  0;
}
