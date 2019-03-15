//map

#include<map>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;


int main()
{
  map<string, int> served;



  ifstream infile;
  ofstream outfile ("output.txt");

  infile.open("Lab4.txt");
  while(!infile.eof())
  {
    string temp;
    getline(infile, temp);
    served[temp] += 1;
  }
  infile.close();

  int count = 0;
  for(auto temp:served) {
    count += temp.second;
  }
/*  cout << count << endl;
  cout << served.size() << endl; */
  double average = count * 1.0 / served.size() ;
  outfile << average << endl;
  outfile.close();

  return 0;
}
