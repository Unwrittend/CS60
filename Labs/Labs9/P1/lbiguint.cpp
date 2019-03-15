#include "lbiguint.h"

#include <cassert>
#include <sstream>
#include <iostream>
#include <string>

 lbiguint::lbiguint(){
   capacity = 1;
   head = new node(0,nullptr);
   tail = head;

 }

 lbiguint::lbiguint (const std::string & s)
 {
   capacity = s.size();

   head = new node(s.at(0)-'0', nullptr);
   tail = head;
   for (int i = 1; i < capacity; i++)
   {
     int intTrans = s.at(i)-'0';
     head = new node(intTrans, head);
   }
 }


 lbiguint::~lbiguint()
 {
   node * one_before_tail;
   bool work = true;

   while(work)
   {
     one_before_tail = head;
     if(head->link() == nullptr)
     {
       delete head;
       work = false;
       //std::cout << "341" << std::endl;
     }
     else
     {
       while(one_before_tail->link()->link() != nullptr)  //find one before tail
       {
         one_before_tail = one_before_tail->link();
       }
       delete tail;
       one_before_tail->set_link(nullptr);
       tail = one_before_tail;
     }
   }
 }



 unsigned short lbiguint::operator [](std::size_t pos) const
 {
   node *search = head;
   if(head->link() == nullptr)
   {
     return 0;
   }

   for(int index = 0; index < pos; index++)
   {
     if(search->link() == nullptr)
     {
       std::cout << "ERROR: Not Found/beyond scope" << std::endl;
       return -1;
     }
     else
     {
       search = search->link();
     }
   }

   return search->data();

 }


/*
 int biguint::compare(const biguint & b) const{
     for(std::size_t i =CAPACITY-1; i>=0; --i){
         if(_data[i]>b._data[i])
             return 1;
         else if (_data[i]<b._data[i])
             return -1;

     }
     return 0;
 }



 void biguint::operator += (const biguint & b){
     int carry = 0;
     int next = 0;
     for(std::size_t i=0; i<CAPACITY; ++i){
         next = carry+_data[i]+b._data[i];
         _data[i]=next%10;
        carry=next/10;
     }
 }
 std::string biguint::toStdString() const
 {
     std::stringstream ss;
     ss << *this;
     return ss.str();
 }//We haven't talked about stringstreams; just ignore this, I was being lazy.

*/
 std::ostream & operator << (std::ostream & os, const lbiguint & b)
 {
   for (int i = b.size() - 1; i >= 0; --i)
   {
     os << b[i];
   }

     return os;
 }

/*
 std::istream & operator >> (std::istream & is, biguint & b)
 {
     std::string s;
     is >> s;
     b = biguint(s);
     return is;


 }

 bool operator <(const biguint& a, const biguint& b){
     return (a.compare(b)==-1);
 }

 bool operator <= (const biguint & b1, const biguint & b2)
 {
     return (b1.compare(b2) <= 0);
 }

 bool operator == (const biguint & b1, const biguint & b2)
 {
     return (b1.compare(b2) == 0);
 }

 bool operator != (const biguint & b1, const biguint & b2)
 {
     return (b1.compare(b2) != 0);
 }
*/
//You do > and >=
