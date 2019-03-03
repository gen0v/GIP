#include <iostream>

using namespace std;

int main() {

	char zahl_a, zahl_b;
	int zahl_A = 0, zahl_B = 0;

	cout << "Bitte geben Sie die erste Ziffer: ? ";
	cin >> zahl_a;
	cout << "Bitte geben Sie die zweite Ziffer: ? ";
	cin >> zahl_b;

	if (zahl_a == 'q' || zahl_b == 'q') {
		cout << "Das Programm wurde durch Eingabe von q beendet" << endl;
		system("PAUSE");
		return 1;
	}
	else {
		zahl_A = zahl_a - '0';
		zahl_B = zahl_b - '0';
		cout << zahl_A << " + " << zahl_B << " = " << zahl_A + zahl_B << endl;
		system("PAUSE");
		return 0;

	}



}