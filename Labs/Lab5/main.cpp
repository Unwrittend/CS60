#include <iostream>
#include "van.h"

using namespace std;

int main()
{
  Van kevinCar("Honda", "Sudana", 2030, 8.50, -1, 9);
  int spotssize = 4;
  bool parkingspots[spotssize];

  parkingspots[0]=true;
  parkingspots[1]=true;
  parkingspots[2]=false;
  parkingspots[3]=true;
/*
//populate array
  for(int i = 0; i < spotssize; i++)
  {
    parkingspots[i] = 0;
  }
  */

  kevinCar.park(parkingspots, spotssize);

  //print
  cout << kevinCar.year() << endl;
  cout << kevinCar.price() <<endl;
  cout << kevinCar.stall() << endl;
  cout << kevinCar.make() << endl;
  cout << kevinCar.model() << endl;
  cout << kevinCar.getSeats() << endl;

  return 0;
}
