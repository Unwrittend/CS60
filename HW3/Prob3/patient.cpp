//Complete

#include "patient.h"
#include <string>

using std::string;

using namespace SavitchEmployees;

//default constructor setting values to dummy values
Patient::Patient() : Person(), primaryDoc()
{
  //purposefully empty
}

Patient::Patient(const string& patientName, const Doctor& doc)
          : Person(patientName), primaryDoc(doc)
{
  //purposefully empty
}

//defined constructor for all elements
Patient::Patient(const string& patientName, const string& newSpeciality,
        const double& fee, const string& docName,
        const string&  newNumber, double newWeeklyPay)
        : Person(patientName),
          primaryDoc(newSpeciality, fee, docName, newNumber, newWeeklyPay)
{
  //purposefully empty
}

Patient::Patient(const Patient& otherPatient)
{
  *this = otherPatient;
}

Patient& Patient::operator=(const Patient& otherPatient)
{
  setName(otherPatient.getName());
  primaryDoc = otherPatient.getDoctor();
  return *this;
}

Doctor Patient::getDoctor() const
{
  return primaryDoc;
}
