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
    /*pair<string, int> temp;
    getline(infile, temp.first);
    temp.second++;*/

    string temp;
    getline(infile, temp);
    served[temp] += 1;
  }
  infile.close();

  //outfile.open();
  for(auto temp:served) {
    outfile << temp.first << ": " << temp.second << endl;
  }
  outfile.close();

  return 0;
}
