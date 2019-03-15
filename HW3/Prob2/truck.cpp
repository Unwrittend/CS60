#include "truck.h"
#include <iostream>

using namespace std;

Truck::Truck() : loadCapacity(-1), towingCapacity(-1), Vehicle()
{
  //purposefully empty
}

Truck::Truck(const double& load, const int& towing, const string& theName,
      const int& cylinders, const string& man)
      :loadCapacity(load), towingCapacity(towing), Vehicle(theName, cylinders, man)
{
  //purposefully empty
}

//copy constructor
Truck::Truck(const Truck& otherTruck)
{
  *this = otherTruck;
}

Truck& Truck::operator= (const Truck& otherTruck)
{
  loadCapacity = otherTruck.getLoadCapacity();
  towingCapacity = otherTruck.getTowingCapacity();
  owner = otherTruck.getOwner();
  setCarName(otherTruck.getCarName());
  setNumCylinders(otherTruck.getNumCylinders());
  return *this;
}

//in tons
double Truck::getLoadCapacity() const
{
  return loadCapacity;
}

//in pounds
int Truck::getTowingCapacity() const
{
  return towingCapacity;
}

void Truck::printSpecs() const
{
  cout << "------------------------------" << endl;
  cout << "Owner: " << getOwner() << endl;
  cout << "name: " << getCarName() << endl;
  cout << "Cylinder Count: " << getNumCylinders() << endl;
  cout << "Load Capacity: " << getLoadCapacity() << endl;
  cout << "Towing Capacity: " << getTowingCapacity() << endl;
}
