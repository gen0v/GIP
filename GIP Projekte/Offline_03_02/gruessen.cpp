#include <iostream>

using namespace std;

int main() {
	int uhr = 0;

	cout << "Bite geben Sie die Stunde der aktuellen Uhrzeit ein: ? ";
	cin >> uhr;
	
	if (0 <= uhr && uhr <= 23) {
		if ((0 <= uhr && uhr <= 5) || (uhr == 23)) {
			cout << "Gute Nacht." << endl;
		}
		if (6 <= uhr && uhr <= 10) {
			cout << "Guten Morgen." << endl;
		}
		if (11 <= uhr && uhr <= 13) {
			cout << "Mahlzeit." << endl;
		}
		if (14 <= uhr && uhr <= 17) {
			cout << "Guten Tag." << endl;
		}
		if (18 <= uhr && uhr <= 22) {
			cout << "Guten Abend." << endl;
		}
	}
	else {
		cout << "Keine erlaubte Stundenangabe." << endl;
	}

	system("PAUSE");
}