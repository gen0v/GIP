#include <iostream>

using namespace std;

int main() {
	//nehmen an die Eingabe ist richtig
	double temperatur = 0;
	cout << "Bitte geben Sie die Temperatur in Grad Celsius ein: ? ";
	cin >> temperatur;
	cout << "Die Temperatur in Fahrenheit lautet: " << temperatur * 1.8 + 32 << endl;
	system("PAUSE");


}