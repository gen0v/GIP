#include <iostream>

using namespace std;


int main() {


	//Variables deklarieren
	bool found = false;
	int border_low = 1;
	int border_high = 100;
	int middle = 0;
	int temp = 0;
	int i = 1;
	char input_ch = '.';
	//Array initialisieren
	/*int numbers[100];
	for (i = 1; i <= 100; i++)
	{
		//cout << i << endl;
		numbers[i] = i;
	}*/

	//Programm start
	cout << "Merken Sie sich eine Zahl zwischen 1 und 100 (inkl.)\n";
	cout << endl;

	while (!found) {

		//Schleife mit Switch Case fuer das finden der Zahl
		cout << "Aktueller Ratebereich: " << border_low << " bis " << border_high << endl ;
		temp = (border_high - border_low) / 2;
		if (input_ch == 'g' && temp < 1) temp = 1; //Problemfall fuer 100 behoben
		middle = border_low + temp;
		cout << "Ist " << middle << " Ihre Zahl?\n";
		cout << "(j) ja: gleich,\n";
		cout << "(k) nein, meine Zahl ist kleiner\n";
		cout << "(g) nein, meine Zahl ist groesser\n";
		cout << "? ";
		cin >> input_ch;
		
		switch (input_ch)
		{
		default:
			break;
		case 'j':
			found = true;
			break;
		case 'k': //Ratebereich optimieren
			border_high = middle;
			break;
		case 'g': // Ratebereich optimieren
			border_low = middle;		
			break;
		}
	}

	system("PAUSE");

}