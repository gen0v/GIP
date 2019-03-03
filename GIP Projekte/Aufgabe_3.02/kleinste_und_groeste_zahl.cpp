#include <iostream>

using namespace std;

int main() {

	int zahl_kleinste = 0;
	int zahl_groeste = 0;
	int position_kleinste = 0;
	int position_groeste = 1;
	int zahl = 0;


	cout << "Bitte geben Sie die 1. Zahl ein: ";
	cin >> zahl;
	
	zahl_kleinste = zahl;
	position_kleinste = 1;

	cout << "Bitte geben Sie die 2. Zahl ein: ";
	cin >> zahl;
	if (zahl < zahl_kleinste) {
		zahl_groeste = zahl_kleinste;
		position_kleinste = position_kleinste;
		zahl_kleinste = zahl;
		position_kleinste = 2;
	}
	else if(zahl > zahl_kleinste){
		zahl_groeste = zahl;
		position_groeste = 2;
	}
	else if (zahl == zahl_kleinste) {
		zahl_groeste = zahl;
		position_groeste = position_kleinste;
	}
	cout << "Bitte geben Sie die 3. Zahl ein: ";
	cin >> zahl;
	if (zahl < zahl_kleinste) {
		zahl_kleinste = zahl;
		position_kleinste = 3;
	}
	else if (zahl > zahl_groeste) {
		zahl_groeste = zahl;
		position_groeste = 3;
	}
	cout << "Bitte geben Sie die 4. Zahl ein: ";
	cin >> zahl;
	if (zahl < zahl_kleinste) {
		zahl_kleinste = zahl;
		position_kleinste = 4;
	}
	else if (zahl > zahl_groeste) {
		zahl_groeste = zahl;
		position_groeste = 4;
	}
	cout << "Bitte geben Sie die 5. Zahl ein: ";
	cin >> zahl;
	if (zahl < zahl_kleinste) {
		zahl_kleinste = zahl;
		position_kleinste = 5;
	}
	else if (zahl > zahl_groeste) {
		zahl_groeste = zahl;
		position_groeste = 5;
	}




	cout << "Die " << position_kleinste << ". Zahl war die kleinste der eingegebenen Zahlen und lautet: " << zahl_kleinste << endl;
	cout << "Die " << position_groeste << ". Zahl war die groeste der eingegebenen Zahlen und lautet: " << zahl_groeste << endl;

	system("PAUSE");

}