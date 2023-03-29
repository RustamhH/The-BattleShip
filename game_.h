#pragma once


void assistmode(char** battleplace, int size, int x, int y, char rotation = 'n') {
    if (rotation == 'h' || rotation == 'n') {
        for (int i = -1; i < size + 1; i++) {
            if(y+i<shipcolumn) if (!(battleplace[x - 1][y + i] >= 48 && battleplace[x - 1][y + i] <= 57 || battleplace[x - 1][y + i] >= 97 && battleplace[x - 1][y + i] <= 102)) battleplace[x - 1][y + i] = assistSymbol;
        };
        for (int i = -1; i < size + 1; i++) {
            if ((x < shiprow - 1) && y+i<shipcolumn) if (!(battleplace[x + 1][y + i] >= 48 && battleplace[x + 1][y + i] <= 57 || battleplace[x + 1][y + i] >= 97 && battleplace[x + 1][y + i] <= 102)) battleplace[x + 1][y + i] = assistSymbol; 
        };
        if (!(battleplace[x][y - 1] >= 48 && battleplace[x][y - 1] <= 57 || battleplace[x][y - 1] >= 97 && battleplace[x][y - 1] <= 102)) battleplace[x][y - 1] = assistSymbol;
        if (y + size < shipcolumn) if (!(battleplace[x][y + size] >= 48 && battleplace[x][y + size] <= 57 || battleplace[x][y + size] >= 97 && battleplace[x][y + size] <= 102)) battleplace[x][y + size] = assistSymbol;
    }
    else if (rotation == 'v') {
        for (int i = -1; i < size + 1; i++) {
            if (y < shipcolumn - 1 && (x-i<shiprow))  if (!(battleplace[x - i][y + 1] >= 48 && battleplace[x - i][y + 1] <= 57 || battleplace[x - i][y + 1] >= 97 && battleplace[x - i][y + 1] <= 102)) battleplace[x - i][y + 1] = assistSymbol;
        };
        for (int i = -1; i < size + 1; i++) { 
            if(x - i < shiprow) if (!(battleplace[x - i][y - 1] >= 48 && battleplace[x - i][y - 1] <= 57 || battleplace[x - i][y - 1] >= 97 && battleplace[x - i][y - 1] <= 102)) battleplace[x - i][y - 1] = assistSymbol;
        };
        if (x < shiprow - 1) if (!(battleplace[x + 1][y] >= 48 && battleplace[x + 1][y] <= 57 || battleplace[x + 1][y] >= 97 && battleplace[x - 1][y] <= 102)) battleplace[x + 1][y] = assistSymbol;
        if (!(battleplace[x - size][y] >= 48 && battleplace[x - size][y] <= 57 || battleplace[x - size][y] >= 97 && battleplace[x - size][y] <= 102)) battleplace[x - size][y] = assistSymbol;
    }
}



void checkforkill(char** fakebattleplace, int x, int y, char ship,int &playerturn) {


    if (ship == 'S') {
        if (y != shipcolumn - 1 && fakebattleplace[x][y] == 'H' && fakebattleplace[x][y + 1] == 'H') {
            fakebattleplace[x][y] = 'K';
            fakebattleplace[x][y + 1] = 'K';
            if (assistmodeOn && playerturn==0) assistmode(fakebattleplace, SubMarineSize, x, y, 'h');
            if (playerturn == 0) {
                remainingshipsBot--; 
            }
            else {
                remainingshipsPerson--;
                hit = false;
            }
            
        }
        else if (y != 1 && fakebattleplace[x][y] == 'H' && fakebattleplace[x][y - 1] == 'H') {
            fakebattleplace[x][y] = 'K';
            fakebattleplace[x][y - 1] = 'K';
            if (assistmodeOn && playerturn == 0) assistmode(fakebattleplace, SubMarineSize, x, y-1, 'h');
            if (playerturn == 0) {
                remainingshipsBot--;
            }
            else {
                remainingshipsPerson--;
                hit = false;
            }

        }
        else if (x != 1 && fakebattleplace[x][y] == 'H' && fakebattleplace[x - 1][y] == 'H') {
            fakebattleplace[x][y] = 'K';
            fakebattleplace[x - 1][y] = 'K';
            if (assistmodeOn && playerturn == 0) assistmode(fakebattleplace, SubMarineSize, x, y, 'v');
            if (playerturn == 0) {
                remainingshipsBot--;
            }
            else {
                remainingshipsPerson--;
                hit = false;
            }

        }
        else if (x != shiprow - 1 && fakebattleplace[x][y] == 'H' && fakebattleplace[x + 1][y] == 'H') {
            fakebattleplace[x][y] = 'K';
            fakebattleplace[x + 1][y] = 'K';
            if (assistmodeOn && playerturn == 0) assistmode(fakebattleplace, SubMarineSize, x+1, y, 'v');
            if (playerturn == 0) {
                remainingshipsBot--;
            }
            else {
                remainingshipsPerson--;
                hit = false;
            }

        }
    }
    else if (ship == 'B') {
        if (y < shipcolumn - 2 && fakebattleplace[x][y] == 'H' && fakebattleplace[x][y + 1] == 'H' && fakebattleplace[x][y + 2] == 'H') {
            fakebattleplace[x][y] = 'K';
            fakebattleplace[x][y + 1] = 'K';
            fakebattleplace[x][y + 2] = 'K';
            if (assistmodeOn && playerturn == 0) assistmode(fakebattleplace, BattleShipSize , x, y, 'h');
            if (playerturn == 0) {
                remainingshipsBot--;
            }
            else {
                remainingshipsPerson--;
                hit = false;
            }

        }
        else if ((y != shipcolumn - 1 && y != 1) && fakebattleplace[x][y] == 'H' && fakebattleplace[x][y + 1] == 'H' && fakebattleplace[x][y - 1] == 'H') {
            fakebattleplace[x][y] = 'K';
            fakebattleplace[x][y + 1] = 'K';
            fakebattleplace[x][y - 1] = 'K';
            if (assistmodeOn && playerturn == 0) assistmode(fakebattleplace, BattleShipSize, x, y-1, 'h');
            if (playerturn == 0) {
                remainingshipsBot--;
            }
            else {
                remainingshipsPerson--;
                hit = false;
            }

        }
        else if (y > 2 && fakebattleplace[x][y] == 'H' && fakebattleplace[x][y - 1] == 'H' && fakebattleplace[x][y - 2] == 'H') {
            fakebattleplace[x][y] = 'K';
            fakebattleplace[x][y - 1] = 'K';
            fakebattleplace[x][y - 2] = 'K';
            if (assistmodeOn && playerturn == 0) assistmode(fakebattleplace, BattleShipSize, x, y - 2, 'h');
            if (playerturn == 0) {
                remainingshipsBot--;
            }
            else {
                remainingshipsPerson--;
                hit = false;
            }

        }
        else if (x > 2 && fakebattleplace[x][y] == 'H' && fakebattleplace[x - 1][y] == 'H' && fakebattleplace[x - 2][y] == 'H') {
            fakebattleplace[x][y] = 'K';
            fakebattleplace[x - 1][y] = 'K';
            fakebattleplace[x - 2][y] = 'K';
            if (assistmodeOn && playerturn == 0) assistmode(fakebattleplace, BattleShipSize, x, y, 'v');
            if (playerturn == 0) {
                remainingshipsBot--;
            }
            else {
                remainingshipsPerson--;
                hit = false;
            }

        }
        else if (x < shiprow - 2 && fakebattleplace[x][y] == 'H' && fakebattleplace[x + 1][y] == 'H' && fakebattleplace[x + 2][y] == 'H') {
            fakebattleplace[x][y] = 'K';
            fakebattleplace[x + 1][y] = 'K';
            fakebattleplace[x + 2][y] = 'K';
            if (assistmodeOn && playerturn == 0) assistmode(fakebattleplace, BattleShipSize, x+2, y, 'v');
            if (playerturn == 0) {
                remainingshipsBot--;
            }
            else {
                remainingshipsPerson--;
                hit = false;
            }

        }
        else if ((x != shiprow - 1 && x != 1) && fakebattleplace[x][y] == 'H' && fakebattleplace[x + 1][y] == 'H' && fakebattleplace[x - 1][y] == 'H') {
            fakebattleplace[x][y] = 'K';
            fakebattleplace[x + 1][y] = 'K';
            fakebattleplace[x - 1][y] = 'K';
            if (assistmodeOn && playerturn == 0) assistmode(fakebattleplace, BattleShipSize, x + 1, y, 'v');
            if (playerturn == 0) {
                remainingshipsBot--;
            }
            else {
                remainingshipsPerson--;
                hit = false;
            }

        }
    }
    else if (ship == 'C') {
        if (y < shipcolumn - 3 && fakebattleplace[x][y] == 'H' && fakebattleplace[x][y + 1] == 'H' && fakebattleplace[x][y + 2] == 'H' && fakebattleplace[x][y + 3] == 'H') {
            fakebattleplace[x][y] = 'K';
            fakebattleplace[x][y + 1] = 'K';
            fakebattleplace[x][y + 2] = 'K';
            fakebattleplace[x][y + 3] = 'K';
            if (assistmodeOn && playerturn == 0) assistmode(fakebattleplace, CarrierSize, x , y, 'h');
            if (playerturn == 0) {
                remainingshipsBot--;
            }
            else {
                remainingshipsPerson--;
                hit = false;
            }

        }
        else if (y > 3 && fakebattleplace[x][y] == 'H' && fakebattleplace[x][y - 1] == 'H' && fakebattleplace[x][y - 2] == 'H' && fakebattleplace[x][y - 3] == 'H') {
            fakebattleplace[x][y] = 'K';
            fakebattleplace[x][y - 1] = 'K';
            fakebattleplace[x][y - 2] = 'K';
            fakebattleplace[x][y - 3] = 'K';
            if (assistmodeOn && playerturn == 0) assistmode(fakebattleplace, CarrierSize, x, y-3, 'h');
            if (playerturn == 0) {
                remainingshipsBot--;
            }
            else {
                remainingshipsPerson--;
                hit = false;
            }

        }
        else if ((y > 2 && y < shipcolumn - 1) && fakebattleplace[x][y] == 'H' && fakebattleplace[x][y + 1] == 'H' && fakebattleplace[x][y - 1] == 'H' && fakebattleplace[x][y - 2] == 'H') {
            fakebattleplace[x][y] = 'K';
            fakebattleplace[x][y + 1] = 'K';
            fakebattleplace[x][y - 1] = 'K';
            fakebattleplace[x][y - 2] = 'K';
            if (assistmodeOn && playerturn == 0) assistmode(fakebattleplace, CarrierSize, x, y - 2, 'h');

            if (playerturn == 0) {
                remainingshipsBot--;
            }
            else {
                remainingshipsPerson--;
                hit = false;
            }

        }
        else if ((y > 1 && y < shipcolumn - 2) && fakebattleplace[x][y] == 'H' && fakebattleplace[x][y - 1] == 'H' && fakebattleplace[x][y + 1] == 'H' && fakebattleplace[x][y + 2] == 'H') {
            fakebattleplace[x][y] = 'K';
            fakebattleplace[x][y - 1] = 'K';
            fakebattleplace[x][y + 1] = 'K';
            fakebattleplace[x][y + 2] = 'K';
            if (assistmodeOn && playerturn == 0) assistmode(fakebattleplace, CarrierSize, x, y - 1, 'h');
            if (playerturn == 0) {
                remainingshipsBot--;
            }
            else {
                remainingshipsPerson--;
                hit = false;
            }

        }
        else if (x > 3 && fakebattleplace[x][y] == 'H' && fakebattleplace[x - 1][y] == 'H' && fakebattleplace[x - 2][y] == 'H' && fakebattleplace[x - 3][y] == 'H') {
            fakebattleplace[x][y] = 'K';
            fakebattleplace[x - 1][y] = 'K';
            fakebattleplace[x - 2][y] = 'K';
            fakebattleplace[x - 3][y] = 'K';
            if (assistmodeOn && playerturn == 0) assistmode(fakebattleplace, CarrierSize, x , y , 'v');

            if (playerturn == 0) {
                remainingshipsBot--;
            }
            else {
                remainingshipsPerson--;
                hit = false;
            }
        }
        else if (x < shiprow - 3 && fakebattleplace[x][y] == 'H' && fakebattleplace[x + 1][y] == 'H' && fakebattleplace[x + 2][y] == 'H' && fakebattleplace[x + 3][y] == 'H') {
            fakebattleplace[x][y] = 'K';
            fakebattleplace[x + 1][y] = 'K';
            fakebattleplace[x + 2][y] = 'K';
            fakebattleplace[x + 3][y] = 'K';
            if (assistmodeOn && playerturn == 0) assistmode(fakebattleplace, CarrierSize, x+3, y, 'v');

            if (playerturn == 0) {
                remainingshipsBot--;
            }
            else {
                remainingshipsPerson--;
                hit = false;
            }
        }
        else if ((x < shiprow - 2 && x>1) && fakebattleplace[x][y] == 'H' && fakebattleplace[x + 1][y] == 'H' && fakebattleplace[x + 2][y] == 'H' && fakebattleplace[x - 1][y] == 'H') {
            fakebattleplace[x][y] = 'K';
            fakebattleplace[x + 1][y] = 'K';
            fakebattleplace[x + 2][y] = 'K';
            fakebattleplace[x - 1][y] = 'K';
            if (assistmodeOn && playerturn == 0) assistmode(fakebattleplace, CarrierSize, x + 2, y, 'v');

            if (playerturn == 0) {
                remainingshipsBot--;
            }
            else {
                remainingshipsPerson--;
                hit = false;
            }

        }
        else if ((x < shiprow - 1 && x>2) && fakebattleplace[x][y] == 'H' && fakebattleplace[x + 1][y] == 'H' && fakebattleplace[x - 2][y] == 'H' && fakebattleplace[x - 1][y] == 'H') {
            fakebattleplace[x][y] = 'K';
            fakebattleplace[x + 1][y] = 'K';
            fakebattleplace[x - 2][y] = 'K';
            fakebattleplace[x - 1][y] = 'K';
            if (assistmodeOn && playerturn == 0) assistmode(fakebattleplace, CarrierSize, x + 1, y, 'v');

            if (playerturn == 0) {
                remainingshipsBot--;
            }
            else {
                remainingshipsPerson--;
                hit = false;
            }

        }
    }

}






void target(char** battleplacebot, char** originalbattleplacebot) {

    int xmove, ymove;

   

    if (checkifsymbolplaced) {
        xmove = 1 + rand() % (shiprow - 1);
        ymove = 1 + rand() % (shipcolumn - 1);
        battleplacebot[xmove][ymove] = 207;
        checkifsymbolplaced = false;
    }
    else {
        xmove = targetx;
        ymove = targety;
    }
    showbattleplaceBot(battleplacebot, shiprow, shipcolumn);

    char key;

    while (true) {

        key = _getch();

        if (key == 72 || key == 119) // up
        {
            if (xmove != 1 && battleplacebot[xmove - 1][ymove] == '.')
            {
                if (battleplacebot[xmove][ymove] == 'M' || battleplacebot[xmove][ymove] == 'H' || battleplacebot[xmove][ymove] == 'K' || battleplacebot[xmove][ymove] == assistSymbol) {
                    battleplacebot[--xmove][ymove] = symbol;
                    check2 = false; 
                }
                else {
                    battleplacebot[xmove][ymove] = '.';
                    battleplacebot[--xmove][ymove] = symbol;
                }

            }
            else if (xmove != 1 && (battleplacebot[--xmove][ymove] == 'H' || battleplacebot[xmove][ymove] == 'M' || battleplacebot[xmove][ymove] == 'K' || battleplacebot[xmove][ymove] == assistSymbol)) {
                if (battleplacebot[xmove + 1][ymove] == 'M' || battleplacebot[xmove + 1][ymove] == 'H' || battleplacebot[xmove + 1][ymove] == 'K' || battleplacebot[xmove+1][ymove] == assistSymbol) {
                    targetx = xmove;
                    targety = ymove;

                }
                else {
                    targetx = xmove;
                    targety = ymove;
                    battleplacebot[xmove + 1][ymove] = '.';
                    check2 = true; 

                }

            }

            showbattleplaceBot(battleplacebot, shiprow, shipcolumn);
        }
        if (key == 80 || key == 115) // down
        {


            if (xmove != (shiprow - 1) && (battleplacebot[xmove + 1][ymove] == '.'))
            {
                if (battleplacebot[xmove][ymove] == 'M' || battleplacebot[xmove][ymove] == 'H' || battleplacebot[xmove][ymove] == 'K' || battleplacebot[xmove][ymove] == assistSymbol) {
                    battleplacebot[++xmove][ymove] = symbol;
                    check2 = false;
                }
                else {

                    battleplacebot[xmove][ymove] = '.';
                    battleplacebot[++xmove][ymove] = symbol;
                }

            }
            else if (xmove != (shiprow - 1) && (battleplacebot[++xmove][ymove] == 'H' || battleplacebot[xmove][ymove] == 'M' || battleplacebot[xmove][ymove] == 'K' || battleplacebot[xmove][ymove] == assistSymbol)) {
                if (battleplacebot[xmove - 1][ymove] == 'M' || battleplacebot[xmove - 1][ymove] == 'H' || battleplacebot[xmove - 1][ymove] == 'K' || battleplacebot[xmove-1][ymove] == assistSymbol) {
                    targetx = xmove;
                    targety = ymove;
                }
                else {
                    targetx = xmove;
                    targety = ymove;
                    battleplacebot[xmove - 1][ymove] = '.';
                    check2 = true;
                }

            }

            showbattleplaceBot(battleplacebot, shiprow, shipcolumn);

        }
        if (key == 75 || key == 97) // left
        {
            if (ymove != 1 && battleplacebot[xmove][ymove - 1] == '.')
            {
                if (battleplacebot[xmove][ymove] == 'M' || battleplacebot[xmove][ymove] == 'H' || battleplacebot[xmove][ymove] == 'K' || battleplacebot[xmove][ymove] == assistSymbol) {
                    battleplacebot[xmove][--ymove] = symbol;
                    check2 = false;
                }
                else {
                    battleplacebot[xmove][ymove] = '.';
                    battleplacebot[xmove][--ymove] = symbol;
                }
            }
            else if (ymove != 1 && (battleplacebot[xmove][--ymove] == 'H' || battleplacebot[xmove][ymove] == 'M' || battleplacebot[xmove][ymove] == 'K' || battleplacebot[xmove][ymove] == assistSymbol)) {
                if (battleplacebot[xmove][ymove + 1] == 'M' || battleplacebot[xmove][ymove + 1] == 'H' || battleplacebot[xmove][ymove + 1] == 'K' || battleplacebot[xmove][ymove+1] == assistSymbol) {
                    targetx = xmove;
                    targety = ymove;
                }
                else {
                    targetx = xmove;
                    targety = ymove;
                    battleplacebot[xmove][ymove + 1] = '.';
                    check2 = true;
                }
            }
            showbattleplaceBot(battleplacebot, shiprow, shipcolumn);

        }
        if (key == 77 || key == 100) // right
        {
            if (ymove != (shipcolumn - 1) && battleplacebot[xmove][ymove + 1] == '.')
            {
                if (battleplacebot[xmove][ymove] == 'M' || battleplacebot[xmove][ymove] == 'H' || battleplacebot[xmove][ymove] == 'K' || battleplacebot[xmove][ymove] == assistSymbol) {
                    battleplacebot[xmove][++ymove] = symbol;
                    check2 = false;
                }
                else {
                    battleplacebot[xmove][ymove] = '.';
                    battleplacebot[xmove][++ymove] = symbol;
                }

            }
            else if (ymove != (shipcolumn - 1) && (battleplacebot[xmove][++ymove] == 'H' || battleplacebot[xmove][ymove] == 'M' || battleplacebot[xmove][ymove] == 'K' || battleplacebot[xmove][ymove] == assistSymbol)) {
                if (battleplacebot[xmove][ymove - 1] == 'M' || battleplacebot[xmove][ymove - 1] == 'H' || battleplacebot[xmove][ymove - 1] == 'K' || battleplacebot[xmove][ymove-1] == assistSymbol) {
                    targetx = xmove;
                    targety = ymove;
                }
                else {
                    targetx = xmove;
                    targety = ymove;
                    battleplacebot[xmove][ymove - 1] = '.';
                    check2 = true;
                }

            }
            showbattleplaceBot(battleplacebot, shiprow, shipcolumn);

        }
        if (key == '\r')
        {
            if (battleplacebot[xmove][ymove] != 'M' && battleplacebot[xmove][ymove] != 'H' && battleplacebot[xmove][ymove] != 'K' && battleplacebot[xmove][ymove] != assistSymbol) {

                check2 = true;
                break;
            }
            else cout<<'\a';
        }

    }

    if (originalbattleplacebot[xmove][ymove] != '.') {
        if (originalbattleplacebot[xmove][ymove] == 'D') {
            targetx = xmove;
            targety = ymove;
            battleplacebot[xmove][ymove] = 'K';
            remainingshipsBot--;
            if (assistmodeOn) assistmode(battleplacebot, DestroyerSize, xmove, ymove);
            showbattleplaceBot(battleplacebot, shiprow, shipcolumn);

        }
        else {
            battleplacebot[xmove][ymove] = 'H';
            targetx = xmove;
            targety = ymove;
            checkforkill(battleplacebot, xmove, ymove, originalbattleplacebot[xmove][ymove],playerturn);

        }
    }
    else if (originalbattleplacebot[xmove][ymove] == '.') {
        battleplacebot[xmove][ymove] = 'M';
        targetx = xmove;
        targety = ymove;
        showbattleplaceBot(battleplacebot, shiprow, shipcolumn);
        playerturn = 1; // bot


    }

}


void smartbot(char** battleplace) {
    int randomhitX, randomhitY;
    while (true) {
        randomhitX = 1 + rand() % (shiprow - 1);
        randomhitY = 1 + rand() % (shipcolumn - 1);
        if (battleplace[randomhitX][randomhitY] != 'M' && battleplace[randomhitX][randomhitY] != 'K' && battleplace[randomhitX][randomhitY] != 'H') break;
    }
    

    if (battleplace[randomhitX][randomhitY] == '.') {
        battleplace[randomhitX][randomhitY] = 'M';
        showbattleplace(battleplace, shiprow, shipcolumn);
        playerturn = 0;
    }
    else if (battleplace[randomhitX][randomhitY] == 'D') {
        battleplace[randomhitX][randomhitY] = 'K';
        remainingshipsPerson--;
        showbattleplace(battleplace, shiprow, shipcolumn);

    }
    else if (battleplace[randomhitX][randomhitY] == 'S' || battleplace[randomhitX][randomhitY] == 'B' || battleplace[randomhitX][randomhitY]=='C') {
        hit = true;
        char tempship = battleplace[randomhitX][randomhitY];
        battleplace[randomhitX][randomhitY] = 'H';
        checkforkill(battleplace, randomhitX, randomhitY, tempship, playerturn);
        showbattleplace(battleplace, shiprow, shipcolumn);

        while (hit==true)  
        {
            int smarthit[4] = { randomhitX - 1 , randomhitX + 1 , randomhitY + 1 , randomhitY - 1};
            int smartchoice = rand() % 4;
            if (smartchoice == 0 && randomhitX - 1 > 0) {
                if ((battleplace[randomhitX - 1][randomhitY] == 'S' || battleplace[randomhitX - 1][randomhitY] == 'B' || battleplace[randomhitX - 1][randomhitY] == 'C')) {
                    char tempship = battleplace[randomhitX - 1][randomhitY];
                    battleplace[--randomhitX][randomhitY] = 'H';
                    checkforkill(battleplace, randomhitX, randomhitY, tempship, playerturn);
                    showbattleplace(battleplace, shiprow, shipcolumn);
                }
                else if (battleplace[randomhitX - 1][randomhitY] == '.') {
                    battleplace[randomhitX - 1][randomhitY] = 'M';
                    showbattleplace(battleplace, shiprow, shipcolumn);
                    playerturn = 0;
                    break;
                }

            }
            else if (smartchoice == 1 && (randomhitX+1<shiprow)) {
                if ((battleplace[randomhitX + 1][randomhitY] == 'S' || battleplace[randomhitX + 1][randomhitY] == 'B' || battleplace[randomhitX + 1][randomhitY] == 'C')) {
                    char tempship = battleplace[randomhitX + 1][randomhitY];
                    battleplace[++randomhitX][randomhitY] = 'H';
                    checkforkill(battleplace, randomhitX, randomhitY, tempship, playerturn);
                    showbattleplace(battleplace, shiprow, shipcolumn);
                }
                else if (battleplace[randomhitX + 1][randomhitY] == '.') {
                    battleplace[randomhitX + 1][randomhitY] = 'M';
                    showbattleplace(battleplace, shiprow, shipcolumn);
                    playerturn = 0;
                    break;
                }
            }
            else if (smartchoice == 2 && (randomhitY + 1 < shipcolumn)) {
                if ((battleplace[randomhitX][randomhitY + 1] == 'S' || battleplace[randomhitX][randomhitY + 1] == 'B' || battleplace[randomhitX][randomhitY + 1] == 'C')) {
                    char tempship = battleplace[randomhitX][randomhitY + 1];
                    battleplace[randomhitX][++randomhitY] = 'H';
                    checkforkill(battleplace, randomhitX, randomhitY, tempship, playerturn);
                    showbattleplace(battleplace, shiprow, shipcolumn);
                }
                else if (battleplace[randomhitX][randomhitY+1] == '.') {
                    battleplace[randomhitX][randomhitY + 1] = 'M';
                    showbattleplace(battleplace, shiprow, shipcolumn);
                    playerturn = 0;
                    break;
                }
            }
            else if (smartchoice == 3 && (randomhitY - 1 > 0)) {
                if ((battleplace[randomhitX][randomhitY - 1] == 'S' || battleplace[randomhitX][randomhitY - 1] == 'B' || battleplace[randomhitX][randomhitY - 1] == 'C')) {
                    char tempship = battleplace[randomhitX][randomhitY - 1];
                    battleplace[randomhitX][--randomhitY] = 'H';
                    checkforkill(battleplace, randomhitX, randomhitY, tempship, playerturn);
                    showbattleplace(battleplace, shiprow, shipcolumn);
                }
                else if (battleplace[randomhitX][randomhitY - 1] == '.') {
                    battleplace[randomhitX][randomhitY - 1] = 'M';
                    showbattleplace(battleplace, shiprow, shipcolumn);
                    playerturn = 0;
                    break;
                }
            }

        }
        
    }
}



















