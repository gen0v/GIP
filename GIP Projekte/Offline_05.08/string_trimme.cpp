
#include <iostream>
#include <string>

using namespace std;


string trimme(string s) {
	string r;
	bool anfang = true, ende = true;
	int a = 0, b = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (s.at(i) == '+' && anfang) {
			a = i;
		}
		else {
			if (i == 0) a = -1;
			break;
		}
	}

	for (int i = s.length() - 1; i > 0; i--)
	{
		if (s.at(i) == '+' && ende) {
			b = i;
		}
		else {
			if (i == s.length() - 1) b = s.length();
			break;
		}
	}

	for (int g = a+1; g < b; g++)
	{
		r += s.at(g);
	}
	return r;
}


int main()
{
	string s = "";
	cout << "Bitte geben Sie die Textzeile ein: ? ";
	getline(cin, s);
	cout << "Vorher: " << s << endl;
	cout << "Nachher: " << trimme(s) << endl;
	system("PAUSE");
	return 0;
}