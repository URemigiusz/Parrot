#include "Header.h"

Pawn::Pawn(int HP, int dmg, std::string name) {
    HP = 5;
    const dmg = 2;
    const name = "Pionek";
}
Horseman::Horseman(int HP, int dmg, std::string name) {
    HP = 3;
    const dmg = 5;
    const name = "Kon";
}
Bishop::Bishop(int HP, int dmg, std::string name) {
    HP = 7;
    const dmg = 3;
    const name = "Goniec";
}
Tower::Tower(int HP, int dmg, std::string name) {
    HP = 8;
    const dmg = 2;
    const name = "Wieza";
}
Queen::Queen(int HP, int dmg, std::string name) {
    HP = 12;
    const dmg = 3;
    const name	="Hetman"
}
King::King(int HP, int dmg, std::string name) {
    HP = 20;
    const dmg = 2;
    const name = "Krol";
}

bool Pawn::canAttak(int targetX, int targetY)
{
    if(targetX == cordX + 1 & targetY == cordY + 1) return(1);
    else if(targetX == cordX + 1 & targetY == cordY - 1) return(1);
    else if(targetX == cordX - 1 & targetY == cordY + 1) return(1);
    else if(targetX == cordX - 1 & targetY == cordY - 1) return(1);
    else return(0);

}

bool  Horseman::canAttak(int targetX, int targetY, Board& Board )
{

    if(cordY == targetY + 1 && wartoscBezwzgledna(targetX - cordX) = 1){
        for(int i = cordX - 1; i <= targetX; i++){
            if(Board[cordY][i]->Name == "Obstacle") return(0);
            else return(1);
        }
    }


    else if(cordY == targetY  - 1 && wartoscBezwzgledna(targetX - cordX) = 1){
        for(int i = cordX - 1; i <= targetX; i++){
            if(Board[cordY][i]->Name == "Obstacle") return(0);
            else return(1);
        }
    }

    else if(cordY == targetY && wartoscBezwzgledna(targetX - cordX) = 1){
        return(1);
    }else return(0);




}

bool Tower::canAttak(int targetX, int targetY)
{
    if(targetX == cordX && (cordY - targetY) <= 3){ //Y rośnie czyli ->
        for(int i = cordY; i <= targetY; i++){
            if(Board[cordX][i]->Name == "Obstacle") return(0);
            else return(1);
        }
    }
    else if(targetX == cordX  && (cordY - targetY) <= -3){ //Y rośnie czyli <-
        for(int i = cordY; i >= targetY; i--){
            if(Board[cordX][i]->Name == "Obstacle") return(0);
            else return(1);
        }
    }
    else if(targetY == cordY && cordX - targetX <= 3){ //Y rośnie czyli ^
        for(int i = cordY; i <= targetY; i++){
            if(Board[i][cordY]->Name == "Obstacle") return(0);
            else return(1);
        }
    }
    else if(targetY == cordY && cordX - targetX <= -3){ //Y rośnie czyli v
        for(int i = cordY; i >= targetY; i--){
            if(Board[i][cordY]->Name == "Obstacle") return(0);
            else return(1);
        }
    }
    else return(0);
}

bool Bishop::canAttak(int targetX, int targetY)
{
    cordX = wartoscBezwzgledna(cordX - targetX);
    cordY = wartoscBezwzgledna(cordY - targetY);

    if (cordX == cordY && cordX <=3)
        return 1;
    else
        return 0;
}

bool Queen::canAttak(int targetX, int targetY)
{
    X = wartoscBezwzgledna(cordX - targetX);
    cordY = wartoscBezwzgledna(cordY - targetY);

    if (cordX == cordY && cordX <=3)
        return 1;
    else
        return 0;
}

bool King::canAttak(int targetX, int targetY)
{
    cordX = cordX - targetX;
    if (cordX < 0) targetX *= -1;
    cordY = cordY - targetY;
    if (cordY < 0) cordY *= -1;

    if (cordX <= 1 && cordY <= 1)
        return 1;
    else
        return 0;
}
