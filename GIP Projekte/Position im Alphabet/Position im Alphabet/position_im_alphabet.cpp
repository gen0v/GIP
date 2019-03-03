#include <iostream>

using namespace std;

int main() {
	char buchstabe;
	cout << "Bitte geben Sie den Buchstaben ein: ? "; // wir gehen davon aus, dass es nur Kleinbuchstaben sind
	cin >> buchstabe;
	cout << "Der Buchstabe " << buchstabe << " hat die Position " << (int)buchstabe - 96 << " im Alphabet.\n";
	system("PAUSE");

}