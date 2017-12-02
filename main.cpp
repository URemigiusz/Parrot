#include "Header.h"
#include "Board.h"

static bool win          = false;
static bool player       = false;
static int roundNumber         = 0;
static bool attacked;
static bool moved;
static std::string input;
static int positionX, positionY, targetX, targetY;

int main() {
    //openFile(); paweł pisze wczytywanie wszystkoeeeeego z pliku

    do {
        player = roundNumber % 2 + 1;
        std::cout << "Tura gracza " << player << std::endl;
        attacked = 0;
        moved = 0;
//===========================================CHECKING============================================//

        std::cout << "Jakie pola chcesz sprawdzić        x-nie chce już sprawdzać";
        do {
            std::cin >> input;
            if (input.size() == 2) {
                positionX = reverse(input[1]);
                positionY = toint(input[0]);
            }else if (input.size() == 3) {
                positionX = reverse(input[1] * 10 + input[2]);
                positionY = toint(input[0]);
            }else error("Zbyt duzy input");

            board[positionX][positionY]->reveal;

        } while (!(input.size() == 1 && input[0] == 'x'));
//======================================MOVE============================================//
        for (int i = 0; i < 1; i++) {     //to  sie robi raz ale mozna tu wracac :v
            std::cout << "Czy chcesz sie ruszyc y/n : " << std::endl;
            std::cin >> input;
            if (input =="y") {
                std::cout << "Wybierz figure                     exit <-wyjdz " << std::endl;
                std::cin >> input;
                if (input.size() == 2) {
                    positionX = reverse(input[1]);
                    positionY = toint(input[0]);
                } else if (input.size() == 3) {
                    positionX = reverse(input[1] * 10 + input[2]);
                    positionY = toint(input[0]);
                } else if (input == "exit") {
                    i--;
                    continue;
                } else error("Zły input");

            }
            else if(input=="n"){
                break;
            }else error("Zbyt duzy input");

            std::cout << "Wybierz cel :                          exit-wyjscie" << std::endl;
            std::cin >> input;
            if (input.size() == 2) {
                targetX = reverse(input[1]);
                targetY = toint(input[0]);
            } else if (input.size() == 3) {
                targetX = reverse(input[1] * 10 + input[2]);
                targetY = toint(input[0]);
            } else if (input == "exit") {
                i--;
                continue;
            } else error("Zły input");

            if(board[positionX][positionY]->canMove(targetX, targetY){         //drogi remku z przyszłości wiemy że to inaczej
                move(); // kiedys się zrobi
                moved=1;
            }
            else {
                std::cout<<"Nie mozesz sie tak ruszyc!" << std::endl;
                i--;
                continue;
            }
        }
//=============================================ATTACK=====================================================//

        for (int i = 0; i < 1; i++) {     //to  sie robi raz ale mozna tu wracac :v
            std::cout << "Czy chcesz atakować y/n : " << std::endl;
            std::cin >> input;
            if (input[0] == 'y') {
                std::cout << "Wybierz figure :                    exit <-wyjdz " << std::endl;
                std::cin >> input;
                if (input.size() == 2) {
                    positionX = reverse(input[1]);
                    positionY = toint(input[0]);
                } else if (input.size() == 3) {
                    positionX = reverse(input[1] * 10 + input[2]);
                    positionY = toint(input[0]);
                } else if (input == "exit") {
                    i--;
                    continue;
                } else error("Zły input");

            }else if(input=="n") {
                break;
            } else error("Zbyt duzy input");

            std::cout << "Wybierz cel : " << std::endl;
            std::cin >> input;
            if (input.size() == 2) {
                targetX = reverse(input[1]);
                targetY = toint(input[0]);
            } else if (input.size() == 3) {
                targetX = reverse(input[1] * 10 + input[2]);
                targetY = toint(input[0]);
            } else if (input == "exit") {
                i--;
                continue;
            }
            else error("Zły input");

            if(board[positionX][positionY]->canAttak(targetX, targetY){    //drogi remku z przyszłości wiemy że to inaczej
                setHP(); // kiedys się zrobi żeby atakowało
                moved=1;
            }
             else {
                std::cout<<"Nie mozesz sie tak ruszyc!" << std::endl;
                i--;
                continue;
            }

        }

        roundNumber ++;

    }while(!win);
    std::cin.get();
}

