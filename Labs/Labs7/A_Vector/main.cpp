//vector

#include<vector>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
  vector<string> served;

  ifstream infile;
  ofstream outfile ("output.txt");

  infile.open("Lab4.txt");
  while(!infile.eof())
  {
    string temp;
    getline(infile, temp);
    served.push_back(temp);
  }
  infile.close();

  //outfile.open();
  for(auto temp:served) {
    outfile << temp << endl;
  }
  outfile.close();

  return 0;
}
