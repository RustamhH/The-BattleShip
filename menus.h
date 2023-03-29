#pragma once
#pragma once

void color(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void gotoxy(int x, int y)
{
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}




void printnameofgame() {
    color(3);

    char* text1 = new char[]
    {
        R"(         
                    
                    __________         __    __  .__                .__    .__        
                    \______   \_____ _/  |__/  |_|  |   ____   _____|  |__ |__|_____  
                     |    |  _/\__  \\   __\   __\  | _/ __ \ /  ___/  |  \|  \____ \ 
                     |    |   \ / __ \|  |  |  | |  |_\  ___/ \___ \|   Y  \  |  |_> >
                     |______  /(____  /__|  |__| |____/\___  >____  >___|  /__|   __/ 
                            \/      \/                     \/     \/     \/   |__|    
                    





    )"
    };


    for (int i = 0; text1[i] != '\0'; i++)
    {
        cout << text1[i];
        delay(2);
    }
}





int menu() {
    int Set[] = { 7,3,7 };
    int counter = 2;
    char key;

    while (true)
    {


        gotoxy(45, 13);
        color(Set[0]);
        cout << "1. New Game";

        gotoxy(45, 14);
        color(Set[1]);
        cout << "2. Help";

        gotoxy(45, 15);
        color(Set[2]);
        cout << "3. Exit";



        key = _getch();

        if (key == 72 && (counter >= 2 && counter <= 3))
        {
            counter--;
        }
        if (key == 80 && (counter >= 1 && counter <= 2))
        {
            counter++;
        }
        if (key == '\r')
        {
            break;
        }

        Set[0] = 7;
        Set[1] = 7;
        Set[2] = 7;


        if (counter == 1)
        {
            Set[0] = 3;
        }
        if (counter == 2)
        {
            Set[1] = 3;
        }
        if (counter == 3)
        {
            Set[2] = 3;
        }
    }

    return counter;
}



int ManualPlaceMenu() {
    int Set[] = { 7,3,7,7 };
    int counter = 2;
    char key;

    while (true)
    {


        gotoxy(45, 7);
        color(Set[0]);
        cout << "1. Destroyer";

        gotoxy(45, 8);
        color(Set[1]);
        cout << "2. SubMarine";

        gotoxy(45, 9);
        color(Set[2]);
        cout << "3. BattleShip";


        gotoxy(45, 10);
        color(Set[3]);
        cout << "4. Carrier";




        key = _getch();

        if (key == 72 && (counter >= 2 && counter <= 4))
        {
            counter--;
        }
        if (key == 80 && (counter >= 1 && counter <= 3))
        {
            counter++;
        }
        if (key == '\r')
        {
            break;
        }

        Set[0] = 7;
        Set[1] = 7;
        Set[2] = 7;
        Set[3] = 7;


        if (counter == 1)
        {
            Set[0] = 3;
        }
        if (counter == 2)
        {
            Set[1] = 3;
        }
        if (counter == 3)
        {
            Set[2] = 3;
        }
        if (counter == 4)
        {
            Set[3] = 3;
        }

    }

    return counter;
}







//--------------------------------------------------------------------------------------------------------

int randomormanualplace() {
    int Set[] = { 3,7 };
    int counter = 0;
    char key;

    while (true)
    {

        gotoxy(35, 8);
        color(3);
        cout << "How would you like to place the ships?";

        gotoxy(46, 13);
        color(Set[0]);
        cout << "1. Manual";

        gotoxy(46, 14);
        color(Set[1]);
        cout << "2. Random";




        key = _getch();

        if (key == 72 && (counter == 1))
        {
            counter--;
        }
        if (key == 80 && (counter == 0))
        {
            counter++;
        }
        if (key == '\r')
        {
            break;
        }

        Set[0] = 7;
        Set[1] = 7;


        if (counter == 0)
        {
            Set[0] = 3;
        }
        if (counter == 1)
        {
            Set[1] = 3;
        }
    }

    return counter;
}


int AssistModeOnorOff() {
    int Set[] = { 3,7 };
    int counter = 0;
    char key;

    while (true)
    {

        gotoxy(35, 8);
        color(3);
        cout << "Would you like to enable <<Player Assist Mode>>";

        gotoxy(46, 13);
        color(Set[0]);
        cout << "1. Yes";

        gotoxy(46, 14);
        color(Set[1]);
        cout << "2. No";




        key = _getch();

        if (key == 72 && (counter == 1))
        {
            counter--;
        }
        if (key == 80 && (counter == 0))
        {
            counter++;
        }
        if (key == '\r')
        {
            break;
        }

        Set[0] = 7;
        Set[1] = 7;


        if (counter == 0)
        {
            Set[0] = 3;
        }
        if (counter == 1)
        {
            Set[1] = 3;
        }
    }

    return counter;
}



int azoreng() {
    int Set[] = { 3,7 };
    int counter = 0;
    char key;

    while (true)
    {

        gotoxy(45, 11);
        color(3);
        cout << "Choose a language ";

        gotoxy(46, 13);
        color(Set[0]);
        cout << "1. Azerbaijani";

        gotoxy(46, 14);
        color(Set[1]);
        cout << "2. English";




        key = _getch();

        if (key == 72 && (counter == 1))
        {
            counter--;
        }
        if (key == 80 && (counter == 0))
        {
            counter++;
        }
        if (key == '\r')
        {
            break;
        }

        Set[0] = 7;
        Set[1] = 7;


        if (counter == 0)
        {
            Set[0] = 3;
        }
        if (counter == 1)
        {
            Set[1] = 3;
        }
    }

    return counter;
}

int keyboardorcoordinate() {
    int Set[] = { 3,7 };
    int counter = 0;
    char key;

    while (true)
    {

        gotoxy(45, 11);
        color(3);
        cout << "Which kind of Manual? ";

        gotoxy(46, 13);
        color(Set[0]);
        cout << "1. With Coordinates";

        gotoxy(46, 14);
        color(Set[1]);
        cout << "2. With Keyboard";




        key = _getch();

        if (key == 72 && (counter == 1))
        {
            counter--;
        }
        if (key == 80 && (counter == 0))
        {
            counter++;
        }
        if (key == '\r')
        {
            break;
        }

        Set[0] = 7;
        Set[1] = 7;


        if (counter == 0)
        {
            Set[0] = 3;
        }
        if (counter == 1)
        {
            Set[1] = 3;
        }
    }

    return counter;
}








void logos() {
    char* logo1 = new char[] {

    R"(         
                ____    ____  ______    __    __     ____    __    ____  ______   .__   __.     __  
                \   \  /   / /  __  \  |  |  |  |    \   \  /  \  /   / /  __  \  |  \ |  |    |  | 
                 \   \/   / |  |  |  | |  |  |  |     \   \/    \/   / |  |  |  | |   \|  |    |  | 
                  \_    _/  |  |  |  | |  |  |  |      \            /  |  |  |  | |  . `  |    |  | 
                    |  |    |  `--'  | |  `--'  |       \    /\    /   |  `--'  | |  |\   |    |__| 
                    |__|     \______/   \______/         \__/  \__/     \______/  |__| \__|    (__) 
                                                                                    
    )"
    };

    char* logo2 = new char[] {

    R"(
                                                                                  ,---. 
                        ,--.   ,--.                 ,--.   ,--.                   |   | 
                         \  `.'  /,---. ,--.,--.    |  |   |  | ,---. ,--,--,     |  .' 
                          '.    /| .-. ||  ||  |    |  |.'.|  || .-. ||      \    |  |  
                            |  | ' '-' ''  ''  '    |   ,'.   |' '-' '|  ||  |    `--'  
                            `--'  `---'  `----'     '--'   '--' `---' `--''--'    .--.  
                                                                                  '--'  
    )"
    };


    char* logo3 = new char[] {

    R"(
                         __    __                  __      __                      __     
                        /\ \  /\ \                /\ \  __/\ \                    /\ \    
                        \ `\`\\/'/ ___   __  __   \ \ \/\ \ \ \    ___     ___    \ \ \   
                         `\ `\ /' / __`\/\ \/\ \   \ \ \ \ \ \ \  / __`\ /' _ `\   \ \ \  
                           `\ \ \/\ \L\ \ \ \_\ \   \ \ \_/ \_\ \/\ \L\ \/\ \/\ \   \ \_\ 
                             \ \_\ \____/\ \____/    \ `\___x___/\ \____/\ \_\ \_\   \/\_\
                              \/_/\/___/  \/___/      '\/__//__/  \/___/  \/_/\/_/    \/_/
                                                                                          

    )"
    };


    char* logo4 = new char[] {

    R"(
                         __    __                  __                       __        __     
                        /\ \  /\ \                /\ \                     /\ \__    /\ \    
                        \ `\`\\/'/ ___   __  __   \ \ \        ___     ____\ \ ,_\   \ \ \   
                         `\ `\ /' / __`\/\ \/\ \   \ \ \  __  / __`\  /',__\\ \ \/    \ \ \  
                           `\ \ \/\ \L\ \ \ \_\ \   \ \ \L\ \/\ \L\ \/\__, `\\ \ \_    \ \_\ 
                             \ \_\ \____/\ \____/    \ \____/\ \____/\/\____/ \ \__\    \/\_\
                              \/_/\/___/  \/___/      \/___/  \/___/  \/___/   \/__/     \/_/
                                                                                             
    
    )"
    };
    
    char* logo5 = new char[] {

    R"(
                                                                                        ,---. 
                            ,--.   ,--.                 ,--.                  ,--.      |   | 
                             \  `.'  /,---. ,--.,--.    |  |    ,---.  ,---.,-'  '-.    |  .' 
                              '.    /| .-. ||  ||  |    |  |   | .-. |(  .-''-.  .-'    |  |  
                                |  | ' '-' ''  ''  '    |  '--.' '-' '.-'  `) |  |      `--'  
                                `--'  `---'  `----'     `-----' `---' `----'  `--'      .--.  
                                                                                        '--'  
                                                                                             
    
    )"
    };




    char** Endlogos = new char* [5] {logo1, logo2, logo3, logo4, logo5};









    char x = 219;
    for (int i = 0; i <= 50; i++)
    {

        system("cls");
        color(rand() % 10);
        if (!playerturn)  cout << Endlogos[rand() % 3];
        else cout << Endlogos[3+rand() % 2];
        gotoxy(50, 13);
        color(3);
        delay(100);
    }
    delay(100);

}








void loading() {

    char* ship1 = new char[]
    {
        R"(         


                                                   |    |    |
                                                  )_)  )_)  )_)
                                                 )___))___))___)\
                                                )____)____)_____)\\
                                              _____|____|____|____\\\__
                                     ---------\                   /---------
                                       ^^^^^ ^^^^^^^^^^^^^^^^^^^^^
                                         ^^^^      ^^^^     ^^^    ^^
                                              ^^^^      ^^^ 
    )"
    };

    char* ship2 = new char[]
    {
        R"( 
        
                                                       _
                                                      /|\
                                                     /_|_\
                                                   ____|____
                                                   \_o_o_o_/
                                                  ~~ |     ~~~~~
                                                  ___t_________

    )"
    };

    char* ship3 = new char[]
    {
        R"(  
       
                                                     _~
                                                  _~ )_)_~
                                                  )_))_))_)
                                                  _!__!__!_
                                                  \______t/
                                                ~~~~~~~~~~~~~
    )"
    };

    char* ship4 = new char[]
    {
        R"(         
                                        
                                                  __    __    __
                                               |==|  |==|  |==|
                                             __|__|__|__|__|__|_
                                          __|___________________|___
                                       __|__[]__[]__[]__[]__[]__[]__|___
                                      |............................o.../
                                      \.............................../
                                   ,~')_,~')_,~')_,~')_,~')_,~')_,~')/,~')_
    )"
    };



    char** allships = new char* [4] {ship1, ship2, ship3, ship4};









    char x = 219;
    for (int i = 0; i <= 100; i++)
    {
        if (_kbhit()) {
            _getch();
            break;
        }

        system("cls");
        color(rand() % 10);
        cout << allships[rand() % 4];
        gotoxy(50, 13);
        color(3);
        cout << "[ " << i << "%" << " ]" << endl;
        delay(15);
    }
    delay(350);
}



void rules() {


    cout << "\n------------------------------------BattleShip-e xos gelmisiniz!!!----------------------------------" << endl << endl;
    cout << "Qaydalar sadedir: Reqibin gemilerini ondan tez bitir." << endl;
    cout << "Oyuna baslayarken oz gemilerinizi 2 cur yerlesdirme imkaniniz olacaq: random ve manual." << endl;
    cout << "Manual yerlesdirme zamani console-dan yerlesdirilen geminin koordinatlari daxil etmekle , ve ya keyboard vasitesile  " << endl;
    cout << "Gemiler yerlesdirilenden sonra oyun baslayir." << endl;
    cout << "Oyun ox duymeleri ve ya w-a-s-d duymeleri ile idare olunur." << endl;

    cout << "\n-------------------------Oyunda qarsilasa bileceyeniz simvollar ve onlarin menasi------------------------------" << endl << endl;
    cout << char(207) << " --> Bu simvol reqibin sahesinde hereket edir , istifadeci ENTER-e basanda hemin noqteye vurus edir." << endl;
    color(12);
    cout << "M (Miss) --> Reqibin ve ya sizin etdiyiniz vurus hec bir geminin koordinatlarina uygun gelmir." << endl;
    color(10);
    cout << "H (Hit) --> Reqibin ve ya sizin etdiyiniz vurus geminin koordinatlarindan birine uygun gelir." << endl;
    color(14);
    cout << "K (Kill) --> Reqibin ve ya sizin etdiyiniz vurus butun gemini mehv etmisdir." << endl;
    color(9);
    cout << "~ (Do not place) --> Eger Assist Mode aktivdirse, oyuncuya vurmamasi gereken yerleri gosterir." << endl;
    color(7);

    cout << "\n-------------------------------------------Ugurlar!!!-------------------------------------------" << endl;


}

void rulesEng() {
    cout << "\n------------------------------------Welcome to BattleShip!!!----------------------------------" << endl << endl;
    cout << "The rules are simple: finish your opponent's ships faster than him." << endl;
    cout << "When starting the game, you will have 2 options to place your ships: random and manual." << endl;
    cout << "During manual deployment, the coordinates of the ship deployed from the console are entered, leaving a space. Or you can place them using keyboard." << endl;
    cout << "The game starts after the ships are placed." << endl;
    cout << "The game is controlled by arrow keys or w-a-s-d keys." << endl;

    cout << "\n-------------------------Symbols and their meaning that you can see in the game------------------------------" << endl << endl;
    cout << char(207) << " --> This symbol moves in the field of the opponent, when the user presses ENTER, he hits that point." << endl;
    color(12);
    cout << "M (Miss) --> Your or opponent's shot does not correspond to the coordinates of any ship." << endl;
    color(10);
    cout << "H (Hit) --> Your or opponent's shot corresponds to one of the ship's coordinates." << endl;
    color(14);
    cout << "K (Kill) --> A shot by your opponent or by you destroys the entire ship." << endl;
    color(9);
    cout << "~ (Do not place) --> If The Assist Mode is active , it shows the player where not to hit." << endl;
    color(7);

    cout << "\n-------------------------------------------Good Luck!!!-------------------------------------------" << endl;


}