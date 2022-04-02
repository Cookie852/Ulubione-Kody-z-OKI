#include <iostream>
using namespace std;

int main() {
long long int i;
long long int liczba;
long long int reszta;

cin >> liczba;

for (i=2; i<liczba/2; ++i) {
	reszta = liczba %i; 
if (reszta ==0) { 
	cout << "NIE";
	return 0;
	}else{ 
}
}
if (liczba ==1) {
	cout << "NIE";
	}else{
 cout << "TAK";
	}
	return 0;
}