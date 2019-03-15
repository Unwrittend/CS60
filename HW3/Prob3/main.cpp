#include "billing.h"
#include "patient.h"
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

using namespace SavitchEmployees;

int main()
{
  Doctor doc1 ("Coming up with ideas", 2345.12, "Smart guy", "25436543", 423.12);
  Patient pat1 ("Pikachu", doc1);
  Billing bill1 (doc1, pat1);
  bill1.printBill();


  Doctor doc2 ("SCU", 234.12, "Bucky Bronco", "432987897234", 35489.93);
  Patient pat2 ("Your child", doc2);
  Billing bill2 (doc2, pat2);
  bill2.printBill();
  return 0;
}
