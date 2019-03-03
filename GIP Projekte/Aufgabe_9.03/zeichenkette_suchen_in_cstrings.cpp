#include <iostream>
#include "string"

using namespace std;


int clength(char *text) {
	int counter = 0;
	for (int i = 0; i < 20; i++)
	{
		//Null Terminator
		if (text[i] == '\0') { 
			break;
		}
		else counter++;
	}
	return counter;
}


int zeichenkette_suchen(char* text, char* zkette) {
	int length = clength(text);
	int z = 0;

	for (int i = 0; i < length; i++)
	{
		if (text[i] == zkette[z] && z < clength(zkette)) {

			z++;
		}
		else if (z == clength(zkette)) {
			return i - z;
		}
		else z = 0; //zurucksetzten
	}

	if (z == clength(zkette)) {
		return length-z;
	}

	return -1;
}


int main() {
	const int len = 20;
	char eingabe[len] = { 0 };
	char suche[20] = { 0 };
	

	cout << "Bitte geben Sie den Text ein: " << endl;
	cin.getline(eingabe, len);

	cout << "Bitte geben Sie die zu suchende Zeichenkette ein: " << endl;
	cin.getline(suche, len);

	
	//cout << clength(eingabe);
	//cout << " TEST TEST " << zeichenkette_suchen(eingabe, suche);

	if (zeichenkette_suchen(eingabe, suche) == -1) {
		cout << "Die Zeichenkette '" << suche << "' ist NICHT in dem Text '" << eingabe << "' enthalten.\n";
	}
	else {
		cout << "Die Zeichenkette '" << suche << "' ist in dem Text '" << eingabe << "' enthalten.\n";
		cout << "Sie startet ab Zeichen " << zeichenkette_suchen(eingabe, suche) << " (bei Zaehlung ab 0).\n";
	}

	//Maximale Anzahl Zeichen 20
	//Abfrage kann theoretisch gleiche Anzahl an Zeichen sein (hier: "len")
	//damit ergibt sich, dass Text und Abfrage auch identisch sein koennen

	system("Color 2B");
	std::cout << "\t\t\t    Hello World" << std::endl;
	

	system("PAUSE");
}