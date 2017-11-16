#include "Header.h"


bool Warrior::canAttak(int positionX, int positionY, int targetX, int targetY)
{
    double X = pow((positionX - targetX), 2);
    double Y = pow((positionY - targetY), 2);
    
    double required = sqrt(X + Y);
    
    if (required > 1 && required < 2)
        return 1;
    else
        return 0;
    
}

bool  Spearman::canAttak(int positionX, int positionY, int targetX, int targetY)
{
    positionX = positionX - targetX;
    if (positionX < 0) targetX *= -1;
    positionY = positionY - targetY;
    if (positionY < 0) positionY *= -1;
    
    if (positionX == 2 && positionY == 0)
        return 1;
    else if (positionX == 0 && positionY == 2)
        return 1;
    else
        return 0;
    
}

bool Archer::canAttak(int positionX, int positionY, int targetX, int targetY)
{
    positionX = positionX - targetX;
    positionY = positionY - targetY;
    
    if (positionX == targetX || positionY == targetY)
        return 1;
    else
        return 0;
    
}

bool Horseman::canAttak(int positionX, int positionY, int targetX, int targetY)
{
    positionX = positionX - targetX;
    positionY = positionY - targetY;
    
    if (positionX == targetX || positionY == targetY)
        return 1;
    else
        return 0;
}

bool Wartiger::canAttak(int positionX, int positionY, int targetX, int targetY)
{
    positionX = positionX - targetX;
    if (positionX < 0) targetX *= -1;
    positionY = positionY - targetY;
    if (positionY < 0) positionY *= -1;
    
    if (positionX == positionY)
        return 1;
    else
        return 0;
}

bool Knight::canAttak(int positionX, int positionY, int targetX, int targetY)
{
    positionX = positionX - targetX;
    if (positionX < 0) targetX *= -1;
    positionY = positionY - targetY;
    if (positionY < 0) positionY *= -1;
    
    if (positionX <= 1 && positionY <= 1)
        return 1;
    else
        return 0;
}

bool King::canAttak(int positionX, int positionY, int targetX, int targetY)
{
    positionX = positionX - targetX;
    if (positionX < 0) targetX *= -1;
    positionY = positionY - targetY;
    if (positionY < 0) positionY *= -1;
    
    if (positionX <= 1 && positionY <= 1)
        return 1;
    else
        return 0;
}
