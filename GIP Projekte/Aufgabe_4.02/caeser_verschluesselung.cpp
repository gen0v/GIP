#include <iostream>
#include <string>

using namespace std;


int main() {

	//Variablen
	string input;
	char letter;
	int letter_pos = 0;
	int position = 0;
	int verschiebung = 0;
	char auswahl = '.';

	cout << "Bitte geben Sie den zu verschluesselnden Text ein: ";
	getline(cin, input);
	cout << "Bitte geben Sie die Anzahl Verschiebepositionen ein (als positive ganze Zahl): ";
	cin >> verschiebung;
	
	while (verschiebung > 26) {
		/*
		Falls verschiebung so gross ist, dass
		Warp Around mehr als einmal passiert
		Subtrahieren bis es sozusagen nur ein
		Warp Around wird.
		*/
		verschiebung = verschiebung - 26;
	}
	//nur Buchstaben(klein und gross) um @position verschieben
	
	while (position < input.length()) {

		letter = input.at(position);
		letter_pos = (int)letter;
		if (65 <= letter_pos && letter_pos <= 90) {
			auswahl = 'g';//Grossbuchstabe
		}
		else if (97 <= letter_pos && letter_pos <= 122) {
			auswahl = 'k';//Kleinbuchstabe
		}
		else auswahl = 'n';

		switch (auswahl)
		{
		default:
			break;
		case 'g':
			//Grossbuchstabe
			letter_pos = letter_pos + verschiebung;
			if (letter_pos > 90) {//warp around
				letter_pos = (letter_pos - 90) + 64;
			}
			//cout << "g" << verschiebung;//Test
			input.at(position) = (char)letter_pos;//Buchstaben wieder reinsetzten
			break;
		case 'k':
			//Kleinbuchstabe
			letter_pos = letter_pos + verschiebung;
			if (letter_pos > 122) {//warp around
				letter_pos = (letter_pos - 122) + 96;
			}
			//cout << "k" << verschiebung;//Test
			input.at(position) = (char)letter_pos;//Buchstaben wieder reinsetzten
			break;
		case 'n':
			//tue nichts nur wieder reinschreiben
			//cout << "n" << verschiebung;//Test
			break;
		}


		position++;
	}

	//Ausgabe
	cout << endl;

	position = 0;
	while (position < input.length())
	{
		cout << input.at(position);
		position++;
	}
	cout << endl;
	system("PAUSE");

}