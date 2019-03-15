#include<iostream>

using namespace std;

int factorial (int num);
int cnr (int n, int r);

int main()
{
  cout << factorial(6) << endl;
  cout << cnr(2,0) << endl;


  return 0;
}

int cnr (int n, int r)
{
  if(r < 0 || (r > n))
  {
    cout << "ERROR: NONPOSITIVE INPUT" << endl;
    exit(1);
  }
  else if(n == r || r == 0)
  {
    return 1;
  }
  else
  {
    return (cnr(n-1, r-1) + cnr(n-1, r));
  }
}


//num is the n!
int factorial (int num)
{
  if(num < 0)
  {
    cout << "ERROR: NEGATIVE INPUT" << endl;
    exit(1);
  }
  else if(num == 1 || num == 0)
  {
    return 1;
  }
  else
  {
    return (factorial(num - 1) * num);
  }
}
