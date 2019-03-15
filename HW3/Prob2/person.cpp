//complete

#include "person.h"
#include <iostream>

using namespace std;

Person::Person()
{
  name = "No Name Given";
}

Person::Person(string theName)
{
  name = theName;
}

Person::Person(const Person& theObject)
{
  *this = theObject;
}

string Person::getName() const
{
  return name;
}

Person& Person::operator=(const Person& theObject)
{
  name = theObject.getName();
  return *this;
}

istream& operator >>(istream& inStream, Person& personObject)
{
  inStream >> personObject.name;
  return inStream;
}

ostream& operator <<(ostream& outStream, const Person& personObject)
{
  outStream << personObject.name;
  return outStream;
}
