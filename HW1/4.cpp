#include <iostream>
#include <string>

using namespace std;

class Month {
  public:
    Month(string monthName);
    Month(int monthInt);
    Month() :monthNum(1) {}
    int getMonthNum();
    string getMonthName();
    void outputName();
    Month nextMonth();

  private:
    int monthNum;
};

int main() {
  Month m1 ("Feb");
  cout << m1.getMonthNum() << endl;
  cout << m1.getMonthName() << endl;
  Month m2 (4);
  cout << m2.getMonthNum() << endl;
  cout << m2.getMonthName() << endl;
  Month m3;
  cout << m3.getMonthNum() << endl;
  m3.outputName();
  m3 = m2.nextMonth();
  cout << m3.getMonthNum() << endl;

  return 0;
}

Month::Month(string monthName){ //switch can not take in string
  if(monthName == "Jan")
    monthNum = 1;
  else if(monthName == "Feb")
    monthNum = 2;
  else if(monthName == "Mar")
    monthNum = 3;
  else if(monthName == "Apr")
    monthNum = 4;
  else if(monthName == "May")
    monthNum = 5;
  else if(monthName == "Jun")
    monthNum = 6;
  else if(monthName == "Jul")
    monthNum = 7;
  else if(monthName == "Aug")
    monthNum = 8;
  else if(monthName == "Sep")
    monthNum = 9;
  else if(monthName == "Oct")
    monthNum = 10;
  else if(monthName == "Nov")
    monthNum = 11;
  else if(monthName == "Dec")
    monthNum = 12;
  else
    monthNum = -1;
  /*switch (monthName) {
    case "Jan":
      monthNum = 1;
      break;
    case "Feb":
      monthNum = 2;
      break;
    case "Mar":
      monthNum = 3;
      break;
    case "Apr":
      monthNum = 4;
      break;
    case "May":
      monthNum = 5;
      break;
    case "Jun":
      monthNum = 6;
      break;
    case "Jul":
      monthNum = 7;
      break;
    case "Aug":
      monthNum = 8;
      break;
    case "Sep":
      monthNum = 9;
      break;
    case "Oct":
      monthNum = 10;
      break;
    case "Nov":
      monthNum = 11;
      break;
    case "Dec":
      monthNum = 12;
      break;
    default:
      monthNum = -1;
      break;
  }*/
}
Month::Month(int monthInt) {
  if(monthInt <= 12 && monthInt >= 1) {
    monthNum = monthInt;
  }
  else {
    monthNum = -1;
  }
}
string Month::getMonthName() {
  switch (monthNum) {
    case 1:
      return "Jan";
      break;
    case 2:
      return "Feb";
      break;
    case 3:
      return "Mar";
      break;
    case 4:
      return "Apr";
      break;
    case 5:
      return "May";
      break;
    case 6:
      return "Jun";
      break;
    case 7:
      return "Jul";
      break;
    case 8:
      return "Aug";
      break;
    case 9:
      return "Sep";
      break;
    case 10:
      return "Oct";
      break;
    case 11:
      return "Nov";
      break;
    case 12:
      return "Dec";
      break;
    default:
      monthNum = -1;
      return "-1";
      break;
  }
}
int Month::getMonthNum() {return monthNum;}
void Month::outputName(){
  switch (monthNum) {
    case 1:
      cout << "Jan" << endl;
      break;
    case 2:
      cout << "Feb" << endl;
      break;
    case 3:
      cout << "Mar" << endl;
      break;
    case 4:
      cout << "Apr" << endl;
      break;
    case 5:
      cout << "May" << endl;
      break;
    case 6:
      cout << "Jun" << endl;
      break;
    case 7:
      cout << "Jul" << endl;
      break;
    case 8:
      cout << "Aug" << endl;
      break;
    case 9:
      cout << "Sep" << endl;
      break;
    case 10:
      cout << "Oct" << endl;
      break;
    case 11:
      cout << "Nov" << endl;
      break;
    case 12:
      cout << "Dec" << endl;
      break;
    default:
      monthNum = -1;
      break;
    }
}
Month Month::nextMonth(){
  Month nextMonth;
  nextMonth.monthNum = monthNum + 1;
  return nextMonth;
}
