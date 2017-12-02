#include "Header.h"
#include "Board.h"

Pawn::Pawn(int HP, int dmg, std::string name)
	:figureHP(HP), figureDMG(dmg), figureName(name) {
}
Horseman::Horseman(int HP, int dmg, std::string name) 
	:figureHP(HP), figureDMG(dmg), figureName(name){
}
Bishop::Bishop(int HP, int dmg, std::string name) 
	:figureHP(HP), figureDMG(dmg), figureName(name) {
}
Tower::Tower(int HP, int dmg, std::string name)
	: figureHP(HP), figureDMG(dmg), figureName(name) {
}
Queen::Queen(int HP, int dmg, std::string name) 
	: figureHP(HP), figureDMG(dmg), figureName(name) {
}
King::King(int HP, int dmg, std::string name) 
	: figureHP(HP), figureDMG(dmg), figureName(name) {
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

    return (positionX == 2 && positionY == 0) || (positionX == 0 && positionY == 2);
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

