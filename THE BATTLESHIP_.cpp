#include <iostream>
#include <conio.h>
#include<time.h>
#include <windows.h>
#include <iomanip>
using namespace std;


bool checkifsymbolplaced = true;
bool a;
bool isDestroyerplaced = true;
bool isSubMarineplaced = true;
bool isBattleshipplaced = true;
bool isCarrierplaced = true;
bool check2;
bool hit = true;
bool assistmodeOn = true;


int dcount = 0, scount = 0, ccount = 0, bcount = 0;
int totalshipcountmanual = 10;

char rotationSubmarine = 'h';
char rotationBattleship = 'h';
char rotationCarrier = 'h';
char symbol = 207;
char assistSymbol = 126;



int lastxsubmarine, lastysubmarine;
int lastxbattleship, lastybattleship;
int lastxcarrier, lastycarrier;

bool callbacksubmarine;
bool callbackbattleship;
bool callbackcarrier;
bool isplacedSubmarine;
bool isplacedBattleship;
bool isplacedCarrier;

enum ShipSizes
{
	DestroyerSize = 1,
	SubMarineSize = 2,
	BattleShipSize = 3,
	CarrierSize = 4
};

char* submarine = new char[3] {"SS"};
char* battleship = new char[4] {"BBB"};
char* carrier = new char[5] {"CCCC"};


int playerturn;
int totalshipcount = 0;
int remainingshipsPerson = 10;
int remainingshipsBot = 10;
int shiprow = 14, shipcolumn = 14;
int targetx, targety;



void delay(clock_t a)
{
	clock_t start;
	start = clock();
	while (clock() - start < a)
	{

	}
}

#include "menus.h"
#include "placefunc.h"
#include "botplace.h"
#include "game_.h"
#include "manualKeyb.h"


void showGeneralbattleplace(char** battleplace, char** battleplacebot, char** originalbattleplacebot, int row, int column) {
	a = true;
	showbattleplace(battleplace, row, column);
	while (true) {

		if (remainingshipsBot == 0) {
			
			system("cls");
			logos();
			system("pause");
			exit(0);
		}
		else if (remainingshipsPerson == 0) {
			system("cls");
			logos();
			system("pause");
			exit(0);
		}

		if (playerturn == 0) {
			target(battleplacebot, originalbattleplacebot);
		}
		else if (playerturn == 1) {
			smartbot(battleplace);
		}
	}

}







int main() {
	

	srand(time(NULL));


	while (true) {
		printnameofgame();


		int counter = menu();
		color(7);
		if (counter == 1) { // starts new game

			system("cls");
			loading();
			char** battleplace = createbattleplace(shiprow, shipcolumn);
			char** battleplaceBot = createbattleplace(shiprow, shipcolumn);
			char** FakeBotplace = createbattleplace(shiprow, shipcolumn);
			int counterrandomormanual = randomormanualplace();
			if (counterrandomormanual == 0) {

				system("cls");
				int counterkeyboardorcoordinate = keyboardorcoordinate();
				if (counterkeyboardorcoordinate == 1) { // keyboard place
					system("cls");
					showbattleplace(battleplace, shiprow, shipcolumn);

					int counter;
					while (true) {

						if (totalshipcountmanual == 0) break;
						counter = ManualPlaceMenu();

						if (counter == 1 && dcount != 4) {
							destroyermovement(battleplace);
						}
						else if (counter == 2 && scount != 3) {
							isplacedSubmarine = true;
							submarinemovement(battleplace, submarine);
						}
						else if (counter == 3 && bcount != 2) {
							isplacedBattleship = true;
							battleshipmovement(battleplace, battleship);
						}
						else if (counter == 4 && ccount != 1) {
							isplacedCarrier = true;
							carriermovement(battleplace, carrier);
						}


					}
					system("cls");
				}
				else { // coordinate place
					showbattleplace(battleplace, shiprow, shipcolumn);
					placetheships(battleplace, shiprow, shipcolumn);
				}

			}
			else if (counterrandomormanual == 1) { // random place
				system("cls");
				placetheshipsforBot(battleplace);

			}
			int assistmodechoice = AssistModeOnorOff();
			if (assistmodechoice == 1) assistmodeOn = false;
			placetheshipsforBot(battleplaceBot);
			showGeneralbattleplace(battleplace, FakeBotplace, battleplaceBot, shiprow, shipcolumn);


		}
		else if (counter == 2) {
			system("cls");
			int counterAzorEng = azoreng();
			if (counterAzorEng == 0) {
				system("cls");
				color(7);
				rules();
				cout << "\nCixis etmek ucun istenilen duymeye basin ";
			}
			else if (counterAzorEng == 1) {
				system("cls");
				color(7);
				rulesEng();
				cout << "\nPress any button to exit";
			}
			int num = _getch();
			system("cls");
		}
		else exit(0);
	}
	





}