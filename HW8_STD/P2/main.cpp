#include <vector>
#include <map>
#include <iostream>
#include <string>

using namespace std;

struct StudentInfo
{
  string name;
  int grade;
};

vector<StudentInfo> buildStudentList();
vector<StudentInfo> sort(vector<StudentInfo> list);
int maxGrade(vector<StudentInfo> list);
int minGrade(vector<StudentInfo> list);
int average(vector<StudentInfo> list);



int main()
{
  vector<StudentInfo> students = buildStudentList();
  students = sort(students);

  //print
  for(auto i : students)
  {
    cout << "Name:" << i.name << " - Grade:" << i.grade << endl;
  }

  cout << "Max grade: " << maxGrade(students) << endl;
  cout << "Lowest grade: " << minGrade(students) << endl;
  cout << "Average grade: " << average(students) << endl;

  return 0;
}

vector<StudentInfo> buildStudentList()
{
  vector<StudentInfo> ret;


  //user input populate
  bool done = false;
  do {
    StudentInfo temp;

    cout << "Enter student name: ";
    getline(cin, temp.name);

    cout << "Enter their grade: ";
    cin >> temp.grade;
    cin.get();

    ret.push_back(temp);

    cout << "Type 'n' if there are no more students otherwise press anything to continue: ";
    char c = 'a'; //a is arbitary
    cin >> c;
    cin.get();
    if(c == 'n')
    {
      done = true;
    }

  } while(!done);
  

/*
  //populate for testing
  int check = 0;
  for(int index = 5; index > check; index--)
  {
    StudentInfo si;
    si.name = 'a' + index;
    si.grade = 100 - 10*index;
    ret.push_back(si);
  }
*/

  return ret;
}

//converts the vector to a map to sort the list
vector<StudentInfo> sort(vector<StudentInfo> list)
{
  vector<StudentInfo> ret;
  map<string, int> infoMap; //map version of the string
  for(int index = 0; index < list.capacity(); index++)  //sorts alphabetically
  {
    infoMap.insert( pair<string, int>(list[index].name, list[index].grade) );
  }
  for(auto index : infoMap)
  {
    StudentInfo si;
    si.name = index.first;
    si.grade = index.second;
    ret.push_back(si);
  }
  return ret;
}

int maxGrade(vector<StudentInfo> list)
{
  int max = 0;
  for(int index = 0; index < list.capacity(); index++)  //sorts alphabetically
  {
    if(list[index].grade > max)
    {
      max = list[index].grade;
    }
  }
  return max;
}

int minGrade(vector<StudentInfo> list)
{
  int min = 100;
  for(int index = 0; index < list.capacity(); index++)  //sorts alphabetically
  {
    if(list[index].grade < min)
    {
      min = list[index].grade;
    }
  }
  return min;
}

int average(vector<StudentInfo> list)
{
  int total = 0;
  int numInList = list.capacity();
  for(int index = 0; index < numInList; index++)  //sorts alphabetically
  {
    total += list[index].grade;
  }
  return total/numInList;
}
