#include <iostream>

using namespace std;

class GasPump {
  //goals - gasoline comes out, takes money, reads money
  public:
    GasPump (double pumped, double money, double fullCost)
            :gasPumped(pumped), rate(money), fullTank(fullCost) {}
    void display();
    void displayCost(); //output cost
    void displayCostPerGal();
    void reset();
    void pumpingGas();
  private:
    double gasPumped;
    double rate;
    double fullTank;
    bool dispensing = false;
    void stopPumping() {dispensing = false;}
    void startPumping() {dispensing = true;}
};

int main() {
  GasPump gp(0.25, 5.21, 0.5);
  gp.displayCostPerGal();
  gp.reset();
  gp.pumpingGas();

  return 0;
}

//FUNCTION CODE
//------------
/*GasPump::GasPump (double pumped, double money) {
  gasPumped = pumped
}*/

void GasPump::display() {
  cout << "Gas pumped: " << gasPumped << " gallons" << endl;
}

void GasPump::displayCost() {
  cout << "cost: $" << rate * gasPumped << endl;
}

void GasPump::displayCostPerGal() {
  cout << "cost per gal: $" << rate << endl;
}

void GasPump::reset() { //should not reset rate. The rate * fuel dispensed being zero equals zero
  gasPumped = 0;
}

void GasPump::pumpingGas() {
  startPumping();
  while(dispensing) {
    gasPumped += 0.01;
    display();
    displayCost();
    if (gasPumped >= fullTank) {
      stopPumping();
    }
  }
}
