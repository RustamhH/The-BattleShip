#pragma once

char** createbattleplace(int row, int column) {
	char** battleplace = new char* [row];
	for (int i = 0; i < row; i++)
	{
		battleplace[i] = new char[column];
	}

	system("cls");
	int reqemsaquli = 49;
	int reqemufuqi = 48;
	for (int i = 0; i < row; i++)
	{
		if (i == 10) reqemsaquli = 97;

		for (int j = 0; j < column; j++)
		{
			if (j == 10) reqemufuqi = 97;

			if (i == 0) battleplace[i][j] = reqemufuqi++;
			else if (j == 0) battleplace[i][j] = reqemsaquli++;
			else battleplace[i][j] = '.';
		}
	}

	return battleplace;
}






void showbattleplace(char** battleplace, int row, int column) {
	system("cls");
	for (int i = 0; i < row; i++)
	{

		for (int j = 0; j < column; j++)
		{
			if (battleplace[i][j] == 'M') {
				color(12);
				cout << battleplace[i][j] << " ";
			}
			else if (battleplace[i][j] == 'H') {
				color(10);
				cout << battleplace[i][j] << " ";
			}
			else if (battleplace[i][j] == 'K') {
				color(14);
				cout << battleplace[i][j] << " ";
			}
			else {
				color(7);
				cout << battleplace[i][j] << " ";
			}
		}
		cout << endl;
	}
	color(7);
	if (a == true) {
		cout << "\n\tYour Place\n";
		cout << "    Remaining ships: " << remainingshipsPerson;
	}


}







inline void printshipplacechoice() {
	cout << "What ship would you like to place? --> \nDestroyer(press 1)\nSubMarine(press 2)\nBattleship(press 3)\nCarrier(press 4)\n";
}


bool checkcollision(char** battleplace, int size, char rotation, int row, int column) {
	int index = 0;
	bool check = true;
	if (rotation == 'h') {
		for (int i = 0; i < size; i++)
		{
			if (battleplace[row][column + index] != '.' && !(battleplace[row][column + index] >= 48 && battleplace[row][column + index] <= 57 || battleplace[row][column + index] >= 97 && battleplace[row][column + index] <= 102)) check = false;
			index++;
		}
	}
	else if (rotation == 'v') {
		for (int j = 0; j < size; j++)
		{
			if (battleplace[row - index][column] != '.' && !(battleplace[row - index][column] >= 48 && battleplace[row - index][column] <= 57 || battleplace[row - index][column] >= 97 && battleplace[row - index][column] <= 102)) check = false;
			index++;
		}

	}
	return check;
}



bool checksurronding(char** battleplace, int size, int row, int column, char rotation = 'n') {
	bool check = true;
	int index = 0;
	if (rotation == 'h' || rotation == 'n') {
		for (int i = 0; i < size; i++)
		{
			if (battleplace[row - 1][column + index] != '.' && !(battleplace[row - 1][column + index] >= 48 && battleplace[row - 1][column + index] <= 57 || battleplace[row - 1][column + index] >= 97 && battleplace[row - 1][column + index] <= 102)) check = false;
			index++;
		}
		index = 0;
		for (int i = 0; i < size; i++)
		{
			if (row < shiprow - 1) if (battleplace[row + 1][column + index] != '.' && !(battleplace[row + 1][column + index] >= 48 && battleplace[row + 1][column + index] <= 57 || battleplace[row + 1][column + index] >= 97 && battleplace[row + 1][column + index] <= 102)) check = false;
			index++;
		}

		if (battleplace[row][column - 1] != '.' && !(battleplace[row][column - 1] >= 48 && battleplace[row][column - 1] <= 57 || battleplace[row][column - 1] >= 97 && battleplace[row][column - 1] <= 102)) check = false;
		if (column + size < shipcolumn) {
			if (battleplace[row][column + size] != '.' && !(battleplace[row][column + size] >= 48 && battleplace[row][column + size] <= 57 || (battleplace[row][column + size] >= 97 && battleplace[row][column + size] <= 102))) {
				check = false;
			}
		}
		if (battleplace[row - 1][column - 1] != '.' && !(battleplace[row - 1][column - 1] >= 48 && battleplace[row - 1][column - 1] <= 57 || battleplace[row - 1][column - 1] >= 97 && battleplace[row - 1][column - 1] <= 102)) check = false;

		if (row < shiprow - 1) if (battleplace[row + 1][column - 1] != '.' && !(battleplace[row + 1][column - 1] >= 48 && battleplace[row + 1][column - 1] <= 57 || battleplace[row + 1][column - 1] >= 97 && battleplace[row + 1][column - 1] <= 102)) check = false;
		if (column + size < shipcolumn) if (battleplace[row - 1][column + size] != '.' && !(battleplace[row - 1][column + size] >= 48 && battleplace[row - 1][column + size] <= 57 || battleplace[row - 1][column + size] >= 97 && battleplace[row - 1][column + size] <= 102)) check = false;

		if (row < shiprow - 1 && (column + size < shipcolumn))	if (battleplace[row + 1][column + size] != '.' && !(battleplace[row + 1][column + size] >= 48 && battleplace[row + 1][column + size] <= 57 || battleplace[row + 1][column + size] >= 97 && battleplace[row + 1][column + size] <= 102)) check = false;
	}
	else if (rotation == 'v') {
		for (int i = 0; i < size; i++)
		{
			if (column < shipcolumn - 1)  if (battleplace[row - index][column + 1] != '.' && !(battleplace[row - index][column + 1] >= 48 && battleplace[row - index][column + 1] <= 57 || battleplace[row - index][column + 1] >= 97 && battleplace[row - index][column + 1] <= 102)) check = false;
			index++;
		}
		index = 0;
		for (int i = 0; i < size; i++)
		{
			if (battleplace[row - index][column - 1] != '.' && !(battleplace[row - index][column - 1] >= 48 && battleplace[row - index][column - 1] <= 57 || battleplace[row - index][column - 1] >= 97 && battleplace[row - index][column - 1] <= 102)) check = false;
			index++;
		}
		if (row < shiprow - 1) if (battleplace[row + 1][column] != '.' && !(battleplace[row + 1][column] >= 48 && battleplace[row + 1][column] <= 57 || battleplace[row + 1][column] >= 97 && battleplace[row - 1][column] <= 102)) check = false;
		if (battleplace[row - size][column] != '.' && !(battleplace[row - size][column] >= 48 && battleplace[row - size][column] <= 57 || battleplace[row - size][column] >= 97 && battleplace[row - size][column] <= 102)) check = false;
		if (row < shiprow - 1) if (battleplace[row + 1][column - 1] != '.' && !(battleplace[row + 1][column - 1] >= 48 && battleplace[row + 1][column - 1] <= 57 || battleplace[row + 1][column - 1] >= 97 && battleplace[row + 1][column - 1] <= 102)) check = false;
		if (row < shiprow - 1 && (column < shipcolumn - 1)) if (battleplace[row + 1][column + 1] != '.' && !(battleplace[row + 1][column + 1] >= 48 && battleplace[row + 1][column + 1] <= 57 || battleplace[row + 1][column + 1] >= 97 && battleplace[row + 1][column + 1] <= 102)) check = false;

		if (battleplace[row - size][column - 1] != '.' && !(battleplace[row - size][column - 1] >= 48 && battleplace[row - size][column - 1] <= 57 || battleplace[row - size][column - 1] >= 97 && battleplace[row - size][column - 1] <= 102)) check = false;
		if (column < shipcolumn - 1) if (battleplace[row - size][column + 1] != '.' && !(battleplace[row - size][column + 1] >= 48 && battleplace[row - size][column + 1] <= 57 || battleplace[row - size][column + 1] >= 97 && battleplace[row - size][column + 1] <= 102)) check = false;
	}
	return check;
}





void placeDestroyer(char** battleplace, int row, int column) {
	int xfordestroyer, yfordestroyer;
	int destroyercount = 0;
	while (destroyercount != 4) {
		
		
		bool bad = false;

		do {
			cout << "Great! Now , choose the coordinates of Destroyer(x/y)";
			cin >> xfordestroyer>>yfordestroyer;
			

			bad = cin.fail(); // if user enters char instead of int , it will stop the program from run-time error 
			if (bad)
				cout << '\a';
			cin.clear();
			cin.ignore(10, '\n');
		} while (bad);


		if ((xfordestroyer > 0 && xfordestroyer < row) && (yfordestroyer > 0 && yfordestroyer < column) && battleplace[xfordestroyer][yfordestroyer] == '.' && checksurronding(battleplace, 1, xfordestroyer, yfordestroyer) == true) {
			destroyercount++;
			battleplace[xfordestroyer][yfordestroyer] = 'D';
			showbattleplace(battleplace, row, column);
		}
		else cout << '\a';
		
	}
	isDestroyerplaced = false;
}

void placeSubMarine(char** battleplace, int row, int column) {
	int SubMarinecount = 0;
	int xforSubMarine, yforSubMarine;


	while (SubMarinecount != 3) {
		char rotationSubMarine;
		cout << "\nWhich side would you like to place , horizontal(press h) or vertical(press v) ? ";
		rotationSubMarine = _getch();

		if (rotationSubMarine == 'h' || rotationSubMarine == 'H') {
			bool bad = false;

			do {
				cout << "\nGreat! Now , choose the coordinates of SubMarine(x/y)";
				cin >> xforSubMarine >> yforSubMarine;


				bad = cin.fail(); // if user enters char instead of int , it will stop the program from run-time error 
				if (bad)
					cout << '\a';
				cin.clear();
				cin.ignore(10, '\n');
			} while (bad);

			if ((xforSubMarine > 0 && xforSubMarine < row) && (yforSubMarine > 0 && yforSubMarine < column) && yforSubMarine + 1 < column && checkcollision(battleplace, 2, 'h', xforSubMarine, yforSubMarine) == true && checksurronding(battleplace, 2, xforSubMarine, yforSubMarine, 'h') == true) {
				for (int i = 0; i < 2; i++)
				{

					battleplace[xforSubMarine][yforSubMarine + i] = 'S';
					showbattleplace(battleplace, row, column);
				}
				SubMarinecount++;
			}
			else cout << '\a';
		}
		else if (rotationSubMarine == 'v' || rotationSubMarine == 'V') {
			bool bad = false;

			do {
				cout << "\nGreat! Now , choose the coordinates of SubMarine(x/y)";
				cin >> xforSubMarine >> yforSubMarine;


				bad = cin.fail(); // if user enters char instead of int , it will stop the program from run-time error 
				if (bad)
					cout << '\a';
				cin.clear();
				cin.ignore(10, '\n');
			} while (bad);

			if ((xforSubMarine > 0 && xforSubMarine < row) && (yforSubMarine > 0 && yforSubMarine < column) && xforSubMarine - 1 > 0 && checkcollision(battleplace, 2, 'v', xforSubMarine, yforSubMarine) == true && checksurronding(battleplace, 2, xforSubMarine, yforSubMarine, 'v') == true) {
				for (int i = 0; i < 2; i++)
				{
					battleplace[xforSubMarine - i][yforSubMarine] = 'S';
					showbattleplace(battleplace, row, column);
				}
				SubMarinecount++;
			}
			else cout << '\a';
		}
	}
	isSubMarineplaced = false;
}

void placeBattleship(char** battleplace, int row, int column) {
	int BattleShipcount = 0;
	int xforBattleShip, yforBattleShip;

	while (BattleShipcount != 2) {
		char rotationBattleShip;
		cout << "\nWhich side would you like to place , horizontal(press h) or vertical(press v) ? ";
		rotationBattleShip = _getch();

		if (rotationBattleShip == 'h' || rotationBattleShip == 'H') {
			bool bad = false;

			do {
				cout << "\nGreat! Now , choose the coordinates of BattleShip(x/y)";
				cin >> xforBattleShip >> yforBattleShip;


				bad = cin.fail(); // if user enters char instead of int , it will stop the program from run-time error 
				if (bad)
					cout << '\a';
				cin.clear();
				cin.ignore(10, '\n');
			} while (bad);

			if ((xforBattleShip > 0 && xforBattleShip < row) && (yforBattleShip > 0 && yforBattleShip < column) && yforBattleShip + 2 < column && checkcollision(battleplace, 3, 'h', xforBattleShip, yforBattleShip) == true && checksurronding(battleplace, 3, xforBattleShip, yforBattleShip, 'h') == true) {
				for (int i = 0; i < 3; i++)
				{

					battleplace[xforBattleShip][yforBattleShip + i] = 'B';
					showbattleplace(battleplace, row, column);
				}
				BattleShipcount++;
			}
			else cout << '\a';
		}
		else if (rotationBattleShip == 'v' || rotationBattleShip == 'V') {
			bool bad = false;

			do {
				cout << "\nGreat! Now , choose the coordinates of BattleShip(x/y)";
				cin >> xforBattleShip >> yforBattleShip;


				bad = cin.fail(); // if user enters char instead of int , it will stop the program from run-time error 
				if (bad)
					cout << '\a';
				cin.clear();
				cin.ignore(10, '\n');
			} while (bad);

			if ((xforBattleShip > 0 && xforBattleShip < row) && (yforBattleShip > 0 && yforBattleShip < column) && xforBattleShip - 2 > 0 && checkcollision(battleplace, 3, 'v', xforBattleShip, yforBattleShip) == true && checksurronding(battleplace, 3, xforBattleShip, yforBattleShip, 'v') == true) {
				for (int i = 0; i < 3; i++)
				{
					battleplace[xforBattleShip - i][yforBattleShip] = 'B';
					showbattleplace(battleplace, row, column);
				}
				BattleShipcount++;
			}
			else cout << '\a';
		}
	}
	isBattleshipplaced = false;
}


void placeCarrier(char** battleplace, int row, int column) {
	int Carriercount = 0;
	int xforCarrier, yforCarrier;
	while (Carriercount != 1) {
		char rotationCarrier;
		cout << "\nWhich side would you like to place , horizontal(press h) or vertical(press v) ? ";
		rotationCarrier = _getch();

		if (rotationCarrier == 'h' || rotationCarrier == 'H') {
			bool bad = false;

			do {
				cout << "\nGreat! Now , choose the coordinates of Carrier(x/y)";
				cin >> xforCarrier >> yforCarrier;


				bad = cin.fail(); // if user enters char instead of int , it will stop the program from run-time error 
				if (bad)
					cout << '\a';
				cin.clear();
				cin.ignore(10, '\n');
			} while (bad);

			if ((xforCarrier > 0 && xforCarrier < row) && (yforCarrier > 0 && yforCarrier < column) && yforCarrier + 3 < column && checkcollision(battleplace, 4, 'h', xforCarrier, yforCarrier) == true && checksurronding(battleplace, 4, xforCarrier, yforCarrier, 'h') == true) {
				for (int i = 0; i < 4; i++)
				{

					battleplace[xforCarrier][yforCarrier + i] = 'C';
					showbattleplace(battleplace, row, column);
				}
				Carriercount++;
			}
			else cout << '\a';
		}
		else if (rotationCarrier == 'v' || rotationCarrier == 'V') {
			bool bad = false;

			do {
				cout << "\nGreat! Now , choose the coordinates of Carrier(x/y)";
				cin >> xforCarrier >> yforCarrier;


				bad = cin.fail(); // if user enters char instead of int , it will stop the program from run-time error 
				if (bad)
					cout << '\a';
				cin.clear();
				cin.ignore(10, '\n');
			} while (bad);

			if ((xforCarrier > 0 && xforCarrier < row) && (yforCarrier > 0 && yforCarrier < column) && xforCarrier - 3 > 0 && checkcollision(battleplace, 4, 'v', xforCarrier, yforCarrier) == true && checksurronding(battleplace, 4, xforCarrier, yforCarrier, 'v') == true) {
				for (int i = 0; i < 4; i++)
				{
					battleplace[xforCarrier - i][yforCarrier] = 'C';
					showbattleplace(battleplace, row, column);
				}
				Carriercount++;
			}
			else cout << '\a';
		}
	}
	isCarrierplaced = false;
}






void placetheships(char** battleplace, int row, int column) {
	while (true) {
		if (totalshipcount == 10) break;
		int placeshipchoice;
		printshipplacechoice();
		placeshipchoice = _getch();
		if (placeshipchoice == 49 && isDestroyerplaced) {
			placeDestroyer(battleplace, row, column);
			totalshipcount += 4;
		}
		if (placeshipchoice == 50 && isSubMarineplaced) {
			placeSubMarine(battleplace, row, column);
			totalshipcount += 3;
		}
		if (placeshipchoice == 51 && isBattleshipplaced) {
			placeBattleship(battleplace, row, column);
			totalshipcount += 2;
		}
		if (placeshipchoice == 52 && isCarrierplaced) {
			placeCarrier(battleplace, row, column);
			totalshipcount += 1;
		}
	}
	delay(50);
	system("cls");

}


