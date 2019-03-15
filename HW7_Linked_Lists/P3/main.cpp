#include "node.h"
#include "polynomial.h"
#include <iostream>
#include <string>

using namespace std;

node * input();
int negative(int coef, string equation, int index);
string removeNewline(string s);


int main()
{

  Polynomial p1(5,1);
  Polynomial p2(10,1);
  p1 = p1 + p2;
  cout << "Testing addition operator" << endl;
  p1.output();
  cout << endl;

  node * first;
  first = input();

/*
  //testing
  Polynomial p1(0,0);
  //node * test_head = new node(p1, nullptr);
  node * test_head;
  for(int i =0; i <3; i++)
  {
    Polynomial p(i,i);
    test_head = new node(p, test_head);
  }
*/





bool done = false;
node * tempNode = first;
while(!done)
{
  if(tempNode->link() == nullptr)
  {
    done = true;
  }
  Polynomial temp = tempNode->data();
  temp.output();

  if(!done)
  {
    cout << " + ";
  }
  tempNode = tempNode->link();
}
cout << endl;



  return 0;
}

//assumes correct user input
node * input()
{
  node * head;
  string equation = "3x^4 + 7x^2 + 5";  //15
  getline(cin, equation);
  equation = removeNewline(equation);


  int index = equation.size()-1;
  //cout << index << endl;
  bool working = true;
  while(working)
  {
    if(index <= 0)
    {
      working = false;
    }

    if(equation.size() <= 2)  //case: only x^0 polynomial
    {
      //cout << "hello" << endl;
      //cout << index << endl;

      int coef = equation[index] - '0';
      if(index - 1 >= 0)  //extra percausion
      {
        if(equation[index-1] == '-')
        {
          coef = coef * -1;
        }
      }
      Polynomial polyData(coef);
      /*
      polyData.output();
      cout << endl;
      */
      head = new node(polyData, 0);
      working = false;
    }

    //for x^0
    else if(index >= 0) //not exits scope
    {

      if(equation[index+1] == 'x') //and has x
      {
        //cout << "hi" << endl;

        int coef = equation[index] - '0';
        coef = negative(coef, equation ,index);
        int ex = equation[index+3]-'0';
        Polynomial polyData(coef, ex);
        /*
        polyData.output();
        cout << endl;
        */
        head = new node(polyData, head);
        index -= 7;
      }
      else if(equation[index-1] == ' ') //case: is x^0
      {
        int coef = equation[index] - '0';
        coef = negative(coef, equation ,index);
        Polynomial polyData(coef);

        polyData.output();  //testing
        cout << endl;

        head = new node(polyData, nullptr);
        index -= 7;
      }

      else
      {
        cout << "ERROR: INPUT INCORRECT" << endl;
        exit(1);
      }


/*
      //covers 0x^n variables
      while(equation[index+3]-'0' != head->data().getExponent()+1)
      {
        int ex = head->data().getExponent();
        Polynomial temp(0, ex);
        head = new node(temp, head);
      }
      */

    }

  }
  return head;
}

//helper function:input
//if there is a subtraction then
int negative(int coef, string equation, int index)
{
  if(equation[index-2] == '-')
  {
    coef = coef * -1;
  }
  return coef;
}

//removes /n and /r at the end of a string
string removeNewline(string s)
{
  int size = s.size();
  string ret;
  int counter = 0;
  for(int index = size - 1; index > size - 3; index--)  //only have to check last 2 indexes
  {
    if(s[index] == '\n' || s[index] == '\r')
    {
      counter++;
    }
  }
  ret = s.substr(0, size - counter);
  return ret;
}
