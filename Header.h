#pragma once

#include <iostream>
#include <cstdlib>
#include <string>
#include <queue>
#include <array>
#include <math.h>
#include <fstream>

const int boardX = 8;
const int boardY = 8;
const int boardSize = 8;


inline void error(const std::string message);
int toint(char c);
int reverse(char a);
constexpr unsigned int str2int(const char* str, int h = 0);


class GameObject{
private:
    
public:
    std::string Name;
    
    
    GameObject(std::string name = "uninitialized");
    
    virtual bool canMove(int startX, int startY, int targetX, int targetY);
    virtual void reveal();
    virtual bool checkFigure(bool player, int x, int y);
};

static std::array<std::array <GameObject*, boardSize>, boardSize> Board;

void setTable();
class Figure : public GameObject{
private:
    int HP;
    double movement;
    
public:
    bool owner; // sprawdzamy ...
    
    
    int dmg;
    
    
    Figure(std::string name, bool own);
    
    virtual bool checkOwner(bool player, int x, int y);
    void reveal();
    virtual void interact();
    
    void setHP(int hp);  // Zmienia HP obiektu o hp
    
    
    bool canMove(int startX, int startY, int targetX, int targetY);
    void move(int startX, int startY, int targetX, int targetY);
    virtual bool canAttak(int positionX, int positionY, int targetX, int targetY);
    //int setAttak(int at, int def, int dmg, int arm); // Zwraca zadany dmg
    
    
    
};


//dziedziczenie po klasie Figure
class Warrior : public Figure
{
public:
    void interact();
    bool canAttak(int positionX, int positionY, int targetX, int targetY);
};

class Spearman : public Figure
{
public:
    void interact();
    bool canAttak(int positionX, int positionY, int targetX, int targetY);
};

class Archer : public Figure
{
public:
    void interact();
    bool canAttak(int positionX, int positionY, int targetX, int targetY);
};

class Horseman : public Figure
{
public:
    void interact();
    bool canAttak(int positionX, int positionY, int targetX, int targetY);
};

class Wartiger : public Figure
{
public:
    void interact();
    bool canAttak(int positionX, int positionY, int targetX, int targetY);
};

class Knight : public Figure
{
public:
    void interact();
    bool canAttak(int positionX, int positionY, int targetX, int targetY);
};

class King : public Figure
{
public:
    void interact();
    bool canAttak(int positionX, int positionY, int targetX, int targetY);
};


/*void missRound(bool &player, int &round){
 }*/

void startFigure(){
    
    /*=============[Czytanie HP DMG]================*/
    std::ifstream file;
    file.open("bin/Figures.txt", std::ios::in);
    std::string linia;
    if(file.good() == true)
    {
        
        while(!file.eof())
        {
            getline(file, linia);
            switch(str2int(linia)){
                case str2int("Warrior"):                //zamieniÊ na ify (gdzieú tu skoÒczyliúmy elo !!!!!!!!!!!!!!!!
                    getLine(file, linia);
                    int HpWarrior = toint(linia[0])*100+toint(linia[1])*10+toint(linia[2]);
                    getLine(file, linia);
                    int DmgWarrior = toint(linia[0])*100+toint(linia[1])*10+toint(linia[2]);
                    
                    //TU MUSI BY∆ DEKLARACJA HP I DMG DLA OBIEKTOW W KLASIE
                    
                    break;
                    
                default:
                    error("W pliku jest klasa ktorej nie rozumiem!")
            }       //tu moøna walnÊ ile nam siÍ podoba klas, tylko mÛwcie jakie (te typki z gamedesignu co udajπ øe coú robiπ :v)
            
        }
        
    }
    file.close();
    
    // tu trzeba tworzyÊ obiekty @@
    
    
    
    
    
    
    std::ifstream file2;
    file2.open("bin/setFigures.txt", std::ios::in);
    if(file2.good() == true){
        while(!file2.eof()){
            bool over = 0;
            getline(file2, linia);
            switch(str2int(linia)):
        case str2int("Warrior 1"):
            do{
                getline(file2, linia);
                int setY = toint(linia[1])-1;
                if (0 <= setY && setY < 9){
                    int setX = toint(linia[0])-1;
                    //ustaw warriora dla gracza 1 na setY i setX
                    Board[setX][setY] = &Figure("Warrior", 0, HpWarrior, DmgWarrior);
                    
                }else over = 1;
            }while(!over);
            
            
            break;
            
        }
    }
}


