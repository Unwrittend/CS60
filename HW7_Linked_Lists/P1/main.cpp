#include <iostream>
#include "node.h"

using namespace std;

void reverse(node * & head);


int main()
{
  node * head;
  head = new node(0, nullptr);

  //populate
  int counter = 1;
  for(int i = 1; i<7; i++)
  {
    head = new node(i, head);
    counter++;
  }

  cout << "before reverse" << endl;
  node * temp = head;
  for(int i = 1; i<=counter; i++)
  {
    cout << temp->data() << endl;
    temp = temp->link();
  }

  reverse(head);
  cout << "after reverse" << endl;
  temp = head;
  for(int i = 1; i<=counter; i++)
  {
    cout << temp->data() << endl;
    temp = temp->link();
  }

  /*
  while(temp->link() != nullptr)
  {

  }
  */

}

void reverse(node * & head)
{
/*
  node * tail = head;
  bool bo = true;

  while(bo)
  {
    if(head->link()==nullptr)
    {
      bo=false;
    }
    else
    {
      //iterates through the linked list to the second to last node
      while(head->link()->link() != nullptr)
      {
        head = head->link();
      }
    }
    node *  temp = head->link();
    temp->set_link(head);
    temp->set_link(nullptr);

  }
  */

  //node * newHead = head;
  node * newHead = head; //second to last node
  node * tail = head; //second to last node
  bool bo = true;
  node *  afterTail = head->link(); //true tail
  node * trueTail = head;


  while(trueTail->link() != nullptr)
  {
    trueTail = trueTail->link();
  }

  while(bo)
  {
    tail = head;
    //if(head->link()==nullptr)

    if(head->link()==nullptr)
    {
      bo=false;
    }
    else
      {
      //iterates through the linked list to the second to last node
      while(tail->link()->link() != nullptr)
      {
        tail = tail->link();
      }
      //cout<<"hello"<< endl;
      afterTail = tail->link();
      afterTail->set_link(tail);
      tail->set_link(nullptr);
    }
  }
  head = trueTail;
}
