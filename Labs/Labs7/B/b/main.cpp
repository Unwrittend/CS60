//unordered_set

#include<unordered_set>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
  unordered_set<string> served;

  ifstream infile;
  ofstream outfile ("output.txt");

  infile.open("Lab4.txt");
  while(!infile.eof())
  {
    string temp;
    getline(infile, temp);
    served.insert(temp);
  }
  infile.close();


  outfile << served.size() << endl;
  outfile.close();

  return 0;
}
