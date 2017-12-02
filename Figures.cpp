#include "Header.h"
#include "Board.h"

Pawn::Pawn(int HP, int dmg, std::string name)
        :figureHP(HP), figureDMG(dmg), figureName(name) {
    HP = 5;
    const dmg = 2;
    const name = "Pionek";
}
Horseman::Horseman(int HP, int dmg, std::string name)
        :figureHP(HP), figureDMG(dmg), figureName(name) {
    HP = 3;
    const dmg = 5;
    const name = "Kon";
}
Bishop::Bishop(int HP, int dmg, std::string name)
        :figureHP(HP), figureDMG(dmg), figureName(name) {
    HP = 7;
    const dmg = 3;
    const name = "Goniec";
}
Tower::Tower(int HP, int dmg, std::string name)
        :figureHP(HP), figureDMG(dmg), figureName(name) {
    HP = 8;
    const dmg = 2;
    const name = "Wieza";
}
Queen::Queen(int HP, int dmg, std::string name)
        :figureHP(HP), figureDMG(dmg), figureName(name) {
    HP = 12;
    const dmg = 3;
    const name	="Hetman";
}
King::King(int HP, int dmg, std::string name)
        :figureHP(HP), figureDMG(dmg), figureName(name) {
    HP = 20;
    const dmg = 2;
    const name = "Krol";
}

bool Pawn::canAttack(int targetX, int targetY)
{
    int x = cordX;
    int y = cordY;
    if(targetX == x + 1 && targetY == y + 1 ) return(1);
    else if(targetX == x + 1 && targetY == y - 1) return(1);
    else if(targetX == x - 1 && targetY == y + 1) return(1);
    else if(targetX == x - 1 && targetY == y - 1) return(1);
    else return(0);
}

bool  Horseman::canAttack(int targetX, int targetY)
{
    int x = cordX;
    int y = cordY;
    if(y == targetY + 1 && wartoscBezwzgledna(targetX - x) == 1)         return 1;
    else if(y == targetY  - 1 && wartoscBezwzgledna(targetX - x) == 1)   return 1;
    else if(y == targetY && wartoscBezwzgledna(targetX - x) == 1)        return 1;
    else if(x == targetX && wartoscBezwzgledna(targetY - y) == 1)        return 1;
    else return 0;
}

bool Tower::canAttack(int targetX, int targetY)
{
    int x = cordX;
    int y = cordY;
    if(targetX == x && wartoscBezwzgledna (y - targetY) <= 3)           return 1;
    else if(targetY == y && wartoscBezwzgledna (x - targetX) <= 3)      return 1;
    else return 0;
}

bool Bishop::canAttack(int targetX, int targetY)
{
    int x = wartoscBezwzgledna(cordX - targetX);
    int y = wartoscBezwzgledna(cordY - targetY);
    if (x == y && x <=3 && y <=3) return 1;
    else return 0;
}

bool Queen::canAttack(int targetX, int targetY)
{
    int x = wartoscBezwzgledna (cordX - targetX);
    int y = wartoscBezwzgledna (cordY - targetY);
    if (x == y && x <= 3) return 1;
    else return 0;
}

bool King::canAttack(int targetX, int targetY)
{
    int x = cordX;
    int y = cordY;
    if(targetX == x + 1 && targetY == y + 1 ) return(1);
    else if(targetX == x + 1 && targetY == y - 1) return(1);
    else if(targetX == x - 1 && targetY == y + 1) return(1);
    else if(targetX == x - 1 && targetY == y - 1) return(1);
    else return(0);
}
