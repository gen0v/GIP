#include <iostream>

using namespace std;

int main() {

	int tagA = 0;
	int monatA = 0;
	int jahrA = 0;
	int tagB = 0;
	int monatB = 0;
	int jahrB = 0;

	cout << "Bitte geben Sie den Tag des ersten Datums ein: ";
	cin >> tagA;
	cout << "Bitte geben Sie den Monat des ersten Datums ein: ";
	cin >> monatA;
	cout << "Bitte geben Sie das Jahr des ersten Datums ein: ";
	cin >> jahrA;

	cout << "Bitte geben Sie den Tag des zweiten Datums ein: ";
	cin >> tagB;
	cout << "Bitte geben Sie den Monat des zweiten Datums ein: ";
	cin >> monatB;
	cout << "Bitte geben Sie das Jahr des zweiten Datums ein: ";
	cin >> jahrB;

	//Hier fangen die IF ELSE an.
	if (jahrA > jahrB) cout << "Das zweite Datum liegt vor dem ersten Datum.";
	else if (jahrA < jahrB) cout << "Das erste Datum liegt vor dem zweiten Datum.";
	else if (jahrA == jahrB && monatA > monatB) cout << "Das zweite Datum liegt vor dem ersten Datum.";//hier vertrauscht, da April>November
	else if (jahrA == jahrB && monatA < monatB) cout << "Das erste Datum liegt vor dem zweiten Datum.";
	else if (jahrA == jahrB && monatA == monatB && tagA > tagB) cout << "Das zweite Datum liegt vor dem ersten Datum.";
	else if (jahrA == jahrB && monatA == monatB && tagA < tagB) cout << "Das erste Datum liegt vor dem zweiten Datum.";
	else if (tagA == tagB && monatA == monatB && jahrA == jahrB) cout << "Beide Datumsangaben sind gleich Datum.\n";//Beide gleich


	cout << endl;
	system("PAUSE");

}