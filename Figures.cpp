#include "Header.h"

bool Pawn::canAttack(int cordX, int cordY, int targetX, int targetY)
{
    int x = cordX;
    int y = cordY;
    return targetX == x + 1 && targetY == y + 1 ||
           targetX == x + 1 && targetY == y - 1 ||
           targetX == x - 1 && targetY == y + 1 ||
           targetX == x - 1 && targetY == y - 1;
}
bool Pawn::canAttack(int targetX, int targetY) {
    return Pawn::canAttack(cordX, cordY, targetX, targetY);
}

bool Knight::canAttack(int cordX, int cordY, int targetX, int targetY)
{
    int x = cordX;
    int y = cordY;
    return y == targetY + 1 && abs(targetX - x) == 1 ||
           y == targetY - 1 && abs(targetX - x) == 1 ||
           y == targetY && abs(targetX - x) == 1 ||
           x == targetX && abs(targetY - y) == 1;
}
bool Knight::canAttack(int targetX, int targetY) {
    return Knight::canAttack(cordX, cordY, targetX, targetY);
}

bool Rook::canAttack(int cordX, int cordY, int targetX, int targetY)
{
    int x = cordX;
    int y = cordY;
    return targetX == x && abs(y - targetY) <= 3 ||
           targetY == y && abs(x - targetX) <= 3;
}
bool Rook::canAttack(int targetX, int targetY) {
    return Rook::canAttack(cordX, cordY, targetX, targetY);
}

bool Bishop::canAttack(int cordX, int cordY, int targetX, int targetY)
{
    int x = abs(cordX - targetX);
    int y = abs(cordY - targetY);
    return x == y && x <= 3 && y <= 3;
}
bool Bishop::canAttack(int targetX, int targetY) {
    return Bishop::canAttack(cordX, cordY, targetX, targetY);
}

bool Queen::canAttack(int cordX, int cordY, int targetX, int targetY)
{
    int x = abs(cordX - targetX);
    int y = abs(cordY - targetY);
    return x == y && x <= 3;
}
bool Queen::canAttack(int targetX, int targetY) {
    return Queen::canAttack(cordX, cordY, targetX, targetY);
}

bool King::canAttack(int cordX, int cordY, int targetX, int targetY)
{
    int x = cordX;
    int y = cordY;
    return targetX == x + 1 && targetY == y + 1 ||
           targetX == x + 1 && targetY == y - 1 ||
           targetX == x - 1 && targetY == y + 1 ||
           targetX == x - 1 && targetY == y - 1;
}
bool King::canAttack(int targetX, int targetY) {
    return King::canAttack(cordX, cordY, targetX, targetY);
}

bool canAttack(const figType type, int cordX, int cordY, int targetX, int targetY) {
    switch (type) {
        case PAWN:
            return Pawn::canAttack(cordX, cordY, targetX, targetY);
        case KNIGHT:
            return Knight::canAttack(cordX, cordY, targetX, targetY);
        case BISHOP:
            return Bishop::canAttack(cordX, cordY, targetX, targetY);
        case ROOK:
            return Rook::canAttack(cordX, cordY, targetX, targetY);
        case QUEEN:
            return Queen::canAttack(cordX, cordY, targetX, targetY);
        case KING:
            return Queen::canAttack(cordX, cordY, targetX, targetY);
        default:
            return false;
    }
}


/**=============[test gita]==========/
/*bool Pawn::canMove(int targetX, int targetY) { //lel po co to????
    return Pawn::canAttack(cordX, cordY, targetX, targetY);
}*/
/*
 * bool Knight::canMove(int cordX, int cordY, int targetX, int targetY) {
    int x = cordX;
    int y = cordY;
    int changedX = x - targetX;
    int changedY = y - targetY;
    if(){

    }
    else{
        return abs(changedX) <= 8 && y == targetY ||
               abs(changedY) <= 8 && x == targetX;
    }
}
*/

bool Pawn::canMove(int cordX, int cordY, int targetX, int targetY) {
    if(styleA((targetX,targetY)) return true;
    else return false;
}

bool Knight::canMove(int targetX, int targetY)
{
    if(styleA(targetX,targetY) || styleB(targetX,targetY)) return true;
    else return false;
}
//powinno się gdzieś dodać movePoints
bool styleA(int targetX, int targetY) { //+
    int x = cordX;
    int y = cordY;
    int changedX = x - targetX;
    int changedY = y - targetY;

    if(changedX > movePoints || changedY > movePoints) return 0;

    if( changeX < 0 && y == targetY){ // poziomo lewo
        for(int i = 1; i <= changedX; i++){
            if(Board[x-i][y] != /*EmptyField*/) return 0;
        }
    }
    else if(changedX > 0 && y == targetY){ //poziomo prawo
        for(int i = 1; i <= changedX; i++){
            if(Board[x+i][y] != /*EmptyField*/) return 0;
        }
    }
    else if(changedX == 0 && y < targetY){ // w gore
        for(int i = 1; i <= changedX; i++){
            if(Board[x][y+i] != /*EmptyField*/) return 0;
        }
    }
    else if(changedX == 0 && y > targetY){ //w dol
        for(int i = 1; i <= changedX; i++){
            if(Board[x][y-i] != /*EmptyField*/) return 0;
        }
    }
    else return true;
}

bool styleA(int targetX, int targetY){//x
    int x = cordX;
    int y = cordY;
    int changedX = x - targetX;
    int changedY = y - targetY;

    if(changedX > movePoints || changedY > movePoints) return 0;

    if(changedX < 0 && changedY > 0){ //lewy górny
        for(int i = 1; i <= changedX; i++){
            if(Board[x-i][y+i] != /*EmptyField*/) return 0;
        }
    }
    else if(changedX > 0 && changedY > 0){ //Prawy górny
        for(int i = 1; i <= changedX; i++){
            if(Board[x+i][y+i] != /*EmptyField*/) return 0;
        }
    }
    else if(changedX < 0 && changedY < 0){ //lewy dolny
        for(int i = 1; i <= changedX; i++){
            if(Board[x-i][y-i] != /*EmptyField*/) return 0;
        }
    }
    else if(changedX > 0 && changedY < 0){ //prawy górny
        for(int i = 1; i <= changedX; i++){
            if(Board[x+i][y-i] != /*EmptyField*/) return 0;
        }
    }
    else return true;
}

