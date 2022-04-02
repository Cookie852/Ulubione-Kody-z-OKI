/*
//class implementing queue in C++
//the same functionality as STL (Standard Template Library ) class queue in C++ 
//with usage example
//Version 1.5
Consists
a. Program template
b. defintion of class mqueue 
c. Constructor
d. empty() method
e. push() method
f. dequeue() method
Author: Daniel Olkowski / Olimpijskie Kolo Informatyczne
 */
 
#include <iostream>
#include <vector>
using namespace std;

class mqueue {
public:
 mqueue() { 
    first = last = -1;
 } 
 bool empty() {
    if (first == -1 ) 
        return true; 
    return false; 
 }	
 void push(int value) {
    if (  empty() == true ) {
       elements.push_back(value);
	   first = last = 0;
	   return;
    }
    elements.push_back(value);
    ++last;
 }	
 int dequeue() {
   int value;
   if ( empty() ) {
      return value;
   }
   if ( first == last) {
      value = elements[first];
      first = last = -1;
	   elements.clear();
	  return value;
   }
   value = elements[first];
   ++first;
   return value;
 }
private:
 vector<int> elements;
 int first, last;
};	

int main() {
 mqueue	payments;
 int value;
 
 cout << "empty?: " << payments.empty() << "\n";
 payments.push(5);
 payments.push(-3);
 payments.push(8);
 cout << "empty?: " << payments.empty() << "\n";
 cout << "serviced: " << payments.dequeue() << "\n";
 cout << "serviced: " << payments.dequeue() << "\n";
 payments.push(11);
 cout << "serviced: " << payments.dequeue() << "\n";
 cout << "serviced: " << payments.dequeue() << "\n";
 cout << "empty?: " << payments.empty() << "\n";
 return 0;
}