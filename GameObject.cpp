#include <sstream>
#include "Header.h"
#include "Board.h"

inline void error(const std::string &message) {
    std::cout << "RUN_TIME_ERROR : " << message << std::endl;
}

inline void log(const std::string &message) {
    std::cout << "LOG : " << message << std::endl;
}

int toInt(char c, int x) {

    if ('a' <= c && c <= 'a' + x /*board.getX()*/) {
        return c - 'a';
    } else {
        error("toInt -> wrong parameter: Letter");
        return 0;
    }
}

int reverse(unsigned x, int y)  //dostaje input i wielkosc planszy
{
    if (x > y /*board.getY()*/) //jesli ziomek wywalil input poza plansze to przypal
        error("reverse error");

    return /*board.getY()*/ y - x + 1;//wzorek dziala lul whatever
}

void GameObject::reveal() {
    std::cout << name() << std::endl;
}


/*Figure::Figure(std::string name, bool own, int HP, int dmg, int cordX, int cordY )
    :GameObject(name), owner(own), HP(HP), dmg(dmg)
{}*/

void Figure::reveal() {
    std::cout << name() << std::endl;
    std::cout << "hp: " << figureHP << std::endl;
    //std::cout << "movement: " << Figure::movement << std::endl;
    //std::cout << "skill: " << Figure::skill << "  " << "defence: " << defence << std::endl;
    std::cout << "dmg: " << figureDMG << std::endl;
    //std::cout << "armour: " << Figure::armour << std::endl;
}

void Figure::addHP(int hp) {
    figureHP += hp;
    if (figureHP < 0) {
        std::ostringstream stringStream;
        stringStream << "Z pola" << cordX << " " << cordY <<
                     "zniknęła figura" << name() << std::endl;
        log(stringStream.str());
    }

}

bool Board::canMove(int cordX, int cordY, int targetX, int targetY) {
    /*
    double required = 0;
    
    if (board[targetX][targetY]->Name == "obstacle")
    {
        return 0;
    }
    
    double X = pow((cordX - targetX), 2);
    double Y = pow((cordY - targetY), 2);
    
    required = sqrt(X + Y);

    return required <= movement;
     */
    return false; //not implemented
}


bool Figure::isYour(bool player) {
    return owner == player;
}

void setHP(int dmg, Figure *target) {
    if ((*target).figureHP < dmg) {
        //zabijaj
        std::cout<<(*target).type << " zginl "<<dmg<<" obrazen"<<std::endl;
    } else {
        (*target).figureHP -= dmg;  //figura target dstaje dmg obrazen
        std::cout << (*target).type << " otrzymal "<<dmg<<" obrazen"<<std::endl;
    }
}

/*bool checkInput(std::string input){
 //Jeøeli te dziwne typy(z game designu) coú zminiπ to tu trzeba dodac elementy do tablic ale beka ...
 std::string cyfra[boardX] = {'1', '2', '3', '4', '5', '6', '7', '8'};
 std::string znakD[boardY] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
 std::string znakM[boardY] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
 
 }*/

/*void missRound(bool &player, int &round){
 round--;
 if(player)player=0;
 else player = 1;
 }*/

int abs(int x) {
    return x < 0 ? -x : x;
}