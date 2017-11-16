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
constexpr unsigned int str2int(const char* str, int h = 0)
{
    return !str[h] ? 5381 : (str2int(str, h+1) * 33) ^ str[h];
}

int reverse(char a)
{
    return 8 - (a - '0');
}



GameObject::GameObject(std::string name)
:Name(name)
{
    
}//getLine(plik, linia);       ===== Why is that???

void GameObject::reveal()
{
    std::cout << GameObject::Name << std::endl;
}

bool GameObject::canMove(int startX, int startY, int targetX, int targetY, double movement)
{
    error("wywolano canMove() na GameObject");
    return false;
}



Figure::Figure(std::string name, bool own, int HP, int dmg )
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
    if(hp < 0 ) Figure::HP += hp;
    // else Figure::HP = hp;
}



bool Figure::canMove(int startX, int startY, int targetX, int targetY)
{
    double required = 0;
    
    if (Board[targetX][targetY]->Name == "obstacle")
    {
        return 0;
    }
    
    double X = pow((startX - targetX), 2);
    double Y = pow((startY - targetY), 2);
    
    required = sqrt(X + Y);
    
    if (required <= movement)
        return true;
    else
        return false;
}

void Figure::move(int startX, int startY, int targetX, int targetY)
{
    GameObject* p = Board[targetX][targetY];
    Board[targetX][targetY] = Board[startX][startY];
    Board[startX][startY] = p;
    
    if (!(targetX <= boardX-1 && targetX >= 0))
    {
        error("canMove -> wrong parameter: Number");
    }
    if (!(targetY <= boardY-1 && targetY >= 0))
    {
        error("canMove -> wrong parameter: Number");
    }
}

int Figure::setAttak(int skill, int def, int dmg ,int arm) // Zwraca zadany dmg
{
    int force = rand() % 11 + 1;
    int dif = skill - def;
    if (5 <= force + dif)
        return dmg - arm;
    else
        return 0;
}
bool Figure::checkOwner(bool player, int x, int y){
    return Board[x][y]->owner == player;
    
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
