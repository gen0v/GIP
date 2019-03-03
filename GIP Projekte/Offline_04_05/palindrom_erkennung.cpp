#include <iostream>
#include <string>

using namespace std;

int main() {

	bool eingabe = false;
	string text;
	string spiegel;

	do
	{
		cout << "Text: ? ";
		getline(cin, text);

		for (int i = 0; i < text.length(); i++) {
			if(text.at(i) < 'a' || text.at(i) > 'z') {
				eingabe = false;
				//cout << "Fehler" << endl;
				break;
			}
			eingabe = true;
		}
	} while (eingabe == false);
	
	for (int i = text.length(); i > 0; i--)
	{
		spiegel += text.at(i-1);
	}
	if (spiegel == text) {
		cout << "Das eingegebene Wort ist ein Palindrom.\n";
	}
	else cout << "Das eingegebene Wort ist KEIN Palindrom.\n";

	//cout << spiegel;
	system("PAUSE");
}