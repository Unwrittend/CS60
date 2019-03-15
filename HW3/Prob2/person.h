//complete

#ifndef PERSON_H
#define PERSON_H

#include <string>

using namespace std;

class Person
{
public:
  Person();
  Person(string theName);
  Person(const Person& theObject);
  string getName() const;
  Person& operator= (const Person& rtSide);
  friend istream& operator >> (istream& inStream, Person& personObject);
  friend ostream& operator << (ostream& outStream, const Person& personObject);

private:
  string name;
};

#endif
