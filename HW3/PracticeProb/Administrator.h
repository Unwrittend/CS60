#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include <string>
#include "salariedemployee.h"

namespace SavitchEmployees
{
  class Administrator : public SalariedEmployee
  {
  public:
    Administrator(const string& adminTitle, const string& adminAreaOfResp,
                    const string& adminSupervisor, const double& adminSalary,
                    const string& adminName, const string& adminNum);
    string getTitle() const;
    string getAreaOfResponsability() const;
    string getSupervisor() const;
    void setSupervisor(string newSupervisor);
    void input(); //what is this bit asking for?
    void print();
    void printCheck();

  /*protected:
    double salary;*/

  private:
    string title;
    string areaOfResponsability;
    string supervisor; //name of supervisor
  };
}

#endif
