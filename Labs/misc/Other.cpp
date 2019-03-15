#include <iostream>
#include <string>

using namespace std;

//DEFINED structrure
struct Time{//military time, no am/pm
  int hour;
  int minute;
};

struct Carpool{
  string names[5];
  int num_people;
  Time arrival;
};



Carpool combineCarpool (Carpool car1, Carpool car2);//declare the function.


int main() {

//VARIABLE DECLARATION
  int num1,num2,i;
Carpool car1;
Carpool car2;

//CODE
//get first car info
cout<<"Enter the information of the first car: "<<endl;
cout<<"Enter the number of people: "<<endl;
cin>>car1.num_people;
cin.get();


  for(i=0;i<car1.num_people;i++){
  cout<<"Enter the name of the passenger: "<<endl;
  getline(cin, car1.names[i]);
  }
  cout<<"Enter the arrival hour: "<<endl;
  cin>>car1.arrival.hour;

  cout<<"Enter the arrival minute: "<<endl;
  cin>>car1.arrival.minute;

//get second car info
cout<<"Enter the information of the second car: "<<endl;
cout<<"Enter the number of people: "<<endl;
cin>>car2.num_people;
cin.get();
for(i=0;i<car2.num_people;i++){
  cout<<"Enter the name of the passenger: "<<endl;
  getline(cin, car2.names[i]);
  }
  cout<<"Enter the arrival hour: "<<endl;
  cin>>car2.arrival.hour;

  cout<<"Enter the arrival minute: "<<endl;
  cin>>car2.arrival.minute;

//combine info
Carpool combined;
combined = combineCarpool(car1, car2);




//print info
  cout<<"The information for the new carpool: "<<endl;

  cout<<"The number of people: "<<combined.num_people<<endl;
  cout<<"Names of each passenger: "<<endl;

  for(int i=0;i<combined.num_people;i++){
    cout<<combined.names[i]<<endl;
  }

  cout<<"The arrival hour: "<<combined.arrival.hour<<endl;
  cout<<"The arrival minute: "<<combined.arrival.minute<<endl;








}

//--------------------
//FUNCTION CODE
//--------------------
Carpool combineCarpool (Carpool car1, Carpool car2){
  Carpool newpool;

  //find earlier time
  if(car1.arrival.hour<car2.arrival.hour)
     {
      newpool.arrival.hour=car1.arrival.hour;
      newpool.arrival.minute=car1.arrival.minute;
     }

  else if(car1.arrival.hour>car2.arrival.hour)
     {
      newpool.arrival.hour=car2.arrival.hour;
      newpool.arrival.minute=car2.arrival.minute;
     }
  else if(car1.arrival.hour==car2.arrival.hour)
  {
    newpool.arrival.hour=car1.arrival.hour;

    if(car1.arrival.minute<car2.arrival.minute)
    newpool.arrival.minute=car1.arrival.minute;

    else
    newpool.arrival.minute=car2.arrival.minute;
  }

  //get total names and the num_people variable
  if (car1.num_people + car2.num_people > 5) {
    cout << "Too Many People" << endl;
    newpool.num_people = 0;
  }
  else {
    int dummy_counter = 0;
    for(int index = 0; index < car1.num_people; index++) {
      newpool.names[index] = car1.names[index];
      dummy_counter++;
    }
    for(int index = 0; index < car2.num_people; index++) {
      newpool.names[index+dummy_counter] = car2.names[index];
    }
    newpool.num_people = car1.num_people + car2.num_people;

  }
  return newpool;

}
//--------------------

//--------------------
