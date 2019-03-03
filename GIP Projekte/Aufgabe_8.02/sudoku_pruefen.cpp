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
.1.2.3.|.7.5.6.|.9.4.6
.5.8.7.|.2.4.9.|.6.3.1
-------|-------|-------
.8.1.4.|.9.2.5.|.7.6.6
.2.7.6.|.1.6.3.|.8.9.4
.6.3.9.|.8.7.4.|.1.5.6
-------|-------|-------
.3.6.8.|.5.9.2.|.4.1.7
.4.5.6.|.6.8.7.|.3.2.9
.7.9.2.|.4.6.1.|.5.8.6

.5.1.4.|.1.6.9.|.7.2.3
.8.7.2.|.3.4.5.|.6.1.9
.9.6.1.|.2.1.7.|.1.4.8
-------|-------|-------
.6.2.8.|.1.3.4.|.9.5.7
.1.9.7.|.6.5.2.|.8.3.4
.8.1.5.|.7.9.8.|.1.6.2
-------|-------|-------
.2.4.6.|.9.7.1.|.3.8.5
.7.1.1.|.4.1.3.|.2.1.6
.3.8.9.|.5.7.6.|.4.7.1

*/
bool pruefe_block(int x, int y, int sudo[9][9],int block) {
/*	for (int i = x + 1; i < 9; i++)
	{
		if (sudo[x][y] == sudo[i][y]) {
			return true;
		}
	}

	return false;*/
	int b = block;

	for (int by = y; by <= b / 3 * 3 + 2; by++)
	{

		for (int bx = x; bx <= b % 3 * 3 + 2; bx++)
		{
			if (sudo[y][x] == sudo[by][bx]) {
				return true;
			}
		}
	}
	return false;
}


void pruefe_block_vorhanden(int y, int x_s, int sudo[9][9], int zahl, int block) {
	bool vorhanden = false;
	for (int x = 0; x < 9; x++)
	{
		if (sudo[y][x] == zahl) {
			vorhanden = true;
		}
	}
	if (vorhanden == false) {
		std::cout << "Block " << block << ": Zahl " << zahl << " kommt nicht vor\n";
	}
}

void pruefe_reihe_vorhanden(int y,int x_s,int sudo[9][9], int zahl) {
	bool vorhanden = false;
	for (int x = 0; x < 9; x++)
	{
		if (sudo[x][y] == zahl) {
			vorhanden = true;
		}
	}
	if (vorhanden == false) {
		std::cout << "Zeile " << y << ": Zahl " << zahl << " kommt nicht vor\n";
	}
}

void pruefe_spalte_vorhanden(int y_s, int x, int sudo[9][9], int zahl) {
	bool vorhanden = false;
	for (int y = 0; y < 9; y++)
	{
		if (sudo[x][y] == zahl) {
			vorhanden = true;
		}
	}
	if (vorhanden == false) {
		std::cout << "Spalte " << x << ": Zahl " << zahl << " kommt nicht vor\n";
	}
}



bool pruefe_reihe(int x, int y, int sudo[9][9], int grenze) {
	for (int i = x+1; i < grenze; i++)
	{
		//std::cout << "Pruefe Reihe  " << y << ": die zahl " << sudo[x][y] <<" XX "<<sudo[i][y] << "\n";
		if (sudo[x][y] == sudo[i][y]) {
			return true;
		}
	}

	return false;
}





bool pruefe_spalte(int x, int y, int sudo[9][9], int grenze) {
	for (int i = y + 1; i < grenze; i++)
	{
		if (sudo[x][y] == sudo[x][i]) {
			return true;
		}
	}

	return false;
}


void saveToArray(char zahl, int(&arr)[9][9], int &r, int &s) {
	//Char in INT umwandel, dann ins array speichern
	int z = zahl - '0';
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
	int sudoku[9][9] = { 0 };
	std::string eingabe[11];
	int global = 0;
	int reihe = 0, spalte = 0;
	int counter_row = 0;
	int counter_col = 0;
	int block_zaehler = 0;
	bool sudoku_gueltig = true;

	bool numbers[10] = { false };
	int temp[9][9] = { 0 };

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
	//Richtige Ausgabe

	//Kontrolle der Zahlen
	//Reihe

	for (int y = 0; y < 9; y++)
	{
		for (int x = 0; x < 9; x++)
		{			
			if (pruefe_reihe(x, y, sudoku, 9) && numbers[sudoku[x][y]] == false) {

				std::cout << "Zeile " << y << ": Zahl " << sudoku[x][y] << " kommt mehrfach vor\n";
				numbers[sudoku[x][y]] = true;
				sudoku_gueltig = false;
			}

		}
		//teste wenn es gar nicht da ist hier :::
		for (int v = 1; v < 10; v++)
		{
				pruefe_reihe_vorhanden(y, 0, sudoku, v);
		}
		memset(numbers, false, 10);//test bool[] auf false setzen nach jeder Reihe
	}
	memset(numbers, false, 10);

	for (int x = 0; x < 9; x++)
	{
		for (int y = 0; y < 9; y++)
		{
			if (pruefe_spalte(x, y, sudoku, 9) && numbers[sudoku[x][y]] == false) {
				std::cout << "Spalte " << x << ": Zahl " << sudoku[x][y] << " kommt mehrfach vor\n";
				numbers[sudoku[x][y]] = true;
				sudoku_gueltig = false;
			}
		}
		//teste wenn es gar nicht da ist hier :::
		for (int v = 1; v < 10; v++)
		{
			pruefe_spalte_vorhanden(0, x, sudoku, v);
		}
		memset(numbers, false, 10);//test bool[] auf false setzen nach jeder Reihe
	}
	memset(numbers, false, 10);//test bool[] auf false setzen nach jeder Reihe



	//BLOCK

	int count = 0;
	for (int b = 0; b < 9; b++)
	{
		for (int bx = b / 3 * 3; bx <= b / 3 * 3 + 2; bx++)
		{
			for (int by = (b % 3 * 3); by <= (b % 3 * 3 + 2); by++)
			{
				temp[b][count] = sudoku[by][bx];
				//std::cout << " BLOCK " <<  by << " ** " << bx << std::endl;
				count++;
			}
			
		}
		count = 0;

	}
	/*
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			std::cout << temp[i][j];// << std::endl;
		}
		std::cout << std::endl;
	}*/


	//pruefe Block
	for (int block = 0; block < 9; block++)
	{
		for (int x = 0; x < 9; x++)
		{
			if (pruefe_spalte(block, x, temp, 9) && numbers[temp[block][x]] == false) {
				std::cout<<"Block " << block << ": Zahl " << temp[block][x] << " kommt mehrfach vor.\n";
				numbers[temp[block][x]] = true;
				sudoku_gueltig = false;
			}
		}
		for (int v = 1; v < 10; v++)
		{
			pruefe_block_vorhanden(block,0,temp,v,block);
		}
		memset(numbers, false, 10);//test bool[] auf false setzen nach jeder Reihe
	}
	memset(numbers, false, 10);//test bool[] auf false setzen nach jeder Reihe


	if (sudoku_gueltig == true) {
		std::cout << "Das Sudoku ist gueltig.\n";
	}


	system("PAUSE");

}