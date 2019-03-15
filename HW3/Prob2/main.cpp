#include <iostream>
#include "truck.h"

using namespace std;

int main()
{
  Truck tomyTruck (1, 3, "Pombur", 23, "Joey Finn");
  tomyTruck.printSpecs();
  Truck timyTruck;
  timyTruck = tomyTruck;
  timyTruck.printSpecs();
  return 0;
}
