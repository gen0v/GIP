#include <iostream>

using namespace std;

int main() {

	double seitenlaenge = 0;


	cout << "Bitte geben Sie die Seitenlaenge ein (in cm): ? ";
	cin >> seitenlaenge;
	cout << "Der Umfang des Quadrats betraegt (in cm): " << seitenlaenge * 4 << endl;
	cout << "Die Flaeche des Quadrats betraegt (in cm*cm): " << seitenlaenge * seitenlaenge << endl;

	system("PAUSE");

}