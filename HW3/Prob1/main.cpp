#include <iostream>
#include "doctor.h" //header file

using std::string;
using std::cout;
using std::endl;

using namespace SavitchEmployees;

int main() {
  //cahnge constructors for differing results
  Doctor puppy("Professional 47", 0.47, "Agent 47", "47", 47.47);
  puppy.printCheck();
  cout << "Specialty: " << puppy.getSpecialty() << endl;
  cout << "Office visiting fee: " << puppy.getOfficeFee() << endl;
  Doctor worseDog;
  worseDog = puppy;
  worseDog.printCheck();
  cout << "Specialty: " << worseDog.getSpecialty() << endl;
  cout << "Office visiting fee: " << worseDog.getOfficeFee() << endl;
  return 0;
}
