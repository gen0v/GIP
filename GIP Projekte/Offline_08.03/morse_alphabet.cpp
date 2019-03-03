#include<iostream>
#include<string>

using namespace std;


struct T_Morse_Data
{
	char letter;
	std::string morse_code;
};
const T_Morse_Data morse_data[] = {
{ 'a', ".-" },
{ 'b', "-..." },
{ 'c', "-.-." },
{ 'd', "-.." },
{ 'e', "." },
{ 'f', "..-." },
{ 'g', "--." },
{ 'h', "...." },
{ 'i', ".." },
{ 'j', ".---" },
{ 'k', "-.-" },
{ 'l', ".-.." },
{ 'm', "--" },
{ 'n', "-." },
{ 'o', "---" },
{ 'p', ".--." },
{ 'q', "--.-" },
{ 'r', ".-." },
{ 's', "..." },
{ 't', "-" },
{ 'u', "..-" },
{ 'v', "...-" },
{ 'w', ".--" },
{ 'x', "-..-" },
{ 'y', "-.--" },
{ 'z', "--.." },
{ '0', "-----" },
{ '1', ".----" },
{ '2', "..---" },
{ '3', "...--" },
{ '4', "....-" },
{ '5', "....." },
{ '6', "-...." },
{ '7', "--..." },
{ '8', "---.." },
{ '9', "----." },
// Leerzeichen zur Worttrennung werden im Morsecode
// durch einen Slash '/' umgeben von Leerzeichen
// dargestellt ...
// (Alternative: Trennung durch 3 Leerzeichen)
// Hier bei uns, um die Testläufe eindeutiger zu
// machen: Trennung mittels drei Slashes
{ ' ', "///" },
{ '.', ".-.-.-" },
{ ',', "--..--" },
{ ':', "---..." },
{ '?', "..--.." },
{ '-', "-....-" },
{ '/', "-..-." },
{ '@', ".--.-." },
{ '=', "-...-" }
};
const int morse_data_len = 47;

int main() {

	string eingabe;

	cout << "Bitte Text eingeben (ggfs. mit Leerzeichen): ? ";
	getline(cin, eingabe);
	for (int i = 0; i < eingabe.length(); i++)
	{
		if (eingabe.at(i) > 64 && eingabe.at(i) < 91) eingabe.at(i) += 32;
	}
	for (int i = 0; i < eingabe.length(); i++)
	{
		//if Leerzeichen
		if (eingabe.at(i) == ' ') {
			cout << "///#";
		}
		else
		{
		//sonst suchen zugehor. morsecode
		for (int j = 0; j < 47; j++)
		{
			if (morse_data[j].letter == eingabe.at(i)) {
				cout << morse_data[j].morse_code << "#";
				break;
			}
		}
	}
	}

	cout << endl;
	system("PAUSE");
}