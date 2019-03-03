#include <iostream>
#include<string>

using namespace std;


void spalte_ab_erstem(char zeichen, string eingabe, string& erster_teil, string& zweiter_teil) {

	bool found = false;

	for (int i = 0; i < eingabe.length(); i++)
	{
		if (zeichen == eingabe.at(i) && found == false) {
			//Zeichen gefunden mache nichts
			found = true;
		}
		else if (!found) {
			erster_teil += eingabe.at(i);
		}
		else {
			zweiter_teil += eingabe.at(i);
		}
	}

}

int main() {

	string input, first, second;
	char c;
	cout << "Bitte geben Sie die einzeilige Zeichenkette ein: ? ";
	getline(cin, input);
	cout << "Bitte geben Sie das Zeichen ein: ? ";
	cin >> c;
	spalte_ab_erstem(c, input, first, second);
	cout << "Der erste Teil der Zeichenkette lautet: " << first << endl;
	cout << "Der zweite Teil der Zeichenkette lautet: " << second << endl;


	
	system("PAUSE");
}