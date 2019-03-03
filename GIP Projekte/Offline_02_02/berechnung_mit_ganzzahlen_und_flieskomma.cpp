#include <iostream>

using namespace std;

int main() {

	int stimmen = 0;
	int stimmen_1 = 0;
	int stimmen_2 = 0;

	cout << "Bitte geben Sie die Gesamtzahl der abgegebenen gueltigen Stimmen ein: ? ";
	cin >> stimmen;
	cout << "Bitte geben Sie die Anzahl Stimmen des ersten Kandidaten ein: ? ";
	cin >> stimmen_1;
	cout << "Bitte geben Sie die Anzahl Stimmen des zweiten Kandidaten ein: ? ";
	cin >> stimmen_2;
	cout << "Auf den dritten Kandidaten sind somit "<< stimmen-stimmen_1-stimmen_2 <<" Stimmen entfallen."<<endl;

	cout << "Kandidat 1 erhielt "<<(100.0/stimmen) * stimmen_1 <<"% der Stimmen."<<endl;
	cout << "Kandidat 2 erhielt "<< (100.0 / stimmen) * stimmen_2 <<"% der Stimmen." << endl;
	cout << "Kandidat 3 erhielt "<< (100.0 / stimmen) * (stimmen - stimmen_1 - stimmen_2) <<"% der Stimmen." << endl;
	
	system("PAUSE");
}