//implimentation of class Triangle
#include "triangle.h"

#include <iostream>
using namespace std;


void Triangle::erase()
{
  cout << "Erasing Triangle" << endl;
}

void Triangle::draw()
{
  cout << "Drawing Triangle" << endl;
}
void Triangle::center()
{
  erase();
  draw();
}
