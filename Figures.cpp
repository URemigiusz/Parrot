#include "Header.h"

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
    return targetX == x + 1 && targetY == y + 1 ||
           targetX == x + 1 && targetY == y - 1 ||
           targetX == x - 1 && targetY == y + 1 ||
           targetX == x - 1 && targetY == y - 1;
}

bool  Horseman::canAttack(int targetX, int targetY)
{
    int x = cordX;
    int y = cordY;
    return y == targetY + 1 && wartoscBezwzgledna(targetX - x) == 1 ||
           y == targetY - 1 && wartoscBezwzgledna(targetX - x) == 1 ||
           y == targetY && wartoscBezwzgledna(targetX - x) == 1 ||
           x == targetX && wartoscBezwzgledna(targetY - y) == 1;
}

bool Tower::canAttack(int targetX, int targetY)
{
    int x = cordX;
    int y = cordY;
    return targetX == x && wartoscBezwzgledna (y - targetY) <= 3 ||
           targetY == y && wartoscBezwzgledna (x - targetX) <= 3;
}

bool Bishop::canAttack(int targetX, int targetY)
{
    int x = wartoscBezwzgledna(cordX - targetX);
    int y = wartoscBezwzgledna(cordY - targetY);
    return x == y && x <= 3 && y <= 3;
}

bool Queen::canAttack(int targetX, int targetY)
{
    int x = wartoscBezwzgledna (cordX - targetX);
    int y = wartoscBezwzgledna (cordY - targetY);
    return x == y && x <= 3;
}

bool King::canAttack(int targetX, int targetY)
{
    int x = cordX;
    int y = cordY;
    return targetX == x + 1 && targetY == y + 1 ||
           targetX == x + 1 && targetY == y - 1 ||
           targetX == x - 1 && targetY == y + 1 ||
           targetX == x - 1 && targetY == y - 1;
}
