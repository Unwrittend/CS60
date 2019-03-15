#include <iostream>
#include "dbiguint.h"
#include <cstdlib>
#include <string>
using namespace std;


/*
std::ostream& operator <<(std::ostream&, const dbiguint&);
dbiguint operator + (const dbiguint &, const dbiguint &);
dbiguint operator - (const dbiguint &, const dbiguint &);


// nonmember functions

bool operator < (const dbiguint &, const dbiguint &);
bool operator <= (const dbiguint &, const dbiguint &);
bool operator != (const dbiguint &, const dbiguint &);
bool operator == (const dbiguint &, const dbiguint &);
bool operator >= (const dbiguint &, const dbiguint &);
bool operator > (const dbiguint &, const dbiguint &);



//----------
int main(){
  return 0;
}
//----------
*/
dbiguint::dbiguint(){
  capacity = 0;
  numPtr= new unsigned short[capacity];

  for(std::size_t i=0; i<dbiguint::capacity; i++){
    numPtr[i]=0;
  }
}
dbiguint::dbiguint(const std::string &var){
  capacity = var.length();
  numPtr= new unsigned short[capacity];

  std::size_t counter=capacity-1;
  int count=1;
  for(std::size_t j=0; j<var.length(); j++){
    numPtr[j]=var[var.length()-count]-'0';
    counter--;
    count++;
  }


}

std::size_t dbiguint::size() const{
  return capacity;
}


unsigned short dbiguint::operator [](std::size_t pos) const{
  if (pos<capacity){
    size_t dig=numPtr[pos];
    return dig;
  }
  else {
    return 0;
  }
}



std::ostream& operator <<(std::ostream& output, const dbiguint& input){
  for (std::size_t i=input.size()-1;i>0; i--){
    output<<input[i];//<<" ";
  }
  output<<input[0];
  output<<std::endl;
  return output;
}



void dbiguint::reserve(std::size_t newcapacity_){
  if (newcapacity_>capacity){
    unsigned short* dummyPtr = new unsigned short[newcapacity_];

    //fill new pointer
    for(int index = 0; index < capacity; index++){
      dummyPtr[index]=numPtr[index];
    }
    for(int index = capacity; index < newcapacity_; index++){
      dummyPtr[index]=0;
    }

    delete[] numPtr;
    numPtr = dummyPtr;
    dummyPtr=nullptr;

    capacity = newcapacity_;

  }


}


void dbiguint::operator += (const dbiguint & b){
  if ((numPtr[capacity - 1]+b[capacity - 1]>=10) || (b.size() > capacity) ) {
    reserve(capacity+1);
  }
  for (size_t i =0; i< capacity;i++){
    if (numPtr[i]+b[i]>=10){
      numPtr[i+1]+=1;
      numPtr[i]=(numPtr[i]+b[i])%10;

    }
    else{
      numPtr[i]+=b[i];
    }
  }
}
/*
dbiguint operator + (const dbiguint &oper1, const dbiguint &oper2){
    dbiguint copy = oper1;

    copy+=oper2;
    return copy;
  }
*/
