#include "node.h"

#include <iostream>
using namespace std;

node::node(const value_type & init_data, node * init_link)
{

    _data = init_data;
    _link = init_link;
}

node::value_type node::data() const
{
    return _data;
}

node * node::link()
{
    return _link;
}

void node::set_data(const value_type & new_data)
{
    _data = new_data;
}

void node::set_link(node * new_link)
{
    _link = new_link;
}

/*
void printAllNodes()
{
  bool done = false;
  node * temp = this;

  while(!done)
  {
    cout << temp->data() << endl;
    if(temp->link()==nullptr)
    {
      done = true;
    }
    else
    {
      temp = temp->link();
    }
  }
}
*/








/*
 *
const node * node::link() const
{
    return _link;
}
*/
