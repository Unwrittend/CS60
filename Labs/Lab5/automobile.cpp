#include "automobile.h"
Automobile::Automobile(){
    make_ = "";
    model_="";
    year_=0;
    price_=0;
    stall_=-1;
}

Automobile::Automobile(std::string imake, std::string imodel, int iyear, double iprice, int istall){
    make_ = imake;
    model_=imodel;
    year_=iyear;
    price_=iprice;
    stall_=istall;
}

//if empty parking spot return true
bool Automobile::park(bool lot[], int size){
    int spot=size;
    for(int i=0; i<size; i++){
        if(!lot[i]) //if this lot is not 0 ie it is 1
                    //ie if there is not car in spot
            spot = i; //the spot the car is taking is i
    }
    if(spot>=size)
       return false;  //
    else{
        lot[spot] = true; //the parking spot is now full
        stall_ = spot;
        return true;
    }
}

double Automobile::discout(double off)
{
  price_ -= off;
  return price_;
}
