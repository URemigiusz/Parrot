#include "Header.h"
#include "Board.h"

bool Pawn::canThisAttack(int cordX, int cordY, int targetX, int targetY)
{
    int x = cordX;
    int y = cordY;
    return targetX == x + 1 && targetY == y + 1 ||
           targetX == x + 1 && targetY == y - 1 ||
           targetX == x - 1 && targetY == y + 1 ||
           targetX == x - 1 && targetY == y - 1;
}
bool Pawn::canAttack(int cordX, int cordY, int targetX, int targetY) {
    return Pawn::canThisAttack(cordX, cordY, targetX, targetY);
}

bool Knight::canThisAttack(int cordX, int cordY, int targetX, int targetY)
{
    int x = cordX;
    int y = cordY;
    return y == targetY + 1 && abs(targetX - x) == 1 ||
           y == targetY - 1 && abs(targetX - x) == 1 ||
           y == targetY && abs(targetX - x) == 1 ||
           x == targetX && abs(targetY - y) == 1;
}
bool Knight::canAttack(int cordX, int cordY, int targetX, int targetY) {
    return Knight::canThisAttack(cordX, cordY, targetX, targetY);
}

bool Rook::canThisAttack(int cordX, int cordY, int targetX, int targetY)
{
    int x = cordX;
    int y = cordY;
    return targetX == x && abs(y - targetY) <= 3 ||
           targetY == y && abs(x - targetX) <= 3;
}
bool Rook::canAttack(int cordX, int cordY, int targetX, int targetY) {
    return Rook::canThisAttack(cordX, cordY, targetX, targetY);
}

bool Bishop::canThisAttack(int cordX, int cordY, int targetX, int targetY)
{
    int x = abs(cordX - targetX);
    int y = abs(cordY - targetY);
    return x == y && x <= 3 && y <= 3;
}
bool Bishop::canAttack(int cordX, int cordY, int targetX, int targetY) {
    return Bishop::canThisAttack(cordX, cordY, targetX, targetY);
}

bool Queen::canThisAttack(int cordX, int cordY, int targetX, int targetY)
{
    int x = abs(cordX - targetX);
    int y = abs(cordY - targetY);
    return x == y && x <= 3;
}
bool Queen::canAttack(int cordX, int cordY, int targetX, int targetY) {
    return Queen::canThisAttack(cordX, cordY, targetX, targetY);
}

bool King::canThisAttack(int cordX, int cordY, int targetX, int targetY)
{
    int x = cordX;
    int y = cordY;
    return targetX == x + 1 && targetY == y + 1 ||
           targetX == x + 1 && targetY == y - 1 ||
           targetX == x - 1 && targetY == y + 1 ||
           targetX == x - 1 && targetY == y - 1;
}
bool King::canAttack(int cordX, int cordY, int targetX, int targetY) {
    return King::canThisAttack(cordX, cordY, targetX, targetY);
}

bool canThisAttack(const figType type, int cordX, int cordY, int targetX, int targetY) {
    switch (type) {
        case PAWN:
            return Pawn::canThisAttack(cordX, cordY, targetX, targetY);
        case KNIGHT:
            return Knight::canThisAttack(cordX, cordY, targetX, targetY);
        case BISHOP:
            return Bishop::canThisAttack(cordX, cordY, targetX, targetY);
        case ROOK:
            return Rook::canThisAttack(cordX, cordY, targetX, targetY);
        case QUEEN:
            return Queen::canThisAttack(cordX, cordY, targetX, targetY);
        case KING:
            return Queen::canThisAttack(cordX, cordY, targetX, targetY);
        default:
            return false;
    }
}




//powinno się gdzieś dodać movePoints
bool Board::styleA(Figure &fig, int cordX, int cordY, int targetX, int targetY) { //+
    int x = cordX;
    int y = cordY;
    int changedX = x - targetX;
    int changedY = y - targetY;

    if(changedX > fig.movePoints || changedY > fig.movePoints) return false;

    if( changedX < 0 && y == targetY){ // poziomo lewo
        for(int i = 1; i <= changedX; i++){
            if(!operator[](x - i)[y]->isEmpty()) return false;
        }
    }
    else if(changedX > 0 && y == targetY){ //poziomo prawo
        for(int i = 1; i <= changedX; i++){
            if(operator[](x+i)[y]->isEmpty()) return false;
        }
    }
    else if(changedX == 0 && y < targetY){ // w gore
        for(int i = 1; i <= changedX; i++){
            if(operator[](x)[y+i]->isEmpty()) return false;
        }
    }
    else if(changedX == 0 && y > targetY){ //w dol
        for(int i = 1; i <= changedX; i++){
            if(operator[](x)[y-i]->isEmpty()) return false;
        }
    }
    else return true;
}

bool Board::styleB(Figure &fig, int cordX, int cordY, int targetX, int targetY){//x
    int x = cordX;
    int y = cordY;
    int changedX = x - targetX;
    int changedY = y - targetY;

    if(changedX > fig.movePoints || changedY > fig.movePoints) return false;

    if(changedX < 0 && changedY > 0){ //lewy górny
        for(int i = 1; i <= changedX; i++){
            if(operator[](x-i)[y+i]->isEmpty()) return false;
        }
    }
    else if(changedX > 0 && changedY > 0){ //Prawy górny
        for(int i = 1; i <= changedX; i++){
            if(operator[](x+i)[y+i]->isEmpty()) return false;
        }
    }
    else if(changedX < 0 && changedY < 0){ //lewy dolny
        for(int i = 1; i <= changedX; i++){
            if(operator[](x-i)[y-i]->isEmpty()) return false;
        }
    }
    else if(changedX > 0 && changedY < 0){ //prawy górny
        for(int i = 1; i <= changedX; i++){
            if(operator[](x+i)[y-i]->isEmpty()) return false;
        }
    }
    else return true;
}

bool Board::canAttack(int cordX, int cordY, int targetX, int targetY) {
    //operator[](x)[y-i];
    if(operator[](targetX)[targetY]->isEmpty()) {
        error("Nie mozesz zaatakowac pustego pola");
        return false;
    }
    if(operator[](targetX)[targetY]->isObstacle()){
        error("Nie mozesz atakowac przeszkody");
        return false;
    }
    else{
        return operator[](targetX)[targetY]->canAttack(cordX, cordY, targetX,targetY);
    }
}