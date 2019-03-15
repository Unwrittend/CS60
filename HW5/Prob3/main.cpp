#include <iostream>

using namespace std;

void towers (int num);

int main()
{
  cout << "note: the larger the number the smaller the rock" << endl;
  towers(5);


  return 0;
}

void towers(int num)
{
  if(num <= 0)
  {
    cout << "ERROR: NONPOSITIVE NUMBER" << endl;
  }
  else if(num == 1)
  {
    cout << "Move " << num << " to the third tower" << endl;
  }
  else
  {
    cout << "Move " << num - 1 << " stones from the occupied tower "
      "to the spare tower using the other towers when necessary until "
      "the spare tower is full save stone" << num << endl;
    cout << "Move " << num << " to the third tower" << endl;
    towers(num - 1);
  }
}
