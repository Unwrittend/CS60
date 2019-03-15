#include <iostream>

using namespace std;

class CounterType {
  public:
    CounterType(int countingNum) {  counter = countingNum; };
    void setCounter(int num) { counter = num;  };
    int addOne() {  return counter++;  };
    int subOne() {
      if(counter > 0)
        return counter--;
    }
    int getCounter() {  return counter;  };
    void output() { cout << counter << endl;  };
  private:
    int counter; //nonnegative whole number
};

int main() {
  CounterType c(5);
  c.output();
  c.addOne();
  c.output();
  c.subOne();
  c.output();
  c.setCounter(9);
  c.output();
  int m = c.getCounter();
  cout << m << endl;

  return 0;
}
