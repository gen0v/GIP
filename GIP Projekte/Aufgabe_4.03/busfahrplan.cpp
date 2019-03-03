#include <iostream>

using namespace std;


int main() {

	//Variablen
	int start_hours = 0, start_minutes = 0, takt = 0;
	int differenz = 0;
	int minutes = 0;
	int takt_var = 0;

	//Zuerst Abfragen und auf Richtigkeit pruefen
	do {
		cout << "Bitte geben Sie die Stunden der Startuhrzeit ein: ";
		cin >> start_hours;
	} while (!(0 <= start_hours && start_hours <= 23));//23, da aber 24 = 0
	do {
		cout << "Bitte geben Sie die Minuten der Startuhrzeit ein: ";
		cin >> start_minutes;
	} while (!(0 <= start_minutes && start_minutes <= 59));// 60 = 0
	cout << "Der erste Bus faehrt also um " << start_hours << ":" << start_minutes << " Uhr." << endl;
	do {
		cout << "Bitte geben Sie die Taktzeit in Minuten ein: ";
		cin >> takt;
	} while (!(0 < takt && takt <= 180));
	
	//Jetzt das Programm und die Ausgabe
	for (int hours = start_hours; hours < 24; hours++) {
		takt_var = takt;
		//nur inkrementieren falls minuten ueber 60 steigt
		minutes = start_minutes;
		while (minutes < 60) {
			cout << hours << ":" << minutes << " ";
			minutes = minutes + takt;
			differenz = minutes;
		}


		if (takt > 60) {
			while (takt_var > 60) {
				if (takt_var > 120) hours++;
				takt_var = takt_var - 60;
				//hours++;
				
			}
			if ((start_minutes + takt_var) > 59) {
				start_minutes = (start_minutes + takt_var) - 60;
				hours++;
			}
			else {
				start_minutes = start_minutes + takt_var;
			}
		}
		else if (minutes >= 60) {
			start_minutes = differenz - 60;
		}
		
		cout << endl;
	}


	system("PAUSE");
}