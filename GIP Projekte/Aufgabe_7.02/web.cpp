#include<iostream>
#include<string>
#include<fstream>
#include "texte.h"
#include "person.h"


using namespace std;

string br(string s) {
	s = s + "<br/>";
	return s;
}
string b(string s) {
	s = "<b>" + s + "</b>";
	return s;
}


int main() {

	string eingabezeile, kurztext, langtext;
	fstream personendatei("personendaten.txt", ios::in);


	while (getline(personendatei, eingabezeile))
	{
		cout << "Eine Zeile war: " << eingabezeile << endl;
		Person person = extrahiere_person(eingabezeile);
		//KURZTEXT
		kurztext += br(
			b(person.name) + ", " + person.vorname
		) + "\n";
		//LANGTEXT
		langtext += br(
			b(person.vorname + " " + person.name) + ", " + person.geburtsdatum
		) + "\n";


		cout << person.name << person.vorname << person.geburtsdatum << endl;
		cout << kurztext << endl;
		cout << langtext << endl;
	}
	personendatei.close();

	//5
	fstream templatendatei("webseite.html.tmpl", ios::in);
	fstream ausgabedatei("webseite.html", ios::out);

	while (getline(templatendatei, eingabezeile)) {

		ersetze(eingabezeile, '%', kurztext);
		ersetze(eingabezeile, '$', langtext);

		ausgabedatei << eingabezeile + "\n";
	}





	/*
	string test = "Das ist ein, test, string";
	//string s1 = "XXXXXXXXXXXXXXXXXXXXXXXXXXX";
	string s1(test.length(), ' ');
	string s2(test.length(), ' ');
	spalte_ab_erstem(',', test, s1, s2);
	cout << s1 << endl;
	cout << s2 << endl;
	
	string teststring = " 12 45 67 8";
	loesche_leerzeichen(teststring);
	cout << " TEST 123 " << teststring;
	*/
	templatendatei.close();
	ausgabedatei.close();
	
	system("PAUSE");
	return 0;
}