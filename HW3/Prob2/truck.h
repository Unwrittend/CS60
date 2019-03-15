#ifndef TRUCK_H
#define TRUCK_H

#include "vehicle.h"
#include <string>

using namespace std;

class Truck : public Vehicle
{
public:
  Truck();
  Truck(const double& load, const int& towing, const string& theName, const int& cylinders, const string& man);
  Truck(const Truck& otherTruck);
  Truck& operator= (const Truck& otherTruck);
  double getLoadCapacity() const;
  int getTowingCapacity() const;
  void printSpecs() const;

  /*
  inhereted  protected
  Person owner;
  */

private:
  double loadCapacity;  //in tons
  int towingCapacity; //in pounds
};



#endif
