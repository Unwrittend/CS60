#include <iostream>

using namespace std;

int fib (int n);

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
//found all numbers near instantly but the tiniest bit slower


  return 0;
}

//returns nth Fibonacci number
//1, 1, 2, 3, 5, 8, 13, 21, ...
int fib (int n)
{
  if(n <= 1 && n >= 0)
  {
    return 1;
  }
  else if(n < 0)
  {
    cout << "ERROR: CAN'T FIND NEGATIVES" << endl;
    exit(1);
  }
  else
  {
    return(fib(n-2) + fib(n-1));
  }
}
