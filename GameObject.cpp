#include "Header.h"

inline void error(const std::string message)
{
    std::cout << "RUN_TIME_ERROR : " << message << std::endl;
}

int toint(char c, unsigned size){
    
    if ('a' <= c && c <= 'a' + size)
    {
        return c - 'a';
    }
    else
    {
        error("toint -> wrong parameter: Letter");
        return 0;
    }
}

int reverse(unsigned x, unsigned size)
{
    if(x > size)
        error("reverse error");

    return size - x + 1;
}

GameObject::GameObject(std::string name)
    :Name(name)
{
    
}//getLine(plik, linia);       ===== Why is that???

void GameObject::reveal()
{
    std::cout << GameObject::Name << std::endl;
}


/*Figure::Figure(std::string name, bool own, int HP, int dmg, int cordX, int cordY )
    :GameObject(name), owner(own), HP(HP), dmg(dmg)
{}*/

void Figure::reveal()
{
    std::cout << Figure::Name << std::endl;
    std::cout << "hp: " << Figure::figureHP << std::endl;
    //std::cout << "movement: " << Figure::movement << std::endl;
    //std::cout << "skill: " << Figure::skill << "  " << "defence: " << defence << std::endl;
    std::cout << "dmg: " << Figure::figureDMG << std::endl;
    //std::cout << "armour: " << Figure::armour << std::endl;
}

void Figure::setHP(int hp)
{
    figureHP += hp;
		if (figureHP < 0) {
			std::cout << "Z pola" << cordX << " " << cordY << "zniknęła figura" << Name << std::endl;
	}
   
}



/*bool Figure::canMove(int targetX, int targetY, Board &board)
{ 
    double required = 0;
    
    if (board[targetX][targetY]->Name == "obstacle")
    {
        return 0;
    }
    
    double X = pow((cordX - targetX), 2);
    double Y = pow((cordY - targetY), 2);
    
    required = sqrt(X + Y);

    return required <= movement;
}*/


bool Figure::isYour(bool player)
{
    return owner == player;    
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

int wartoscBezwzgledna(int x){
    if(x < 0){
        x = x * (-1);
        return(x);
    }
    else return(x);
}