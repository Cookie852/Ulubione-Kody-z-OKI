#include <iostream>
#include <math.h>
using namespace std;

int main() {
int i;
int liczba;
int reszta;
int granica;

cin >> liczba;
//cout << liczba;

granica=pow(liczba,0.5)+1;

for (i=2; i<granica; ++i) {
	reszta = liczba %i; 
if (reszta ==0) { 
	cout << "NIE ";
//	cout << i;
	return 0;
	}
}
if (liczba ==1) {
	cout << "NIE";
	}else{
 cout << "TAK";
	}
	return 0;
}
