#ifndef DOCTOR_H
#define DOCTOR_H

#include "salariedemployee.h"

using std::string;
#include <string>

namespace SavitchEmployees
{
  class Doctor : public SalariedEmployee
  {
  public:
    //constructors
    Doctor();
    Doctor(const string& spec, const double& fee, const string&  newName,
                    const string&  newNumber, double newWeeklyPay);
    Doctor(const Doctor& otherDoc);

    Doctor& operator=(const Doctor& otherDoc);

    //accessor functions
    string getSpecialty() const;
    double getOfficeFee() const;

  private:
    string specialty;
    double officeFee;

  };

  //nonmember functions
  //Doctor& operator=(const Doctor& otherDoc);
}

#endif DOCTOR_H
