#include "Header.h"

inline void error(const std::string message)
{
    std::cout << "RUN_TIME_ERROR : " << message << std::endl;
}

inline int toint(char c)
{
    
    if ('a' <= c && c <= 'h')
    {
        return c - 'a';
    }
    else
    {
        error("toint -> wrong parameter: Letter");
        return 0;
    }
}


GameObject::GameObject(std::string name)
    :Name(name)
{
    
}//getLine(plik, linia);       ===== Why is that???

void GameObject::reveal()
{
    std::cout << GameObject::Name << std::endl;
}

bool GameObject::canMove(int targetX, int targetY)
{
    error("wywolano canMove() na GameObject");
    return false;
}



Figure::Figure(std::string name, bool own, int HP, int dmg, int cordX, int cordY )
    :GameObject(name), owner(own), HP(HP), dmg(dmg)
{
}

void Figure::reveal()
{
    std::cout << Figure::Name << std::endl;
    std::cout << "hp: " << Figure::HP << std::endl;
    //std::cout << "movement: " << Figure::movement << std::endl;
    //std::cout << "skill: " << Figure::skill << "  " << "defence: " << defence << std::endl;
    std::cout << "dmg: " << Figure::dmg << std::endl;
    //std::cout << "armour: " << Figure::armour << std::endl;
}

void Figure::setHP(int hp)
{
    HP += hp;
		if (HP < 0) {
			std::cout << "Z pola" << cordX << " " << cordY << "zniknęła figura" << Name << std::endl;
	}
   
}



bool Figure::canMove(int targetX, int targetY)
{
    double required = 0;
    
    if (Board[targetX][targetY]->Name == "obstacle")
    {
        return 0;
    }
    
    double X = pow((cordX - targetX), 2);
    double Y = pow((cordY - targetY), 2);
    
    required = sqrt(X + Y);
    
    if (required <= movement)
        return true;
    else
        return false;
}


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
