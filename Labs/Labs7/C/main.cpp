#include <iostream>

using namespace std;

//everything is in thousands
/*
const linIncrease = 5;
const percentIncrease = 1.1;
*/

int salary(int n);

int main()
{

  int pay = 0;
  cout << "Year 1: " << salary(pay) << endl;
  cout << "Year 2: " << salary(pay+1) << endl;
  cout << "Year 3: " << salary(pay+2) << endl;


  return 0;
}

int salary(int n)
{
  if(n == 0)
  {
    return 50;
  }
  else
  {
    return(salary(n-1) * 1.1 + 5);
  }
}
