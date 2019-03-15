#include "billing.h"
#include <iostream>
#include <string>


using std::cout;
using std::endl;
using std::string;

using namespace SavitchEmployees;

Billing::Billing() : doc(), pat(), amountDue(-1)
{
  //purposefully empty
}

Billing::Billing(const Doctor& newDoc, const Patient& newPatient)
        :doc(newDoc), pat(newPatient), amountDue(newDoc.getOfficeFee())
{
  //purposefully empty
}

Billing::Billing(const string& spec, const double& fee, const string&  newName,
        const string&  newNumber, double newWeeklyPay, const string& patientName,
        const double& cost)
        : doc(spec, fee, newName, newNumber, newWeeklyPay),
        pat(patientName, spec, fee, newName, newNumber, newWeeklyPay), amountDue(cost)
{
  //purposefully empty
}

Billing::Billing(const Billing& otherBill)
{
  *this = otherBill;

}

Billing& Billing::operator=(const Billing& otherBill)
{
  doc = otherBill.getDoc();
  pat = otherBill.getPatient();
  amountDue = otherBill.getAmountDue();

  return *this;
}


void Billing::printBill()
{
  std::cout << "--------------------------------" << std::endl;
  std::cout << "Patient [" << pat.getName() << "] pays $" << getAmountDue() << std::endl;
  std::cout << "to Doctor [" << doc.getName() << "]" << std::endl;
  std::cout << "--------------------------------" << std::endl;

}
