//complete


#ifndef VEHICLE_H
#define VEHICLE_H

#include "person.h"

class Vehicle
{
public:
  Vehicle();
  Vehicle(const string& theName, const int& cylinders, const string& man);
  Vehicle(const Vehicle& otherVehicle);
  Vehicle& operator=(const Vehicle& otherVehicle);
  string getCarName() const;
  int getNumCylinders() const;
  Person getOwner() const;
  void setCarName(string name);
  void setNumCylinders(int cyl);

protected:
  Person owner;

private:
  string carName;
  int numCylinders;

};

#endif
