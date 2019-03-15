#include "pickup.h"

Pickup::Pickup() : haulingCap(-1), extendedCap(true), Automobile()
{
  //purposefully empty
}

Pickup::Pickup(std::string imake, std::string imodel,
      int iyear, double iprice, int istall,
      double haul, bool cap)
      : haulingCap(haul), extendedCap(cap), Automobile(imake, imodel, iyear, iprice, istall)
{
  //purposefully empty
}

//if empty parking spot return true
bool Pickup::park(bool lot[], int size){
    int spot=size;
    for(int i=1; i<size; i++){
        if(!lot[i] && !lot[i-1]) //if this lot is not 0 ie it is 1
                    //ie if there is not car in spot
            spot = i; //the spot the car is taking is i
    }
    if(spot>=size)
       return false;  //
    else{
        lot[spot] = true; //the parking spot is now full
        lot[spot-1] = true; //it has also filled the spot next to it
        set_stall(spot);
        return true;
    }
}
