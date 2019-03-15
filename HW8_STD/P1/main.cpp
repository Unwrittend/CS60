#include "iostream"
#include "vector"

using namespace std;

struct prime
{
  int num;
  bool used;
};

vector<int> allPrimes(int lastNum);

int main()
{
  int maxNum = 30;
  vector<int> primNums = allPrimes(maxNum);

  //print
  for(auto i : primNums)
  {
    cout << i << " ";
  }
  cout << endl;

  return 0;
}

vector<int> allPrimes(int lastNum)
{
  vector<int> ret;

  //if case for 0 or 1
  //returns empty vector
  if(lastNum == 0 || lastNum == 1)
  {
    return ret;
  }

  //populate
  int lastIndex = lastNum - 2;
  prime arrPrime[lastIndex]; //not include 0 or 1
  for(int index = 0; index < lastIndex; index++)
  {
    arrPrime[index].num = index + 2;
    arrPrime[index].used = false;
  }

  //find all prime
  for(int index = 0; index < lastIndex/2; index++)
  {
    if(arrPrime[index].used == false)
    {
      for(int jindex = index+1; jindex < lastIndex; jindex++) //iterate through array to find multiples
      {
        //should I add if for arrPrime[jindex].used == true? to stop
        if(arrPrime[jindex].num % arrPrime[index].num == 0)
        {
          arrPrime[jindex].used = true;
        }
      }
    }
  }
  for(int index = 0; index < lastIndex; index++)
  {
    if(arrPrime[index].used == false)
    {
      ret.push_back(arrPrime[index].num);
    }
  }


  return ret;
}
