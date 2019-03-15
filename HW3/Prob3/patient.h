//Complete

#ifndef PATIENT_H
#define PATIENT_H

#include <string>
#include "person.h"
#include "doctor.h"

using std::string;

using namespace SavitchEmployees;

class Patient : public Person
{
public:
  Patient();
  Patient(const string& patientName, const Doctor& doc);
  Patient(const string& patientName, const string& newSpeciality, const double& fee,
          const string& docName,const string&  newNumber, double newWeeklyPay);
  Patient(const Patient& otherPatient);
  Patient& operator=(const Patient& otherPatient);
  Doctor getDoctor() const;

private:
  Doctor primaryDoc;
};

#endif
