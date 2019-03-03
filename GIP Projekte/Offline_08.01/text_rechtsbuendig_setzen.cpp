#include <iostream>
#include <string>

using namespace std;

int main() {

	string eingabe[4] = {"","","",""};
	int i = 0;
	int max = 0;
	while (eingabe[i].length() < 1 || i > 4)
	{
	
		cout << "Textzeile = ? ";
		getline(cin, eingabe[i]);
		if (eingabe[i].length() > max) {
			max = eingabe[i].length();
		}
		if (eingabe[i].length() < 1)
		{
			break;
		}
		i++;
	} 


	//Logik
	//Finde den laengsten string

	
	for (string var: eingabe)
	{
		if (var.length() == 0) break;
		int m = 0;
		while (var.length() + m < max)
		{
			cout << "#";
			m++;
		}
		cout << var << endl;
	}
	
	system("PAUSE");
	return 0;
}