#include <iostream>
#include <string>

using namespace std;

int main() {

	int eingabe = 0;
	string komplett;
	int unterschiedlich = 0;
	char zahl;
	bool eins = false;
	bool zwei = false;
	bool drei = false;
	bool vier = false;
	bool fuenf = false;
	bool sechs = false;
	bool zahlen[6] = { false,false,false,false,false,false };


	for (int a = 0; a < 9; a++)
	{
		do
		{
			cout << "Bitte geben Sie die " << a + 1 << ". Zahl ein: ? ";
			cin >> zahl;
			eingabe = zahl - 48;
		} while (eingabe < 1 || eingabe > 6);

		switch (zahl)
		{
		default:
			break;
		case '1':
			zahlen[0] = true;
			break;
		case '2':
			zahlen[1] = true;
			break;
		case '3':
			zahlen[2] = true;
			break;
		case '4':
			zahlen[3] = true;
			break;
		case '5':
			zahlen[4] = true;
			break;
		case '6':
			zahlen[5] = true;
			break;
		}

	}

	for (bool test : zahlen)
	{
		if (test == true) unterschiedlich++;
	}

	cout << "In der Eingabe kamen " << unterschiedlich <<" unterschiedliche Zahlen vor.\n";
	system("PAUSE");
}