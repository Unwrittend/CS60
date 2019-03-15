#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

class Polynomial
{
public:
  Polynomial();
  Polynomial(Polynomial const & other);
  Polynomial(int a);
  Polynomial(int a, int x);

  //accessors
  int getCoefficient() const {return coefficient;}
  int getExponent() const {return exponent;}

  //mutators
  void setCoefficient(int num){coefficient = num;}
  void setExponent(int num){exponent = num;}

  //operator overload
  Polynomial operator + (Polynomial rhpoly);  //good
  Polynomial operator - (Polynomial rhpoly);  //good
  Polynomial operator * (Polynomial rhpoly);  //good

  //functions
  int evaluation(int xvalue); //good
  void output();
  void input();

private:
  int coefficient;
  int exponent;
  bool samePower(int otherExponent) {return (exponent == otherExponent);}
};

#endif //POLYNOMIAL
