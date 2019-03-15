#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;

set<string> inputStr();
set<string> inputStr(string query);
double similarity(set<string> query, set<string> document);

int main()
{
  cout << "Input query: ";
  set<string> query = inputStr();
  cout << "Input document: ";
  set<string> documents = inputStr();

  cout << "Their similarity: " << endl;
  cout << similarity(query, documents) << endl;

/*
  //print testing
  for(auto index : query)
  {
    cout << index << endl;
  }
*/
  //string query = inputString();
  //string document = inputString();

  return 0;
}

//separates string into a set
set<string> inputStr()
{
  set<string> ret;
  string query = "I am here";
  getline(cin, query);

  int start_of_word = 0;
  int counter = 0;
  for(int index = 0; index < query.size(); index++)
  {
    bool uppercase = (query[index] >= 'A' && query[index] <= 'Z');
    bool lowercase = (query[index] >= 'a' && query[index] <= 'z');

    if(uppercase) //make uppercase letters lowercase
    {
      query[index] = tolower(query[index]);
    }

    if( !(uppercase) && !(lowercase) )
    {
      ret.insert(query.substr(start_of_word, counter));
      start_of_word = index+1;
      counter = 0;
    }
    //contains specific case for last index
    else if(index == query.size() - 1)
    {
      ret.insert(query.substr(start_of_word, counter+1));
      start_of_word = index+1;
      counter = 0;
    }
    else
    {
      counter++;
    }
  }

  return ret;
}

//testing purposes only
set<string> inputStr(string query)
{
  set<string> ret;
  int start_of_word = 0;
  int counter = 0;
  for(int index = 0; index < query.size(); index++)
  {
    bool uppercase = (query[index] >= 'A' && query[index] <= 'Z');
    bool lowercase = (query[index] >= 'a' && query[index] <= 'z');

    if(uppercase) //make uppercase letters lowercase
    {
      query[index] = tolower(query[index]);
    }

    if( !(uppercase) && !(lowercase) )
    {
      ret.insert(query.substr(start_of_word, counter));
      start_of_word = index+1;
      counter = 0;
    }
    //contains specific case for last index
    else if(index == query.size() - 1)
    {
      ret.insert(query.substr(start_of_word, counter+1));
      start_of_word = index+1;
      counter = 0;
    }
    else
    {
      counter++;
    }
  }

  return ret;
}

//find similiarity
double similarity(set<string> query, set<string> document)
{

/*
  double counter = 0;
  for(auto qindex : query)
  {
    for(auto dindex : document)
    {
      if(qindex == dindex)
      {
        counter += 1;
      }
    }
  }
*/

  set<string> intersect;
  insert_iterator< set<string> > it_intersect(intersect, intersect.begin());
  set_intersection(query.begin(), query.end(), document.begin(), document.end(), it_intersect);

  //equation
  double similar = intersect.size() / ( sqrt(query.size()) * sqrt(document.size()) ) * 1.0;
  return similar;
}
