
#include <iostream>
#include <string>

using namespace std;

struct Person
{
	string nachname, vorname;
	int alter;
	char geschlecht;
};


void filter(Person p[100], int anzahl) {
	
	int e = 0;
	int count = 0;
	cout << "Ihre Auswahl:\n";
	cout << "1 - Weibliche Erwachsene\n";
	cout << "2 - Maennliche Erwachsene\n";
	cout << "3 - Weibliche Kinder\n";
	cout << "4 - Maennliche Kinder\n";
	cout << "? ";
	cin >> e;
	switch (e)
	{
	case 1:
		for (int i = 0; i < anzahl; i++)
		{
			if (p[i].geschlecht == 'w' && p[i].alter >= 18) {
				cout << p[i].nachname << ", " << p[i].vorname << ", " << p[i].geschlecht << ", " << p[i].alter << endl;
				count++;
			}
		}
		break;

	case 2:
		for (int i = 0; i < anzahl; i++)
		{
			if (p[i].geschlecht == 'm' && p[i].alter >= 18) {
				cout << p[i].nachname << ", " << p[i].vorname << ", " << p[i].geschlecht << ", " << p[i].alter << endl;
				count++;
			}
		}
		break;

	case 3:
		for (int i = 0; i < anzahl; i++)
		{
			if (p[i].geschlecht == 'w' && p[i].alter < 18) {
				cout << p[i].nachname << ", " << p[i].vorname << ", " << p[i].geschlecht << ", " << p[i].alter << endl;
				count++;
			}
		}
		break;

	case 4:
		for (int i = 0; i < anzahl; i++)
		{
			if (p[i].geschlecht == 'm' && p[i].alter < 18) {
				cout << p[i].nachname << ", " << p[i].vorname << ", " << p[i].geschlecht << ", " << p[i].alter << endl;
				count++;
			}
		}
		break;

	default:
		break;
	}

	cout << "Summe: " << count <<endl;
}

int main() {

	//Person personen[100];
	Person personen[100] = {
	{ "Musterfrau1", "Petra1", 18, 'w' },
	{ "Mustermann1", "Klaus1", 18, 'm' },
	{ "Mustermaedchen1", "Lisa1", 1, 'w' },
	{ "Musterjunge1", "Jan1", 1, 'm' },
	{ "Musterfrau2", "Petra2", 19, 'w' },
	{ "Mustermann2", "Klaus2", 19, 'm' },
	{ "Mustermaedchen2", "Lisa2", 2, 'w' },
	{ "Musterjunge2", "Jan2", 2, 'm' },
	{ "Musterfrau3", "Petra3", 20, 'w' },
	{ "Mustermann3", "Klaus3", 20, 'm' },
	{ "Mustermaedchen3", "Lisa3", 3, 'w' },
	{ "Musterjunge3", "Jan3", 3, 'm' },
	{ "Musterfrau4", "Petra4", 21, 'w' },
	{ "Mustermann4", "Klaus4", 21, 'm' },
	{ "Mustermaedchen4", "Lisa4", 4, 'w' },
	{ "Musterjunge4", "Jan4", 4, 'm' },
	{ "Musterfrau5", "Petra5", 22, 'w' },
	{ "Mustermann5", "Klaus5", 22, 'm' },
	{ "Mustermaedchen5", "Lisa5", 5, 'w' },
	{ "Musterjunge5", "Jan5", 5, 'm' },
	{ "Musterfrau6", "Petra6", 23, 'w' },
	{ "Mustermann6", "Klaus6", 23, 'm' },
	{ "Mustermaedchen6", "Lisa6", 6, 'w' },
	{ "Musterjunge6", "Jan6", 6, 'm' },
	{ "Musterfrau7", "Petra7", 24, 'w' },
	{ "Mustermann7", "Klaus7", 24, 'm' },
	{ "Mustermaedchen7", "Lisa7", 7, 'w' },
	{ "Musterjunge7", "Jan7", 7, 'm' },
	{ "Musterfrau8", "Petra8", 25, 'w' },
	{ "Mustermann8", "Klaus8", 25, 'm' },
	{ "Mustermaedchen8", "Lisa8", 8, 'w' },
	{ "Musterjunge8", "Jan8", 8, 'm' }
	};
	int anzahl_personen = 32;

	char eingabe;

	string name, vorname;
	char geschlecht;
	int alter = 0;

	do
	{
		cout << "Eine weitere Person eingeben (j/n)? ";
		cin >> eingabe;
		cin.clear();
		cin.ignore();
		if (eingabe == 'j') {
			cout << "Bitte den Nachnamen der " << anzahl_personen+1 << ". Person eingeben: ? ";
			getline(cin, name);
			cout << "Bitte den Vornamen der " << anzahl_personen+1 << ". Person eingeben: ? ";
			getline(cin, vorname);
			cout << "Bitte das Alter der " << anzahl_personen+1 << ". Person eingeben: ? ";
			cin >> alter;
			cin.clear();
			cin.ignore();
			cout << "Bitte das Geschlecht der " << anzahl_personen+1 << ". Person eingeben: ? ";
			cin >> geschlecht;
			cin.clear();
			cin.ignore();
			personen[anzahl_personen] = { name,vorname,alter,geschlecht };
			anzahl_personen++;
		}

	} while (eingabe != 'n');

	filter(personen, anzahl_personen);

	system("PAUSE");
}