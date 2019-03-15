#include <string>
#include <iostream>
#include "Administrator.h"

using std::string;
using std::cout;
using std::endl;

namespace SavitchEmployees
{
  Administrator::Administrator(const string& adminTitle, const string& adminAreaOfResp,
                  const string& adminSupervisor, const double& adminSalary,
                  const string& adminName, const string& adminNum)
              : title(adminTitle), areaOfResponsability(adminAreaOfResp),
                  supervisor(adminSupervisor), SalariedEmployee(adminName, adminNum, adminSalary)
  {
    //purposefully empty
  }

  //accessor functions
  string Administrator::getTitle() const {return title;}
  string Administrator::getAreaOfResponsability() const {return areaOfResponsability;}
  string Administrator::getSupervisor() const {return supervisor;}

  //manipulator functions
  void Administrator::setSupervisor(string newSupervisor) {
    supervisor = newSupervisor;
  }

  //other member functions
  //--------------------
  //Reads administrator's data from keyboard
  void Administrator::input(){

  }
  //--------------------
  //outputs administrator's data
  void Administrator::print(){
    cout << "Administrator's profile" << endl;
    cout << "Name: " << getName() << endl;
    cout << "Social Security Number: " << getSsn() << endl;
    cout << "Title: " << getTitle() << endl;
    cout << "Area of Responsibility: " << getAreaOfResponsability() << endl;
  }

  void Administrator::printCheck(){
    {
        setNetPay(salary);
        cout << "\n__________________________________________________\n";
        cout << "Pay to the order of " << getName( ) << endl;
        cout << "The sum of " << getSalary( ) << " Dollars\n";
        cout << "_________________________________________________\n";
        cout << "Check Stub NOT NEGOTIABLE \n";
        cout << "Employee Number: " << getSsn( ) << endl;
        cout << "Administrator. Administrator Pay: "  //changed this line to reflect the new class
             << this->salary << endl; //problem
        cout << "_________________________________________________\n";
    }
  }


}
