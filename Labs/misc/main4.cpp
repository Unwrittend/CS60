#include <iostream>
#include "dbiguint.h"
using namespace std;


int main(){
  dbiguint test1("1234"); //test different numbers by inputing string values of numbers here
  cout<<test1[2];
  cout<<endl;

  test1.reserve(3);
  for(int index = 0; index < test1.size(); index++){
    cout << test1[index];
  }
  cout<<endl;

  dbiguint test2("9234"); //test different numbers by inputing string values of numbers here
  test1 += test2;
  for(int index = 0; index < test1.size(); index++){
    cout << test1[index];
  }
  cout << endl;

  return 0;
}
