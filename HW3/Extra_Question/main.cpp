#include <iostream>
#include "Administrator.h" //header file

using std::string;
using std::cout;
using std::endl;

using namespace SavitchEmployees;

int main() {
  Administrator admin("Janitor Plus", "Cleaning Floors", "Tommy", 15.01, "Timmy", "337160990");
  admin.print();
  cout << endl;
  admin.printCheck();

  return 0;
}
