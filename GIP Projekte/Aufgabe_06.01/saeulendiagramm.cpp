#include <iostream>
#include <string>

using namespace std;


int main() {


	int input[5][10] = { 0 }; // y = 0 wird nicht benutzt
	int reihe[5] = { 0 };
	int z = 0;
	int pX;




	for (int i = 0; i < 5 ; i++)
	{
		do
		{
			cout << "Bitte geben Sie die " << i+1 << ". Zahl ein: ? ";
			cin >> z;
			
		} while (z < 1 || z > 9);
		input[i][z] = 1; //x und y
	}//Zahlen eingelesen


	for (int y = 9; y > 0; y--)
	{
		cout << y;
		for (int x = 0; x < 5; x++)
		{
			if (reihe[x] == 1) { // welche reihe jetzt pluse beinhalten muss
				cout << "+";
			}
			else if (input[x][y] == 1) {//welcher punkt eine 1 hat fuer *
				cout << "*";
				reihe[x] = 1;
			}
			else {
				cout << " ";
			}

			//cout << input[x][y];
		}
			cout << endl;
		
	}
	cout << " 12345" << endl;
	system("PAUSE");
	return 0;
}