#include<iostream>
#include"binaerer_suchbaum.h"

using namespace std;

int main() {

	int eingabe = 0;

	BaumKnoten* baum = new BaumKnoten;
	baum->elternknoten = true;

	cout << "Leerer Baum.\n";
	do
	{
		cout << "Naechster Wert (99 beendet) : ?";
		cin >> eingabe;
		if(eingabe != 99)
		suchbaum::einfuegen(baum, eingabe);
		
	} while (eingabe != 99);

	suchbaum::ausgeben(baum, 0);

	system("PAUSE");

}