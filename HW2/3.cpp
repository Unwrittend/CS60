#include <iostream>
#include <new>

using namespace std;

class Student {
public:
    Student(); //default constructor
    Student(string studentName);
    Student(string studentName, int numberOfClasses);
    Student(const Student& otherStudent);
    ~Student();
    void output();  //prints
    void reset(); //resets classes
    void setClasses(); //also sets numClasses
    void operator =(const Student& otherStudent);  //copies classes
    string getName() const { return name; };
    int getNumClasses() const { return numClasses; };
    string * getClassListPtr() const { return classList; };
    string getClassList(int index) const { return classList[index]; };



private:
    string name;    //name of student
    int numClasses; //number of classes enrolled in
    string *classList; //stores names of the classes



};


int main() {
    //tests constructor, setClasses() and output() [setClasses() is in the cosntructor
    Student s1;
    //Student s1("Chris");
    s1.output();

    //tests reset()
    s1.reset();
    s1.output();

    //tests = operator
    Student s2;
    //Student s2("Dennis");
    s1 = s2;
    s1.output();

    //tests destructor automatically
    return 0;
}

 Student::Student(){
 cout << "Input student's name: ";
 cin >> name;
 cout << "Number of classes: ";
 cin >> numClasses;
 setClasses();
 }

Student::Student(string studentName){
 name = studentName;
 cout << "Number of classes: ";
 cin >> numClasses;
 setClasses();
 }

Student::Student(string studentName, int numberOfClasses) {

    name = studentName;
    cout << "contructing " << name << endl;
    numClasses = numberOfClasses;
    setClasses();
}

Student::Student(const Student& otherStudent) {
    cout << "copying" << endl;
    name = otherStudent.getName();
    numClasses = otherStudent.getNumClasses();
    classList = new string[numClasses];
    for(int index = 0; index < otherStudent.getNumClasses(); index++) {
        classList[index] = otherStudent.getClassList(index);
    }
}


Student::~Student(){  //work in progress
    cout << "Trying to delete " << name << endl;
    delete [] classList;

}

void Student::setClasses(){
    int index = 0;
    classList = new string[numClasses];

    while(index < numClasses){  //fills classList
        cout << "Input class: ";
        cin >> classList[index];
        index++;
    }
}


void Student::reset(){
    delete []classList;
    numClasses = 0;
    classList = new string[numClasses];

}

void Student::operator =(const Student& otherStudent){
    delete [] classList;
    numClasses = otherStudent.getNumClasses();
    classList = new string[numClasses];
    for(int index = 0; index < otherStudent.getNumClasses(); index++) {
        classList[index] = otherStudent.getClassList(index);
    }
}

void Student::output(){
    cout << "Student: " << name << endl;
    cout << "Classes:";
    for (int index = 0; index < numClasses; index++){
        cout << " ["  << classList[index] << "]";
    }
    cout << endl;
}
