#include <iostream>

using namespace std;

int fib(int num);

int main()
{
  cout << fib(1) << endl;
  cout << fib(3) << endl;
  cout << fib(5) << endl;
  cout << fib(7) << endl;
  cout << fib(9) << endl;
  cout << fib(11) << endl;
  cout << fib(13) << endl;
  cout << fib(15) << endl;
//found all numbers neear instantly

  return 0;
}

int fib(int num)
{
  if (num == 1 || num == 0)
  {
    return 1;
  }
  else if(num < 0)
  {
    cout << "ERROR: CAN'T FIND NEGATIVES" << endl;
    exit(1);
  }
  else
  {
    int count = 1;
    int temp1 = 1;
    int temp2 = 1;

    for (int index = 1; index < num; index++)
    {
      temp2 = count;
      count += temp1;
      temp1 = temp2;
    }
    return count;
  }
}
