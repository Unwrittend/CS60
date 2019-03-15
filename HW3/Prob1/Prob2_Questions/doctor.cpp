#include <iostream>
#include "doctor.h"

using std::cout;
using std::endl;
using std::cin;

namespace SavitchEmployees
{
  Doctor::Doctor() : specialty("NO SPECIALTY"), officeFee(0), SalariedEmployee()
  {
    //purposefully empty
  }
  Doctor::Doctor(const string& spec, const double& fee, const string&  newName,
                  const string&  newNumber, double newWeeklyPay)
                  : specialty(spec), officeFee(fee), SalariedEmployee(newName, newNumber, newWeeklyPay)
  {
    //purposefully empty
  }

  //copy constructor
  Doctor::Doctor(const Doctor& otherDoc)
  {
    specialty = otherDoc.getSpecialty();
    officeFee = otherDoc.getOfficeFee();
    setSalary(otherDoc.getSalary());
    setSsn(otherDoc.getSsn());
    setName(otherDoc.getName());
  }

  //accessors
  string Doctor::getSpecialty() const
  {
    return specialty;
  }
  double Doctor::getOfficeFee() const
  {
    return officeFee;
  }

  Doctor& Doctor::operator =(const Doctor& otherDoc)  //why does this not work?
  {
    Doctor newDoctor(otherDoc);
    return *newDoctor;
  }
  //void Doctor::operator =(const Doctor& otherDoc)
}
