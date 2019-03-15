#ifndef PICKUP_H
#define PICKUP_H
#include "automobile.h"
#include <string>
class Van : public Automobile
{
public:
    Van();
    Van(std::string imake, std::string imodel,
          int iyear, double iprice, int istall,
          int numSeats);
    int getSeats() {return seats;}
    bool park(bool lot[], int size);

private:
  int seats;
};




#endif // PICKUP_H
