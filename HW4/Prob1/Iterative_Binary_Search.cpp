//Program to demonstrate the recursive function for binary search.
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
const int ARRAY_SIZE = 10;

template <class numType>
int search(const numType a[], int first, int last,
                    numType key, bool& found, int& location);
//Precondition: a[first] through a[last] are sorted in increasing order.
//Postcondition: if key is not one of the values a[first] through a[last],
//then found == false; otherwise a[location] == key and found == true.


int main( )
{
    double a[ARRAY_SIZE];
    const double finalIndex = ARRAY_SIZE - 1;

    int i;
    for (i = 0; i < ARRAY_SIZE; i++)
        a[i] = 3.1*i;
    cout << "Array conatins:\n";
    for (i = 0; i < ARRAY_SIZE; i++)
        cout << a[i] << " ";
    cout << endl;

    double key;
    int location;
    bool found;
    cout << "Enter number to be located: ";
    cin >> key;
    search(a, 0.0, finalIndex, key, found, location);

    if (found)
        cout << key << " is in index location "
             << location << endl;
    else
        cout << key << " is not in the array." << endl;

    return 0;
}

template <class numType>
int search(const numType a[], int first, int last,
                          numType key, bool& found, int& location)
{
  int mid;
  mid = (first + last)/2;

  for (int index = 0; index < ARRAY_SIZE/(index + 1); index++)
  if (key == a[mid])
  {
    found = true;
    return mid;
  }
  else if (key < a[mid])
  {
    last = mid;
    mid = (first + last)/2;
  }
  else if (key > a[mid])
  {
    first = mid;
    mid = (first + last)/2;
  }
}
