#include <iostream>

using namespace std;

int main() {
	//nehmen an die Eingabe ist richtig
	double euro = 0;
	cout << "Bitte geben Sie die Geldmenge in Euro ein: ? ";
	cin >> euro;
	cout << "Die Geldmenge in US Dollar lautet: " << euro * 1.2957 << endl;
	system("PAUSE");


}