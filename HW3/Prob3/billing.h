#ifndef BILLING_H
#define BILLING_H

#include <string>
#include "patient.h"
#include "doctor.h"

using std::string;

using namespace SavitchEmployees;

class Billing
{
public:
  Billing();
  Billing(const Doctor& newDoc, const Patient& newPatient);
  Billing(const string& spec, const double& fee, const string&  newName,
                  const string&  newNumber, double newWeeklyPay,
                  const string& patientName, const double& cost);
  Billing(const Billing& otherBill);
  Billing& operator=(const Billing& otherBill);
  Doctor getDoc() const {return doc;}
  Patient getPatient() const {return pat;}
  double getAmountDue() const {return amountDue;}
  void printBill();

private:
  Doctor doc;
  Patient pat;
  double amountDue;
};

#endif
