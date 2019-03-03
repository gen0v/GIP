#include <iostream>
#include <string>
#include "wortspiegel.h"


using namespace std;

string text;
char eingabe;
int position = 0;

void search_last() {
	if (position > 0) {
		/*
		do
		{
			if (text.at(position - 1) == ' ' || text.at(position - 1) == '.') {
				//Position noch weiter verschieben
				position = position - 2;
			}
			else { position = position - 1; }
			if (text.at(position) != ' ' && text.at(position) != '.')
				{
					break;
			}
		} while (true);
		/*if (text.at(position-1) == ' ' || text.at(position-1) == '.') {
			//Position noch weiter verschieben
			position = position - 2;
		}
		else position = position - 1;*/
		position = position - 1;
	}
}
void search_next() {
	if (position < text.length()-1) {
		/*
		do
		{
			if (text.at(position + 1) == ' ' || text.at(position + 1) == '.') {
				//Position noch weiter verschieben
				position = position + 2;
			}
			else { position = position + 1; }
			if (text.at(position) != ' ' && text.at(position) != '.')
			{
				break;
			}
		} while (true);
		
		
		
		
		/*if (text.at(position + 1) == ' ' || text.at(position + 1) == '.') {
			//Position noch weiter verschieben
			
			position = position + 2;
		}
		else position = position + 1;*/
		position = position + 1;
	}
}

void stern() {
	for (int i = 0; i < position; i++)
	{
		cout << " ";
	}
	cout << "*" << endl;
}

void befehl(char in) {

	switch (in)
	{
	default:
		break;
	case 'l':
		search_last();
		//if (position > 0) position--;
		break;
	case 'r':
		search_next();
		//if (position < text.length()-1) position++;
		break;
	case 's':
		text = wortspiegel(text, position);
		break;
	case 'q':
		//tu nichts
		break;
	}



}
void menu() {cout << "Befehl (l: links, r: rechts, s: spiegeln, q: Ende) ?- ";}



int main() {
	
	cout << "Bitte geben Sie einen Text ein: ? ";
	getline(cin, text);

	do
	{
		cout << text << endl;
		stern();
		menu();
		cin >> eingabe;
		befehl(eingabe);
	} while (eingabe != 'q');



	system("PAUSE");
}