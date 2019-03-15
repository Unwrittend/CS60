#include <iostream>
#include "node.h"

node * mergeLists(node * first, node * second);
void printAllNodes(node * head);

using namespace std;

int main()
{
  node * head_one;
  head_one = new node(5, nullptr);
  head_one = new node(3, head_one);
  head_one = new node(1, head_one);

  /*
  //populate
  for(int i = 2; i>0; i--)
  {
    head_one = new node(i, head_one);
  }
  */

  printAllNodes(head_one);

  node * head_two;
  head_two = new node(6, nullptr);
  head_two = new node(4, head_two);
  head_two = new node(2, head_two);

  /*
  //populate
  for(int i = 5; i>3; i--)
  {
    head_two = new node(i, head_two);
  }
  */
  printAllNodes(head_two);

//--------------
//program question
  node * merged = mergeLists(head_one, head_two);
  printAllNodes(merged);

  return 0;
}

node * mergeLists(node * first, node * second)
{
  node * newhead;

  //start: find head
  //find smallest value to start;
  //-----------------------------
  if(first->data() < second->data())
  {
    newhead = first;
    if(first->link() != nullptr)
    {
      first = first->link();
    }
  }
  else //second->data() > first->data()
  {
    newhead = second;
    if(second->link() != nullptr)
    {
      second = second->link();
    }
  }
  //-----------------------------

  //finds the smaller value in the two lists and moves it to a new list
  //-----------------------------
  bool firstDone = false;
  bool secondDone = false;
  node * newtail = newhead;

  while(!firstDone || !secondDone)
  {
    if((first->data() <= second->data() && !firstDone) || secondDone)
    {
      newtail->set_link(first);
      if(first->link() == nullptr)
      {
        firstDone = true;
      }
      else //(first->link() != nullptr)
      {
        first = first->link();
      }
      newtail = newtail->link();
    }
    else if ( (second->data() <= first->data() && !secondDone) || firstDone)
    {

      newtail->set_link(second);
      if(second->link() == nullptr)
      {
        secondDone = true;
      }
      else //(second->link() != nullptr)
      {
        second = second->link();
      }
      newtail = newtail->link();
    }
    else
    {
      cout << "ERROR" << endl;
    }
  }
  return newhead;
}

//prints backwards
void printAllNodes(node * head)
{
  bool done = false;
  node * temp = head;

  while(!done)
  {
    cout << temp->data() << " ";
    if(temp->link()==nullptr)
    {
      done = true;
    }
    else
    {
      temp = temp->link();
    }
  }
  cout << endl;
}
