#include "Header.h"
#include "Board.h"

Pawn::Pawn(int HP, int dmg, std::string name)
        :figureHP(HP), figureDMG(dmg), figureName(name) {
    HP = 5;
    const dmg = 2;
    const name = "Pionek";
}
Knight::Knight(int HP, int dmg, std::string name)
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
Rook::Rook(int HP, int dmg, std::string name)
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

bool  Knight::canAttack(int targetX, int targetY)
{
    int x = cordX;
    int y = cordY;
    return y == targetY + 1 && wartoscBezwzgledna(targetX - x) == 1 ||
           y == targetY - 1 && wartoscBezwzgledna(targetX - x) == 1 ||
           y == targetY && wartoscBezwzgledna(targetX - x) == 1 ||
           x == targetX && wartoscBezwzgledna(targetY - y) == 1;
}

bool Rook::canAttack(int targetX, int targetY)
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

