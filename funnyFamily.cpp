#include <iostream>
#include <string>
#include <time.h>

using namespace std;

class Pitterle
{
public:
  Pitterle() : numFamilyMembers(5), ownsPet(true), income(123456)
  {
    //purposefully nothing
  }
  bool activateOperationBaconUnderTree(bool yes) //cause children of Pitterle class to frantically complete a custom present for parents
  {
    if(yes)
    {
      //do an all nighter cleaning a messy garage
      cout << "You are sleepy" << endl;
      return true;
    }
    else
    {
      //give in to earthly desires and sleep you naught elf
      cout << "You are a horrible elf" << endl;
      return false;
    }
  }
  double calculateTaxes(double highTaxesPercent) //determine how much the IRS is coming after you
  {
    //complicated taxy things here
    return (income * highTaxesPercent);
  }
private:
  int numFamilyMembers;
  bool ownsPet;
  double income;
};



class Chris : public Pitterle
{
public:
  Chris() : Pitterle(), childOrder(1), gender('M'), motivated(false)
  {
    //purposefully nothing
  }
  bool activateWorkaholic() //make Chris work forever and he better ENJOY IT WITH PASSION! If conditions are not met return "Chris is sleeping to user"
  {
    if (motivated) {
      //complete code, place self in closet and write more code, then die after code has eaten me
      return true;
    }
    else{
      cout << "Chris is going to sleep now" << endl;
      return false;
    }
  }

  void sayWeirdSaying() //uses rand() to say a random stored phrases like "Cursing hamsters and guinea pigs!"
  {
    int saying = -1;
    srand(time(NULL));
    saying = rand() % 4;
    switch (saying) {
      case 0:
      cout << "Stupid fart" << endl;
      break;

      case 1:
      cout << "Cursing hamsters and guinea pigs!" << endl;
      break;

      case 2:
      cout << "AHUOWFSVDUOHW... I said something." << endl;
      break;

      case 3:
      cout << "1000 bottles of milk on the wall. 1000 bottles of milk..." << endl;
      break;
    }
  }

  void setMotivation(bool statusMotivated)
  {
    motivated = statusMotivated;
  }
private:
  int childOrder; //The x number child of the family
  char gender;
  bool motivated;
};

int main()
{
  Chris me;
  cout << "Family taxes: " << me.calculateTaxes(.01) << endl;
  me.activateOperationBaconUnderTree(true);
  me.activateWorkaholic();
  me.sayWeirdSaying();

  return 0;
}
