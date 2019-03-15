#include "polynomial.h"
#include <iostream>
#include <cmath>

using namespace std;


Polynomial::Polynomial()
{
  coefficient = -1;
  exponent = 0;
}

Polynomial::Polynomial(Polynomial const & other)
{
  coefficient = other.getCoefficient();
  exponent = other.getExponent();
}

Polynomial::Polynomial(int a)
{
  coefficient = a;
  exponent = 0;
}

Polynomial::Polynomial(int a, int x)
{
  coefficient = a;
  exponent = x;
}

Polynomial Polynomial::operator + (Polynomial rhpoly)
{
  if(!samePower(rhpoly.getExponent()))
  {
    cout << "ERROR: NOT SAME POWER" << endl;
    Polynomial added;
    return added;
  }
  else
  {
    int coeff = coefficient+rhpoly.getCoefficient();
    Polynomial added(coeff, this->getExponent());
    return added;
  }
}

Polynomial Polynomial::operator - (Polynomial rhpoly)
{
  if(!samePower(rhpoly.getExponent()))
  {
    cout << "ERROR: NOT SAME POWER" << endl;
    Polynomial subtract;
    return subtract;
  }
  else
  {
    int coeff = coefficient-rhpoly.getCoefficient();
    Polynomial subtract(coeff, this->getExponent());
    return subtract;
  }
}

Polynomial Polynomial::operator * (Polynomial rhpoly)
{
  if(!samePower(rhpoly.getExponent()))
  {
    cout << "ERROR: NOT SAME POWER" << endl;
    Polynomial multi;
    return multi;
  }
  else
  {
    int coeff = coefficient*rhpoly.getCoefficient();
    Polynomial multi(coeff, this->getExponent());
    return multi;
  }
}

int Polynomial::evaluation(int xvalue)
{
  return( coefficient*pow(xvalue, exponent) );
}

void Polynomial::output()
{
  cout << getCoefficient() << "x^" << getExponent();
}

void Polynomial::input()
{
  string term;
  cin >> term;
  if(term[0] == '-')  //is negative
  {
    coefficient = (term[1]-'0') * -1;
    exponent = term[3]-'0';
  }
  else
  {
    coefficient = (term[1]-'0');
    exponent = term[4]-'0';
  }
}
