#pragma once





void showbattleplaceBot(char** battleplace, int row, int column) {
	int index = 0;
	for (int i = 0; i < row; i++)
	{
		gotoxy(60, index++);

		for (int j = 0; j < column; j++)
		{

			if (battleplace[i][j] == 'M') {

				if (check2 == true && (i == targetx && j == targety)) {
					color(13);
					cout << battleplace[i][j] << " ";
				}
				else {
					
					color(12);
					cout << battleplace[i][j] << " ";
				}

			}
			else if (battleplace[i][j] == 'H') {
				if (check2 == true && (i == targetx && j == targety)) {
					color(13);
					cout << battleplace[i][j] << " ";
				}
				else {
					
					color(10);
					cout << battleplace[i][j] << " ";
				}
			}
			else if (battleplace[i][j] == 'K') {
				if (check2 == true && (i == targetx && j == targety)) {
					color(13);
					cout << battleplace[i][j] << " ";
				}
				else {
					color(14);
					cout << battleplace[i][j] << " ";
				}

			}
			else if (battleplace[i][j] == assistSymbol) {
				if (check2 == true && (i == targetx && j == targety)) {
					color(13);
					cout << battleplace[i][j] << " ";
				}
				else {
					color(9);
					cout << battleplace[i][j] << " ";
				}
			}
			else {
				color(7);
				cout << battleplace[i][j] << " ";
			}
		}


		cout << endl;
	}
	color(7);
	gotoxy(70, index + 1);
	cout << "Enemy Place " << endl;
	gotoxy(66, index + 2);
	cout <<"Remaining ships: " << setw(4) << remainingshipsBot << endl;
}


void placeDestroyerBot(char** battleplace) {
	int destroyerBotcount = 0;

	while (destroyerBotcount != 4) {
		int xfordestroyerBot = 1 + rand() % (shiprow - 1);
		int yfordestroyerBot = 1 + rand() % (shipcolumn - 1);
		if (battleplace[xfordestroyerBot][yfordestroyerBot] == '.' && checksurronding(battleplace, 1, xfordestroyerBot, yfordestroyerBot) == true) {
			destroyerBotcount++;
			battleplace[xfordestroyerBot][yfordestroyerBot] = 'D';
		}
	}
}


void placeSubMarineBot(char** battleplace) {
	int SubMarinecountBot = 0;
	char rotationarr[2] = { 'h','v' };
	while (SubMarinecountBot != 3) {
		int randomrotation = rand() % 2;
		if (randomrotation == 0) { // horizontal
			int xforSubMarineBot = 1 + rand() % (shiprow - 1);
			int yforSubMarineBot = 1 + rand() % (shipcolumn - 2);
			if (checkcollision(battleplace, 2, rotationarr[randomrotation], xforSubMarineBot, yforSubMarineBot) == true && checksurronding(battleplace, 2, xforSubMarineBot, yforSubMarineBot, rotationarr[randomrotation]) == true) {
				for (int i = 0; i < 2; i++)
				{

					battleplace[xforSubMarineBot][yforSubMarineBot + i] = 'S';
				}
				SubMarinecountBot++;
			}
		}
		else if (randomrotation == 1) { // vertical
			int xforSubMarineBot = 2 + rand() % (shiprow - 2);
			int yforSubMarineBot = 1 + rand() % (shipcolumn - 1);
			if (checkcollision(battleplace, 2, rotationarr[randomrotation], xforSubMarineBot, yforSubMarineBot) == true && checksurronding(battleplace, 2, xforSubMarineBot, yforSubMarineBot, rotationarr[randomrotation]) == true) {
				for (int i = 0; i < 2; i++)
				{

					battleplace[xforSubMarineBot - i][yforSubMarineBot] = 'S';
				}
				SubMarinecountBot++;
			}
		}



	}
}


void placeBattleshipBot(char** battleplace) {
	int BattleshipcountBot = 0;
	char rotationarr[2] = { 'h','v' };
	while (BattleshipcountBot != 2) {
		int randomrotation = rand() % 2;
		if (randomrotation == 0) { // horizontal
			int xforBattleshipBot = 1 + rand() % (shiprow - 1);
			int yforBattleshipBot = 1 + rand() % (shipcolumn - 3);
			if (checkcollision(battleplace, 3, rotationarr[randomrotation], xforBattleshipBot, yforBattleshipBot) == true && checksurronding(battleplace, 3, xforBattleshipBot, yforBattleshipBot, rotationarr[randomrotation]) == true) {
				for (int i = 0; i < 3; i++)
				{

					battleplace[xforBattleshipBot][yforBattleshipBot + i] = 'B';
				}
				BattleshipcountBot++;
			}
		}
		else if (randomrotation == 1) { // vertical
			int xforBattleshipBot = 3 + rand() % (shiprow - 3);
			int yforBattleshipBot = 1 + rand() % (shipcolumn - 1);
			if (checkcollision(battleplace, 3, rotationarr[randomrotation], xforBattleshipBot, yforBattleshipBot) == true && checksurronding(battleplace, 3, xforBattleshipBot, yforBattleshipBot, rotationarr[randomrotation]) == true) {
				for (int i = 0; i < 3; i++)
				{

					battleplace[xforBattleshipBot - i][yforBattleshipBot] = 'B';
				}
				BattleshipcountBot++;
			}
		}



	}
}


void placeCarrierBot(char** battleplace) {
	int CarriercountBot = 0;
	char rotationarr[2] = { 'h','v' };
	while (CarriercountBot != 1) {
		int randomrotation = rand() % 2;
		if (randomrotation == 0) { // horizontal
			int xforCarrierBot = 1 + rand() % (shiprow - 1);
			int yforCarrierBot = 1 + rand() % (shipcolumn - 4);
			if (checkcollision(battleplace, 4, rotationarr[randomrotation], xforCarrierBot, yforCarrierBot) == true && checksurronding(battleplace, 4, xforCarrierBot, yforCarrierBot, rotationarr[randomrotation]) == true) {
				for (int i = 0; i < 4; i++)
				{

					battleplace[xforCarrierBot][yforCarrierBot + i] = 'C';
				}
				CarriercountBot++;
			}
		}
		else if (randomrotation == 1) { // vertical
			int xforCarrierBot = 4 + rand() % (shiprow - 4);
			int yforCarrierBot = 1 + rand() % (shipcolumn - 1);
			if (checkcollision(battleplace, 4, rotationarr[randomrotation], xforCarrierBot, yforCarrierBot) == true && checksurronding(battleplace, 4, xforCarrierBot, yforCarrierBot, rotationarr[randomrotation]) == true) {
				for (int i = 0; i < 4; i++)
				{

					battleplace[xforCarrierBot - i][yforCarrierBot] = 'C';
				}
				CarriercountBot++;
			}
		}



	}
}







void placetheshipsforBot(char** battleplace) {
	placeDestroyerBot(battleplace);
	placeSubMarineBot(battleplace);
	placeBattleshipBot(battleplace);
	placeCarrierBot(battleplace);
}















