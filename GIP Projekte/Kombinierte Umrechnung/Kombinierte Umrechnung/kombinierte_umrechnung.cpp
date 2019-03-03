#include <iostream>

using namespace std;

int main() {
	double eingabe;
	int auswahl;
	cout << "Ihre Eingabe: ? ";
	cin >> eingabe;
	cout << "Ihre Auswahl der Umwandlung:\n";
	cout << " 1 - Celsius in Fahrenheit\n";
	cout << " 2 - Meter in Fuss\n";
	cout << " 3 - Euro in US Dollar\n";
	cin >> auswahl;
	/*
	Berechnung wie folgt:
	1/auswahl => 1 wenn auswahl groeser gleich 1 da Int alles nach Komma weglaesst
	(auswahl % 2 - 1) + (-1) => 1 wegen modula kann man 1 und 3 wegmachen da es immer nur 0 1 0 1 gibt, man muss es nur umkehren
	auswahl/3 => 1 wenn auswahl groeser gleich 3 da Int alles nach Komma wegleasst
	*/
	cout << "Das Ergebnis lautet: "<<((eingabe * 1.8 + 32) * (1 / auswahl)) + ((eingabe * 3.2808) * (((auswahl % 2) - 1)) * (-1)) + ((eingabe * 1.2957) * (auswahl/3)) << "\n\n";

	system("PAUSE");
}