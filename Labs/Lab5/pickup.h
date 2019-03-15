#ifndef PICKUP_H
#define PICKUP_H
#include "automobile.h"
#include <string>
class Pickup : public Automobile
{
public:
    Pickup();
    Pickup(std::string imake, std::string imodel,
          int iyear, double iprice, int istall,
          double haul, bool cap);
    double getHaulingCap() {return haulingCap;}
    bool getExtendedCap() {return extendedCap;}
    bool park(bool lot[], int size);

private:
  double haulingCap;
  bool extendedCap;
};




#endif // PICKUP_H
