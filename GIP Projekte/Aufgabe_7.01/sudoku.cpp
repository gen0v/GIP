#include <iostream>
#include <string>

/*

.5.1.4.|.8.6.9.|.7.2.3
.8.7.2.|.3.4.5.|.6.1.9
.9.6.3.|.2.1.7.|.5.4.8
-------|-------|-------
.6.2.8.|.1.3.4.|.9.5.7
.1.9.7.|.6.5.2.|.8.3.4
.4.3.5.|.7.9.8.|.1.6.2
-------|-------|-------
.2.4.6.|.9.7.1.|.3.8.5
.7.5.1.|.4.8.3.|.2.9.6
.3.8.9.|.5.2.6.|.4.7.1

.9.4.6.|.3.1.8.|.2.7.5
.1.2.3.|.7.5.6.|.9.4.8
.5.8.7.|.2.4.9.|.6.3.1
-------|-------|-------
.8.1.4.|.9.2.5.|.7.6.3
.2.7.5.|.1.6.3.|.8.9.4
.6.3.9.|.8.7.4.|.1.5.2
-------|-------|-------
.3.6.8.|.5.9.2.|.4.1.7
.4.5.1.|.6.8.7.|.3.2.9
.7.9.2.|.4.3.1.|.5.8.6

*/

void saveToArray(char zahl, int (&arr)[9][9], int &r, int &s){
	//Char in INT umwandel, dann ins array speichern
	int z = zahl - '0';
	//std::cout << z <<"Temp"<< std::endl;
	//Reihe und Spalte
	if (r >= 9) {
		//FEHLER
		r = 0;
		s++;
	}
	arr[r][s] = z;
	r++;


}

int main() {

	//Variablen
	int sudoku[9][9] = {0};
	std::string eingabe[11];
	int global = 0;
	int reihe = 0, spalte = 0;
	int counter_row = 0;
	int counter_col = 0;

	//MAIN
	std::cout << "Bitte geben Sie das Sudoku ein:" << std::endl;

	//Einlesen
	for (int i = 0; i < 11; i++)
	{
		std::getline(std::cin, eingabe[i]);
	}
	
	//Bearbeiten
	for (int i = 0; i < 11; i++)
	{
		for (int a = 0; a < eingabe[i].length(); a++)
		{
			if (eingabe[i].at(a) >= '0' && eingabe[i].at(a) <= '9') {
				//Dann speicher in Array das int 
				saveToArray(eingabe[i].at(a), sudoku, reihe, spalte);
			}
		}
	}
	//Ausgeben

	//TEST
	/*
	for (int y = 0; y < 9; y++)
	{
		for (int x = 0; x < 9; x++)
		{
			std::cout << sudoku[x][y];
		}
		std::cout << std::endl;
	}
	*/
	//Richtige Ausgabe
	std::cout << "Das Sudoku lautet:" << std::endl;
	for (int a1 = 0; a1 < 9; a1++)
	{
		std::cout << ";";
		for (int a2 = 0; a2 < 9; a2++)
		{
			if (counter_row > 2) {
				std::cout << "//;";
				counter_row = 0;
			}
			std::cout << sudoku[a2][a1];
			//std::cout << ";" << sudoku[a2][a1];
			if (a2 < 8) {
				std::cout << ";";
			}
			counter_row++;
		}
		counter_row = 0;
		std::cout << std::endl;
		counter_col++;
		if (counter_col > 2 && a1 < 6) {
			std::cout << "=======//=======//=======";
			std::cout << std::endl;
			counter_col = 0;
		}


		
	}


	system("PAUSE");

}