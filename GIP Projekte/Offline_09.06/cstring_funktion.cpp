#include <iostream>
#include <string>
using namespace std;

int clength(const char *text) {
	int counter = 0;
	for (int i = 0; i < 20; i++)
	{
		//Null Terminator
		if (text[i] == '\0') {
			break;
		}
		else counter++;
	}
	return counter;
}

char* my_strconcat(const char * ptr1, const char * ptr2) {

	int max = clength(ptr1) + clength(ptr2);
	char r[40] = { 0 };
	bool firstword = true;
	int j = 0;

	for (int i = 0; i < 40; i++)
	{
		if (firstword && ptr1[i] != '\0') {
			r[i] = ptr1[i];
		}
		else if(i < max){
			firstword = false;
			//jetzt im zweiten wort
			r[i] = ptr2[j];

			j++;
		}
		else {
			break;
		}
	}


	return r;

}


int main() {

	char one[20];
	char two[20];

	cout << "Bitte ersten Text eingeben (ggfs. mit Leerzeichen): ? ";
	cin.getline(one, 20);
	cout << "Bitte zweiten Text eingeben (ggfs. mit Leerzeichen): ? ";
	cin.getline(two, 20);
	cout << "Ergebnis my_strconcat(): ";
	for (int i = 0; i < clength(my_strconcat(one, two));i++)
	{
		cout << my_strconcat(one, two)[i];
	}
	cout << endl;
	system("PAUSE");
}