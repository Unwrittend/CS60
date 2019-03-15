#include <iostream>

using namespace std;

class Point {
  public:
    Point (double xcoord, double ycoord);
    void set(double xcoord, double ycoord); //mutator which sets the points x and y
    void move(double xmove, double ymove);  //translational movement
    void rotate90();
    void output();  //provides output
    const int getx() {  return x;  };
    const int gety() {  return y;  };
  private:
    double x;
    double y;
};

int main(){
  Point p(1,5);
  p.set(2,4);
  p.output();
  p.move(1,1);
  p.output();
  p.rotate90();
  p.output();
  cout << p.getx() << endl;
  cout << p.gety() << endl;

}

//FUNCTION CODE

Point::Point (double xcoord, double ycoord) {
  x = xcoord;
  y = ycoord;
}

void Point::set(double xcoord, double ycoord) {
  x = xcoord;
  y = ycoord;
}

void Point::output() {
  cout << "x:" << x << endl;
  cout << "y:" << y << endl;
}

void Point::move(double xmove, double ymove){
  x += xmove;
  y += ymove;
}

void Point::rotate90(){
  double dummy = x;
  x = y;
  y = -dummy;
}
