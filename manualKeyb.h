#pragma once


bool checkwalkingarea(char** battleplace, int x, int y, char key, int size, char rotation = 'n') {
	bool check = true;
	if (key == 72) {  // up

		// up horizontal
		if (rotation == 'h') {
			for (int i = 0; i < size; i++)
			{
				if (battleplace[x - 1][y + i] != '.' && !((battleplace[x - 1][y + i] >= 48 && battleplace[x - 1][y + i] <= 57) || (battleplace[x - 1][y + i] >= 97 && battleplace[x - 1][y + i] <= 102))) check = false;
			}
		}
		// up vertical
		else {
			if (battleplace[x - size][y] != '.' && !((battleplace[x - size][y] >= 48 && battleplace[x - size][y] <= 57) || (battleplace[x - size][y] >= 97 && battleplace[x - size][y] <= 102))) check = false;
		}
	}
	else if (key == 75) { // left
		if (rotation == 'h') {
			if (battleplace[x][y - 1] != '.' && !((battleplace[x][y - 1] >= 48 && battleplace[x][y - 1] <= 57) || (battleplace[x][y - 1] >= 97 && battleplace[x][y - 1] <= 102))) check = false;
		}
		else {
			for (int i = 0; i < size; i++)
			{
				if (battleplace[x - i][y - 1] != '.' && !((battleplace[x - i][y - 1] >= 48 && battleplace[x - i][y - 1] <= 57) || (battleplace[x - i][y - 1] >= 97 && battleplace[x - i][y - 1] <= 102))) check = false;
			}
		}

	}
	else if (key == 77) { // right
		if (rotation == 'h') {
			if (battleplace[x][y + size] != '.' && !((battleplace[x][y + 1] >= 48 && battleplace[x][y + 1] <= 57) || (battleplace[x][y + 1] >= 97 && battleplace[x][y + 1] <= 102))) check = false;
		}
		else {
			for (int i = 0; i < size; i++)
			{
				if (battleplace[x - i][y + 1] != '.' && !((battleplace[x - i][y + 1] >= 48 && battleplace[x - i][y + 1] <= 57) || (battleplace[x - i][y + 1] >= 97 && battleplace[x - i][y + 1] <= 102))) check = false;
			}
		}
	}
	else if (key == 80) { // down
		// up horizontal
		if (rotation == 'h') {
			for (int i = 0; i < size; i++)
			{
				if (battleplace[x + 1][y + i] != '.' && !((battleplace[x + 1][y + i] >= 48 && battleplace[x + 1][y + i] <= 57) || (battleplace[x + 1][y + i] >= 97 && battleplace[x + 1][y + i] <= 102))) check = false;
			}
		}
		// up vertical
		else {
			if (battleplace[x + 1][y] != '.' && !((battleplace[x + 1][y] >= 48 && battleplace[x + 1][y] <= 57) || (battleplace[x + 1][y] >= 97 && battleplace[x + 1][y] <= 102))) check = false;
		}
	}
	return check;


}



void destroyermovement(char** battleplace) {
	int x, y;
	while (true) {
		x = 1 + rand() % (shiprow - 1);
		y = 1 + rand() % (shipcolumn - 1);
		if (battleplace[x][y] == '.') {
			battleplace[x][y] = 'D';
			showbattleplace(battleplace, shiprow, shipcolumn);
			break;
		}

	}



	char key;
	while (true) {
		key = _getch();
		if (key == 72) { // up
			if (x != 1) {
				if (checkwalkingarea(battleplace, x, y, key, DestroyerSize) == true) {
					battleplace[x][y] = '.';
					battleplace[--x][y] = 'D';
					showbattleplace(battleplace, shiprow, shipcolumn);
				}
				else cout << '\a';
			}
			else cout << '\a';
		}
		if (key == 75) { // left
			if (y != 1) {
				if (checkwalkingarea(battleplace, x, y, key, DestroyerSize) == true) {
					battleplace[x][y] = '.';
					battleplace[x][--y] = 'D';
					showbattleplace(battleplace, shiprow, shipcolumn);
				}
				else cout << '\a';

			}
			else cout << '\a';
		}
		if (key == 77) { // right
			if (y != (shipcolumn - 1)) {
				if (checkwalkingarea(battleplace, x, y, key, DestroyerSize) == true) {
					battleplace[x][y] = '.';
					battleplace[x][++y] = 'D';
					showbattleplace(battleplace, shiprow, shipcolumn);
				}
				else cout << '\a';

			}
			else cout << '\a';
		}
		if (key == 80) { // down
			if (x != (shiprow - 1)) {
				if (checkwalkingarea(battleplace, x, y, key, DestroyerSize) == true) {
					battleplace[x][y] = '.';
					battleplace[++x][y] = 'D';
					showbattleplace(battleplace, shiprow, shipcolumn);
				}
				else cout << '\a';
			}
			else cout << '\a';
		}
		if (key == '\r') {
			if (checksurronding(battleplace, 1, x, y) == true) {
				battleplace[x][y] = 'D';
				totalshipcountmanual--;
				dcount++;
				break;
			}
			else cout << '\a';

		}

	}

}



//--------------------------------------------------------------------------------------------------------





void submarinehorizontal(char** battleplace, char* submarine, int x = 0, int y = 0) {
	if (!callbacksubmarine && isplacedSubmarine) {
		while (true) {
			x = 1 + rand() % (shiprow - 1);
			y = 1 + rand() % (shipcolumn - 2);
			if (checkcollision(battleplace, SubMarineSize, rotationSubmarine, x, y) == true) {

				for (int i = 0; i < SubMarineSize; i++)
				{
					battleplace[x][y + i] = submarine[i];
				}
				showbattleplace(battleplace, shiprow, shipcolumn);
				break;
			}
		}


	}


	char key;
	while (true) {
		key = _getch();
		if (key == 72) { // up
			if (x != 1) { 
				if (checkwalkingarea(battleplace, x, y, key, SubMarineSize, rotationSubmarine) == true) {
					battleplace[x][y] = '.';
					battleplace[x][y + 1] = '.';
					x--;
					for (int i = 0; i < SubMarineSize; i++)
					{
						battleplace[x][y + i] = 'S';
					}
					showbattleplace(battleplace, shiprow, shipcolumn);
				}
				else cout << '\a';
			}
			else cout << '\a';
		}
		if (key == 75) { // left
			if (y != 1) {
				if (checkwalkingarea(battleplace, x, y, key, SubMarineSize, rotationSubmarine) == true) {
					battleplace[x][y + SubMarineSize - 1] = '.';
					y--;
					for (int i = 0; i < SubMarineSize; i++)
					{
						battleplace[x][y + i] = 'S';
					}
					showbattleplace(battleplace, shiprow, shipcolumn);
				}
				else cout << '\a';

			}
			else cout << '\a';

		}
		if (key == 77) { // right
			if (y + SubMarineSize != shipcolumn) {
				if (checkwalkingarea(battleplace, x, y, key, SubMarineSize, rotationSubmarine) == true) {
					battleplace[x][y] = '.';
					y++;
					for (int i = 0; i < SubMarineSize; i++)
					{
						battleplace[x][y + i] = 'S';
					}
					showbattleplace(battleplace, shiprow, shipcolumn);
				}
				else cout << '\a';
			}
			else cout << '\a';

		}
		if (key == 80) { // down
			if (x != (shiprow - 1)) {
				if (checkwalkingarea(battleplace, x, y, key, SubMarineSize, rotationSubmarine) == true) {
					battleplace[x][y] = '.';
					battleplace[x][y + 1] = '.';
					x++;
					for (int i = 0; i < SubMarineSize; i++)
					{
						battleplace[x][y + i] = 'S';
					}
					showbattleplace(battleplace, shiprow, shipcolumn);
				}
				else cout << '\a';
			}
			else cout << '\a';

		}
		if (key == 114 || key == 32) { // horizontaldan verticala
			if (x != shiprow - 1) {
				if (battleplace[x + 1][y] == '.') {
					battleplace[x][y + 1] = '.';
					battleplace[x + 1][y] = 'S';
					lastxsubmarine = x + 1;
					lastysubmarine = y;
					showbattleplace(battleplace, shiprow, shipcolumn);
					rotationSubmarine = 'v';
					break;
				}
				else cout << '\a';
			}
			else cout << '\a';


		}
		if (key == '\r') {
			if (checksurronding(battleplace, SubMarineSize, x, y, rotationSubmarine) == true) {
				for (int i = 0; i < SubMarineSize; i++)
				{
					battleplace[x][y + i] = 'S';
				}
				totalshipcountmanual--;
				scount++;
				callbacksubmarine = false;
				isplacedSubmarine = false;
				break;
			}
			else cout << '\a';
		}

	}
}


void submarinevertical(char** battleplace, char* submarine, int x, int y) {


	char key;
	while (true) {
		key = _getch();
		if (key == 72) { // up
			if (x - SubMarineSize + 1 != 1) {
				if (checkwalkingarea(battleplace, x, y, key, SubMarineSize, rotationSubmarine) == true) {
					battleplace[x][y] = '.';
					battleplace[x - 1][y] = '.';
					x--;
					for (int i = 0; i < SubMarineSize; i++)
					{
						battleplace[x - i][y] = 'S';
					}
					showbattleplace(battleplace, shiprow, shipcolumn);
				}
				else cout << '\a';

			}
			else cout << '\a';

		}
		if (key == 75) { // left
			if (y != 1) {
				if (checkwalkingarea(battleplace, x, y, key, SubMarineSize, rotationSubmarine) == true) {
					battleplace[x][y] = '.';
					battleplace[x - 1][y] = '.';
					y--;
					for (int i = 0; i < SubMarineSize; i++)
					{
						battleplace[x - i][y] = 'S';
					}
					showbattleplace(battleplace, shiprow, shipcolumn);
				}
				else cout << '\a';
			}
			else cout << '\a';

		}
		if (key == 77) { // right
			if (y != shipcolumn - 1) {
				if (checkwalkingarea(battleplace, x, y, key, SubMarineSize, rotationSubmarine) == true) {
					battleplace[x][y] = '.';
					battleplace[x - 1][y] = '.';
					y++;
					for (int i = 0; i < SubMarineSize; i++)
					{
						battleplace[x - i][y] = 'S';
					}
					showbattleplace(battleplace, shiprow, shipcolumn);
				}
				else cout << '\a';
			}
			else cout << '\a';

		}
		if (key == 80) { // down
			if (x != shiprow - 1) {
				if (checkwalkingarea(battleplace, x, y, key, SubMarineSize, rotationSubmarine) == true) {
					battleplace[x][y] = '.';
					battleplace[x - 1][y] = '.';
					x++;
					for (int i = 0; i < SubMarineSize; i++)
					{
						battleplace[x - i][y] = 'S';
					}
					showbattleplace(battleplace, shiprow, shipcolumn);
				}
				else cout << '\a';
			}
			else cout << '\a';

		}
		if (key == 114 || key == 32) { // verticaldan horizontala
			if (y != shipcolumn - 1) {
				if (battleplace[x - 1][y + 1] == '.') {
					battleplace[x][y] = '.';
					battleplace[x - 1][y + 1] = 'S';
					lastxsubmarine = x - 1;
					lastysubmarine = y;
					showbattleplace(battleplace, shiprow, shipcolumn);
					callbacksubmarine = true;
					rotationSubmarine = 'h';
					break;
				}
				else cout << '\a';
			}
			else cout << '\a';

		}
		if (key == '\r') {
			if (checksurronding(battleplace, SubMarineSize, x, y, rotationSubmarine) == true) {
				for (int i = 0; i < SubMarineSize; i++)
				{
					battleplace[x - i][y] = 'S';
				}
				totalshipcountmanual--;
				scount++;
				callbacksubmarine = false;
				isplacedSubmarine = false;
				rotationSubmarine = 'h';
				break;
			}
			else cout << '\a';
		}

	}
}


void submarinemovement(char** battleplace, char* submarine) {
	while (isplacedSubmarine) {
		if (rotationSubmarine == 'h') {
			submarinehorizontal(battleplace, submarine, lastxsubmarine, lastysubmarine);
		}
		else {
			submarinevertical(battleplace, submarine, lastxsubmarine, lastysubmarine);
		}
	}

}


// -------------------------------------------------------------------------------------------------------------

//                           battleship



void battleshiphorizontal(char** battleplace, char* battleship, int x, int y) {
	if (!callbackbattleship && isplacedBattleship) {
		while (true) {
			x = 1 + rand() % (shiprow - 1);
			y = 1 + rand() % (shipcolumn - 3);

			if (checkcollision(battleplace, BattleShipSize, rotationBattleship, x, y) == true) {
				for (int i = 0; i < BattleShipSize; i++)
				{
					battleplace[x][y + i] = battleship[i];
				}
				showbattleplace(battleplace, shiprow, shipcolumn);
				break;
			}
		}



	}

	char key;
	while (true) {
		key = _getch();
		if (key == 72) { // up
			if (x != 1) { // check collision  and check surrounding
				if (checkwalkingarea(battleplace, x, y, key, BattleShipSize, rotationBattleship) == true) {
					battleplace[x][y] = '.';
					battleplace[x][y + 1] = '.';
					battleplace[x][y + 2] = '.';
					x--;
					for (int i = 0; i < BattleShipSize; i++)
					{
						battleplace[x][y + i] = 'B';
					}
					showbattleplace(battleplace, shiprow, shipcolumn);
				}
				else cout << '\a';
			}
			else cout << '\a';

		}
		if (key == 75) { // left
			if (y != 1) {
				if (checkwalkingarea(battleplace, x, y, key, BattleShipSize, rotationBattleship) == true) {
					battleplace[x][y + BattleShipSize - 1] = '.';
					y--;
					for (int i = 0; i < BattleShipSize; i++)
					{
						battleplace[x][y + i] = 'B';
					}
					showbattleplace(battleplace, shiprow, shipcolumn);
				}
				else cout << '\a';
			}
			else cout << '\a';

		}
		if (key == 77) { // right
			if (y + BattleShipSize != shipcolumn) {
				if (checkwalkingarea(battleplace, x, y, key, BattleShipSize, rotationBattleship) == true) {
					battleplace[x][y] = '.';
					y++;
					for (int i = 0; i < BattleShipSize; i++)
					{
						battleplace[x][y + i] = 'B';
					}
					showbattleplace(battleplace, shiprow, shipcolumn);
				}
				else cout << '\a';
			}
			else cout << '\a';

		}
		if (key == 80) { // down
			if (x != (shiprow - 1)) {
				if (checkwalkingarea(battleplace, x, y, key, BattleShipSize, rotationBattleship) == true) {
					battleplace[x][y] = '.';
					battleplace[x][y + 1] = '.';
					battleplace[x][y + 2] = '.';
					x++;
					for (int i = 0; i < BattleShipSize; i++)
					{
						battleplace[x][y + i] = 'B';
					}
					showbattleplace(battleplace, shiprow, shipcolumn);
				}
				else cout << '\a';
			}
			else cout << '\a';

		}
		if (key == 114 || key == 32) { // horizontaldan verticala
			if (x < shiprow - 2) {
				if (battleplace[x + 1][y] == '.' && battleplace[x + 2][y] == '.') {
					battleplace[x][y + 1] = '.';
					battleplace[x][y + 2] = '.';
					battleplace[x + 1][y] = 'B';
					battleplace[x + 2][y] = 'B';
					lastxbattleship = x + 2;
					lastybattleship = y;
					showbattleplace(battleplace, shiprow, shipcolumn);
					rotationBattleship = 'v';
					break;
				}
				else cout << '\a';
			}
			else cout << '\a';

		}
		if (key == '\r') {
			if (checksurronding(battleplace, BattleShipSize, x, y, rotationBattleship) == true) {

				for (int i = 0; i < BattleShipSize; i++)
				{
					battleplace[x][y + i] = 'B';
				}
				totalshipcountmanual--;
				bcount++;
				callbackbattleship = false;
				isplacedBattleship = false;
				break;
			}
			else cout << '\a';
		}
	}


}




void battleshipvertical(char** battleplace, int x, int y) {
	char key;
	while (true) {
		key = _getch();
		if (key == 72) { // up
			if (x - BattleShipSize + 1 != 1) { // check collision  and check surrounding
				if (checkwalkingarea(battleplace, x, y, key, BattleShipSize, rotationBattleship) == true) {
					battleplace[x][y] = '.';
					battleplace[x - 1][y] = '.';
					battleplace[x - 2][y] = '.';
					x--;
					for (int i = 0; i < BattleShipSize; i++)
					{
						battleplace[x - i][y] = 'B';
					}
					showbattleplace(battleplace, shiprow, shipcolumn);
				}
				else cout << '\a';
			}
			else cout << '\a';

		}
		if (key == 75) { // left
			if (y != 1) {
				if (checkwalkingarea(battleplace, x, y, key, BattleShipSize, rotationBattleship) == true) {
					battleplace[x][y] = '.';
					battleplace[x - 1][y] = '.';
					battleplace[x - 2][y] = '.';
					y--;
					for (int i = 0; i < BattleShipSize; i++)
					{
						battleplace[x - i][y] = 'B';
					}
					showbattleplace(battleplace, shiprow, shipcolumn);
				}
				else cout << '\a';
			}
			else cout << '\a';

		}
		if (key == 77) { // right
			if (y != shipcolumn - 1) {
				if (checkwalkingarea(battleplace, x, y, key, BattleShipSize, rotationBattleship) == true) {
					battleplace[x][y] = '.';
					battleplace[x - 1][y] = '.';
					battleplace[x - 2][y] = '.';
					y++;
					for (int i = 0; i < BattleShipSize; i++)
					{
						battleplace[x - i][y] = 'B';
					}
					showbattleplace(battleplace, shiprow, shipcolumn);
				}
				else cout << '\a';
			}
			else cout << '\a';

		}
		if (key == 80) { // down
			if (x != shiprow - 1) {
				if (checkwalkingarea(battleplace, x, y, key, BattleShipSize, rotationBattleship) == true) {
					battleplace[x][y] = '.';
					battleplace[x - 1][y] = '.';
					battleplace[x - 2][y] = '.';
					x++;
					for (int i = 0; i < BattleShipSize; i++)
					{
						battleplace[x - i][y] = 'B';
					}
					showbattleplace(battleplace, shiprow, shipcolumn);
				}
				else cout << '\a';
			}
			else cout << '\a';

		}
		if (key == 114 || key == 32) { // verticaldan horizontala
			if (y < shipcolumn - 2) {
				if (battleplace[x - 2][y + 1] == '.' && battleplace[x - 2][y + 2] == '.') {
					battleplace[x][y] = '.';
					battleplace[x - 1][y] = '.';
					battleplace[x - 2][y + 1] = 'B';
					battleplace[x - 2][y + 2] = 'B';
					lastxbattleship = x - 2;
					lastybattleship = y;
					showbattleplace(battleplace, shiprow, shipcolumn);
					callbackbattleship = true;
					rotationBattleship = 'h';
					break;
				}
				else cout << '\a';
			}
			else cout << '\a';

		}
		if (key == '\r') {
			if (checksurronding(battleplace, BattleShipSize, x, y, rotationBattleship) == true) {
				for (int i = 0; i < BattleShipSize; i++)
				{
					battleplace[x - i][y] = 'B';
				}
				totalshipcountmanual--;
				bcount++;
				callbackbattleship = false;
				isplacedBattleship = false;
				rotationBattleship = 'h';
				break;
			}
			else cout << '\a';
		}

	}
}













void battleshipmovement(char** battleplace, char* battleship) {
	while (isplacedBattleship) {
		if (rotationBattleship == 'h') {
			battleshiphorizontal(battleplace, battleship, lastxbattleship, lastybattleship);
		}
		else {
			battleshipvertical(battleplace, lastxbattleship, lastybattleship);
		}
	}
}





// -------------------------------------------------------------------------------------------------------------

				// carrier

void carrierhorizontal(char** battleplace, char* carrier, int x, int y) {
	if (!callbackcarrier && isplacedCarrier) {
		while (true) {
			x = 1 + rand() % (shiprow - 1);
			y = 1 + rand() % (shipcolumn - 4);

			if (checkcollision(battleplace, CarrierSize, rotationCarrier, x, y) == true) {
				for (int i = 0; i < CarrierSize; i++)
				{
					battleplace[x][y + i] = carrier[i];
				}
				showbattleplace(battleplace, shiprow, shipcolumn);
				break;
			}
		}


	}
	char key;
	while (true) {
		key = _getch();
		if (key == 72) { // up
			if (x != 1) { // check collision  and check surrounding
				if (checkwalkingarea(battleplace, x, y, key, CarrierSize, rotationCarrier) == true) {
					battleplace[x][y] = '.';
					battleplace[x][y + 1] = '.';
					battleplace[x][y + 2] = '.';
					battleplace[x][y + 3] = '.';
					x--;
					for (int i = 0; i < CarrierSize; i++)
					{
						battleplace[x][y + i] = 'C';
					}
					showbattleplace(battleplace, shiprow, shipcolumn);
				}
				else cout << '\a';
			}
			else cout << '\a';

		}
		if (key == 75) { // left
			if (y != 1) {
				if (checkwalkingarea(battleplace, x, y, key, CarrierSize, rotationCarrier) == true) {
					battleplace[x][y + CarrierSize - 1] = '.';
					y--;
					for (int i = 0; i < CarrierSize; i++)
					{
						battleplace[x][y + i] = 'C';
					}
					showbattleplace(battleplace, shiprow, shipcolumn);
				}
				else cout << '\a';
			}
			else cout << '\a';

		}
		if (key == 77) { // right
			if (y + CarrierSize != shipcolumn) {
				if (checkwalkingarea(battleplace, x, y, key, CarrierSize, rotationCarrier) == true) {
					battleplace[x][y] = '.';
					y++;
					for (int i = 0; i < CarrierSize; i++)
					{
						battleplace[x][y + i] = 'C';
					}
					showbattleplace(battleplace, shiprow, shipcolumn);
				}
				else cout << '\a';
			}
			else cout << '\a';

		}
		if (key == 80) { // down
			if (x != (shiprow - 1)) {
				if (checkwalkingarea(battleplace, x, y, key, CarrierSize, rotationCarrier) == true) {
					battleplace[x][y] = '.';
					battleplace[x][y + 1] = '.';
					battleplace[x][y + 2] = '.';
					battleplace[x][y + 3] = '.';
					x++;
					for (int i = 0; i < CarrierSize; i++)
					{
						battleplace[x][y + i] = 'C';
					}
					showbattleplace(battleplace, shiprow, shipcolumn);
				}
				else cout << '\a';
			}
			else cout << '\a';

		}
		if (key == 114 || key == 32) { // horizontaldan verticala
			if (x < shiprow - 3) {
				if (battleplace[x + 1][y] == '.' && battleplace[x + 2][y] == '.' && battleplace[x + 3][y] == '.') {
					battleplace[x][y + 1] = '.';
					battleplace[x][y + 2] = '.';
					battleplace[x][y + 3] = '.';
					battleplace[x + 1][y] = 'C';
					battleplace[x + 2][y] = 'C';
					battleplace[x + 3][y] = 'C';
					lastxcarrier = x + 3;
					lastycarrier = y;
					showbattleplace(battleplace, shiprow, shipcolumn);
					rotationCarrier = 'v';
					break;
				}
				else cout << '\a';
			}
			else cout << '\a';


		}
		if (key == '\r') {
			if (checksurronding(battleplace, CarrierSize, x, y, rotationCarrier) == true) {
				for (int i = 0; i < CarrierSize; i++)
				{
					battleplace[x][y + i] = 'C';
				}

				totalshipcountmanual--;
				ccount++;
				callbackcarrier = false;
				isplacedCarrier = false;
				break;
			}
			else cout << '\a';
		}

	}

}



void carriervertical(char** battleplace, char* carrier, int x, int y) {
	char key;
	while (true) {
		key = _getch();
		if (key == 72) { // up
			if (x - CarrierSize + 1 != 1) { // check collision  and check surrounding
				if (checkwalkingarea(battleplace, x, y, key, CarrierSize, rotationCarrier)) {
					battleplace[x][y] = '.';
					battleplace[x - 1][y] = '.';
					battleplace[x - 2][y] = '.';
					battleplace[x - 3][y] = '.';
					x--;
					for (int i = 0; i < CarrierSize; i++)
					{
						battleplace[x - i][y] = 'C';
					}
					showbattleplace(battleplace, shiprow, shipcolumn);
				}
				else cout << '\a';
			}
			else cout << '\a';

		}
		if (key == 75) { // left
			if (y != 1) {
				if (checkwalkingarea(battleplace, x, y, key, CarrierSize, rotationCarrier) == true) {
					battleplace[x][y] = '.';
					battleplace[x - 1][y] = '.';
					battleplace[x - 2][y] = '.';
					battleplace[x - 3][y] = '.';
					y--;
					for (int i = 0; i < CarrierSize; i++)
					{
						battleplace[x - i][y] = 'C';
					}
					showbattleplace(battleplace, shiprow, shipcolumn);
				}
				else cout << '\a';
			}
			else cout << '\a';

		}
		if (key == 77) { // right
			if (y != shipcolumn - 1) {
				if (checkwalkingarea(battleplace, x, y, key, CarrierSize, rotationCarrier) == true) {
					battleplace[x][y] = '.';
					battleplace[x - 1][y] = '.';
					battleplace[x - 2][y] = '.';
					battleplace[x - 3][y] = '.';
					y++;
					for (int i = 0; i < CarrierSize; i++)
					{
						battleplace[x - i][y] = 'C';
					}
					showbattleplace(battleplace, shiprow, shipcolumn);
				}
				else cout << '\a';
			}
			else cout << '\a';

		}
		if (key == 80) { // down
			if (x != shiprow - 1) {
				if (checkwalkingarea(battleplace, x, y, key, CarrierSize, rotationCarrier) == true) {
					battleplace[x][y] = '.';
					battleplace[x - 1][y] = '.';
					battleplace[x - 2][y] = '.';
					battleplace[x - 3][y] = '.';
					x++;
					for (int i = 0; i < CarrierSize; i++)
					{
						battleplace[x - i][y] = 'C';
					}
					showbattleplace(battleplace, shiprow, shipcolumn);
				}
				else cout << '\a';
			}
			else cout << '\a';

		}
		if (key == 114 || key == 32) { // verticaldan horizontala
			if (y < shipcolumn - 3) {
				if (battleplace[x - 3][y + 1] == '.' && battleplace[x - 3][y + 2] == '.' && battleplace[x - 3][y + 3] == '.') {
					battleplace[x][y] = '.';
					battleplace[x - 1][y] = '.';
					battleplace[x - 2][y] = '.';
					battleplace[x - 3][y + 1] = 'C';
					battleplace[x - 3][y + 2] = 'C';
					battleplace[x - 3][y + 3] = 'C';
					lastxcarrier = x - 3;
					lastycarrier = y;
					showbattleplace(battleplace, shiprow, shipcolumn);
					callbackcarrier = true;
					rotationCarrier = 'h';
					break;
				}
				else cout << '\a';
			}
			else cout << '\a';

		}
		if (key == '\r') {
			if (checksurronding(battleplace, CarrierSize, x, y, rotationCarrier) == true) {
				for (int i = 0; i < CarrierSize; i++)
				{
					battleplace[x - i][y] = 'C';
				}

				totalshipcountmanual--;
				ccount++;
				callbackcarrier = false;
				isplacedCarrier = false;
				rotationCarrier = 'h';
				break;
			}
			else cout << '\a';
		}

	}
}



void carriermovement(char** battleplace, char* carrier) {
	while (isplacedCarrier) {
		if (rotationCarrier == 'h') {
			carrierhorizontal(battleplace, carrier, lastxcarrier, lastycarrier);
		}
		else {
			carriervertical(battleplace, carrier, lastxcarrier, lastycarrier);

		}
	}
}
