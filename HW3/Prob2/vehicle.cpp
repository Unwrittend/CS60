//complete

#include "vehicle.h"
#include <iostream>
#include <string>

using namespace std;

Vehicle::Vehicle() :carName("Unknown Car"), numCylinders(-1)
{
  //purposefully empty
}

Vehicle::Vehicle(const string& theName, const int& cylinders, const string& man)
            : carName(theName), numCylinders(cylinders), owner(man)
{
  //purposefully empty
}

Vehicle::Vehicle(const Vehicle& otherVehicle)
{
  *this = otherVehicle;
}

Vehicle& Vehicle::operator=(const Vehicle& otherVehicle)
{
  carName = otherVehicle.getCarName();
  numCylinders = otherVehicle.getNumCylinders();
  owner = otherVehicle.owner;
  return *this;
}

string Vehicle::getCarName() const
{
  return carName;
}

int Vehicle::getNumCylinders() const
{
  return numCylinders;
}

Person Vehicle::getOwner() const
{
  return owner;
}

void Vehicle::setCarName(string name)
{
  carName = name;
}

void Vehicle::setNumCylinders(int cyl)
{
  numCylinders = cyl;
}
