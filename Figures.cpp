#include "Header.h"

Pawn::Pawn(int HP, int dmg, std::string name) {
	HP = 5;
	dmg = 2;
	name = "Pionek";
}
Horseman::Horseman(int HP, int dmg, std::string name) {
	HP = 3;
    dmg= 5;
    name= "Kon";
}
Bishop::Bishop(int HP, int dmg, std::string name) {
	HP = 7;
    dmg= 3;
    name= "Goniec";
}
Tower::Tower(int HP, int dmg, std::string name) {
	HP = 8;
    dmg= 2;
    name= "Wieza";
}
Queen::Queen(int HP, int dmg, std::string name) {
	HP = 12;
    dmg= 3;
    name= "Hetman";
}
King::King(int HP, int dmg, std::string name) {
	HP = 20;
    dmg= 2;
    name= "Krol";
}

bool Pawn::canAttak(int positionX, int positionY, int targetX, int targetY)
{
    double X = pow((positionX - targetX), 2);
    double Y = pow((positionY - targetY), 2);
    
    double required = sqrt(X + Y);

    return required > 1 && required < 2;
}

bool  Horseman::canAttak(int positionX, int positionY, int targetX, int targetY)
{
    positionX = positionX - targetX;
    if (positionX < 0) targetX *= -1;
    positionY = positionY - targetY;
    if (positionY < 0) positionY *= -1;

    return positionX == 2 && positionY == 0 || positionX == 0 && positionY == 2;
}

bool Tower::canAttak(int positionX, int positionY, int targetX, int targetY)
{
    positionX = positionX - targetX;
    positionY = positionY - targetY;

    return positionX == targetX || positionY == targetY;
    
}

bool Bishop::canAttak(int positionX, int positionY, int targetX, int targetY)
{
    positionX = positionX - targetX;
    positionY = positionY - targetY;

    return positionX == targetX || positionY == targetY;
}

bool Queen::canAttak(int positionX, int positionY, int targetX, int targetY)
{
    positionX = positionX - targetX;
    if (positionX < 0) targetX *= -1;
    positionY = positionY - targetY;
    if (positionY < 0) positionY *= -1;

    return positionX == positionY;
}

bool King::canAttak(int positionX, int positionY, int targetX, int targetY)
{
    positionX = positionX - targetX;
    if (positionX < 0) targetX *= -1;
    positionY = positionY - targetY;
    if (positionY < 0) positionY *= -1;

    return positionX <= 1 && positionY <= 1;
}
