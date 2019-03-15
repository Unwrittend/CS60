//implimentation of class Figure

#include "figure.h"

#include <iostream>
using namespace std;


void Figure::erase()
{
  cout << "Erasing figure" << endl;
}

void Figure::draw()
{
  cout << "Drawing figure" << endl;
}
void Figure::center()
{
  erase();
  draw();
}
