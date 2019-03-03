#include <iostream>
#include <string>

using namespace std;

void teile_string(string &dertext,int pos, char zeichen) {
	//cout << "Teile String\n";
	string teil1 = "";
	string teil2 = "";
	for (int i = 0; i < pos+1; i++)
	{
		//cout << "Erster Teil >> " << dertext.at(i) <<endl;
		teil1 += dertext.at(i);
	}
	for (int h = pos+1; h < dertext.length(); h++)
	{
		//cout << "Zweiter Teil >> " << dertext.at(h) << endl;
		teil2 += dertext.at(h);
	}
	teil1 += zeichen;
	dertext = teil1 + teil2;
}

void loesche_zeichen(string &temp) {
	string verbessert;

	for (int i = 0; i < temp.length(); i++)
	{
		if ((temp.at(i) == '!' || temp.at(i) == '?')) {
		}
		else verbessert += temp.at(i);

	}

	temp = verbessert;
}



int main() {

	string text;
	string temp;
	string temp2;

	cout << "Bitte Text eingeben (ggfs. mit Leerzeichen): ? ";
	getline(cin, text);
	
	//Unwandeln
	for (int a = 0; a < text.length(); a++)
	{
		//Kleinbuchstaben
		if (text.at(a) >= 'a' && text.at(a) <= 'z')
		{
			teile_string(text, a, text.at(a));
			a++;
		}
		//Grossbuchstaben
		else if (text.at(a) >= 'A' && text.at(a) <= 'Z')
		{
			teile_string(text, a, text.at(a));
			teile_string(text, a+1, text.at(a));
			a=a+2;
		}
		//Zahlen
		else if (text.at(a) >= '0' && text.at(a) <= '9')
		{
			text.at(a) = '.';
		}
		//Ausrufezeichen und Fragezeichen
		else if (text.at(a) == '!' || text.at(a) == '?')
		{
			loesche_zeichen(text);
			a--;
		}
		else if (text.at(a) == ' ')
		{
			text.at(a) = '_';
		}
	}

	cout <<"Der Text nach der Umwandlung: "<< text<<endl;
	system("PAUSE");
}