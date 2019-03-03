#include <iostream>
#include <string>

using namespace std;

int main() {

	string eingabe;
	cout << "Bitte einzeiligen Text eingeben (ohne Leerzeichen): ? ";
	getline(cin, eingabe);

	if (eingabe.length() > 0) {
		for (int i = 0; i < eingabe.length(); i++)
		{
			cout << "Position: " << i << " Buchstabe: " << eingabe.at(i) << endl;
		}
	}

	system("PAUSE");
}