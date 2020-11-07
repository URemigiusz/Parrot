#include "Header.h"
#include "Board.h"

static bool win = false;
static bool player = false;
static int roundNumber = 0;
static bool attacked;
static bool moved;
static std::string input;
static int positionX, positionY, targetX, targetY;

void move() {}

int main() {
    auto board = GetFromString("brd=8x8;");//File();

    //setlocale( LC_ALL, "pl_PL" );   nie weim jak, ale zostawiam żeb wiedzieć że chcemy polskie znaki

    do {
        player = roundNumber % 2 + 1 != 0;
        std::cout << "Tura gracza " << player << std::endl;
        attacked = false;
        moved = false;
//===========================================CHECKING============================================//

        std::cout << "Jakie pola chcesz sprawdzic: \t \t x-nie chce juz sprawdzac" << std::endl;
        do {
            std::cin >> input;
            if (input.size() == 2) {
                positionX = reverse(input[1], board.getY());
                positionY = toInt(input[0], board.getX());
            } else if (input.size() == 3) {
                positionX = reverse(input[1] * 10 + input[2], board.getY());
                positionY = toInt(input[0], board.getX());
            } else error("Zbyt duzy input");

            board[positionX][positionY]->reveal();

        } while (!(input.size() == 1 && input[0] == 'x'));
//======================================MOVE============================================//
        for (int i = 0; i < 1; i++) {     //to  sie robi raz ale mozna tu wracac :v
            std::cout << "Czy chcesz sie ruszyc y/n : " << std::endl;
            std::cin >> input;
            if (input == "y") {
                std::cout << "Wybierz figure                     exit <-wyjdz " << std::endl;
                std::cin >> input;
                if (input.size() == 2) {
                    positionX = reverse(input[1], board.getY());
                    positionY = toInt(input[0], board.getX());
                } else if (input.size() == 3) {
                    positionX = reverse(input[1] * 10 + input[2], board.getY());
                    positionY = toInt(input[0], board.getX());
                } else if (input == "exit") {
                    i--;
                    continue;
                } else error("Zły input");

            } else if (input == "n") {
                break;
            } else error("Zbyt duzy input");

            std::cout << "Wybierz cel :                          exit-wyjscie" << std::endl;
            std::cin >> input;
            if (input.size() == 2) {
                targetX = reverse(input[1], board.getY());
                targetY = toInt(input[0], board.getX());
            } else if (input.size() == 3) {
                targetX = reverse(input[1] * 10 + input[2], board.getY());
                targetY = toInt(input[0], board.getX());
            } else if (input == "exit") {
                i--;
                continue;
            } else error("Zły input");

            if (board.canMove(positionX, positionY, targetX,
                              targetY)) {         //drogi remku z przyszłości wiemy że to inaczej
                move(); // kiedys się zrobi
                moved = true;
            } else {
                std::cout << "Nie mozesz sie tak ruszyc!" << std::endl;
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
                    positionX = reverse(input[1], board.getY());
                    positionY = toInt(input[0], board.getX());
                } else if (input.size() == 3) {
                    positionX = reverse(input[1] * 10 + input[2], board.getY());
                    positionY = toInt(input[0], board.getX());
                } else if (input == "exit") {
                    i--;
                    continue;
                } else error("Zły input");

            } else if (input == "n") {
                break;
            } else error("Zbyt duzy input");

            std::cout << "Wybierz cel : " << std::endl;
            std::cin >> input;
            if (input.size() == 2) {
                targetX = reverse(input[1], board.getY());
                targetY = toInt(input[0], board.getX());
            } else if (input.size() == 3) {
                targetX = reverse(input[1] * 10 + input[2], board.getY());
                targetY = toInt(input[0], board.getX());
            } else if (input == "exit") {
                i--;
                continue;
            } else error("Zły input");
            if (board.canAttack(positionX, positionY, targetX,
                                targetY)) {       //drogi remku z przyszłości wiemy że to inaczej
                auto *fig = (Figure *) board[positionX][positionY];
                auto *tar = (Figure *) board[targetX][targetY];
                if (setHP(fig->figureDMG, tar, player)) win = true;             //zabicie króla kończy grę
                else attacked = true;
            } else {
                std::cout << "Nie mozesz sie tak ruszyc!" << std::endl;
                i--;
                continue;
            }

        }

        roundNumber++;

    } while (!win);
    std::cin.get();
}

