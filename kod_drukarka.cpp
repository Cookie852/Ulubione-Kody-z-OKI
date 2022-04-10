/*
//Class implementing print server in C++
//Solution of task https://szkopul.edu.pl/problemset/problem/swy/site/
//Version 2.0 FULL
Consists
a. Program template
b. switch/case
c. Servicing d request (adding task)
d. Servicing g request (printer ready)
e. Servicing s request (stats)
f. corrected d / waiting time
-
Author: Makary Krupicz / Cookie852
*/
 
#include <iostream>
#include <vector>
#include <algorithm> 
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

 int size() {
	if (first == -1 ) 
        return 0;
	return last - first + 1; 
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
   int value = -5;
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
 mqueue printer;	
 char request;
 int number_of_requests, number_of_so_far_prints, total_print_time, average_print_time;
 int expected_time, time, start_time, print_time, i;
 int longest_print, longest_queue;

 cin >> number_of_requests; //9

 average_print_time = -1;
 total_print_time = number_of_so_far_prints = 0;
 longest_print = longest_queue = 0;
 for (i=1; i<=number_of_requests; ++i) {
    cin >> request; //s,  d,  g
    switch (request) {
       case 'd':
          cin >> time;
          printer.push(time);
          longest_queue = max(longest_queue, printer.size());
       	  if (average_print_time == -1)
       	     expected_time = -1;
		  else
		     expected_time = printer.size() * average_print_time;
       	  longest_queue = max ( longest_queue, printer.size()) ;
       	  cout << "Request accepted. You are number " << printer.size() << " in queue, ";
     	  cout << " expected time is " <<  expected_time << " seconds. \n";
		  break;	
       case 'g':
          cin >> time;   //15
          if ( printer.empty() ) {
             cout << "Printer is ready.\n";	
		     break;	
		  }
          start_time = printer.dequeue(); //7
          print_time = time-start_time; //15-7
          total_print_time += print_time; 
          ++number_of_so_far_prints;
          average_print_time = total_print_time / number_of_so_far_prints;
          longest_print = max (longest_print, print_time);   //max 3 i 8       
     	  cout << "Printer is ready. Print time: " << print_time << " seconds.\n";	
		  break;	
       case 's':
          cout << "Stats: Longest queue: " << longest_queue << ", longest waiting time: ";
          cout << longest_print << " seconds.\n";	
		  break;	
	}
 }


 return 0;
} 