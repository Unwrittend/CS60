#include "van.h"
#include <iostream>

using namespace std;

Van::Van() : Automobile(), seats(-1)
{
  //purposefully empty
}

Van::Van(std::string imake, std::string imodel,
      int iyear, double iprice, int istall,
      int numSeats)
      : Automobile(imake, imodel, iyear, iprice, istall), seats(numSeats)
{
  //purposefully empty
}

bool Van::park(bool lot[], int size){

  if(seats <= 7 && seats >= 1) //for smaller van
  {
    return Automobile::park(lot, size);
  }

  else if (seats > 7) //bigger van
  {
    int spot=size;
    for(int i=1; i<size; i++){
        if(!lot[i] && !lot[i-1])
            spot = i;
    }
    if(spot>=size)
       return false;
    else{
        lot[spot] = true;
        lot[spot-1] = true;
        set_stall(spot);
        return true;
    }
  }

  else  //error
  {
    cout << "ERROR: NEGATIVE SEAT VALUE" << endl;
    exit(1);
  }
}
