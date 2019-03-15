//recursive Fibonacci with arrays

#include <iostream>

using namespace std;

int fib (int n[], int i);

int main()
{
    int size = 9; //modify this to change the answer
    int arr[size];

    cout << fib(arr, size) << endl;

    //found all numbers near instantly but the tiniest bit slower


    return 0;
}

//returns nth Fibonacci number
//1, 1, 2, 3, 5, 8, 13, 21, ...
int fib (int n[], int i)
{

    if(i <= 1 && i >= 0)
    {
        n[i] = 1;
        return 1;
    }
    else if(i < 0)
    {
        cout << "ERROR: CAN'T FIND NEGATIVES" << endl;
        exit(1);
    }
    else
    {
        n[i] = fib(n, i - 1);
        int ret = n[i] + n[i-1];
        return ret;
    }
}
