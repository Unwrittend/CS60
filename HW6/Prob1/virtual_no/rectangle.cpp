//implimentation of class Rectangle

#include "rectangle.h"

#include <iostream>
using namespace std;


void Rectangle::erase()
{
  cout << "Erasing Rectangle" << endl;
}

void Rectangle::draw()
{
  cout << "Drawing Rectangle" << endl;
}
void Rectangle::center()
{
  draw();
  erase();
}
