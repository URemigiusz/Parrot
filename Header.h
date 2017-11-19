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
	bool owner;
        
    GameObject(std::string name = "uninitialized");
    
    virtual bool canMove(int targetX, int targetY);
    virtual void reveal();
    virtual bool checkFigure(bool player, int x, int y);
	virtual void isYour(bool player, int x, int y);
};

static std::array<std::array <GameObject*, boardSize>, boardSize> Board;

class Figure : public GameObject{
private:
    int HP;
    double movement;
	int cordX;
	int cordY;
	
    
public:
    bool owner; // sprawdzamy ...
    
    
    int dmg;
    
    
	Figure(std::string name, bool own, int HP, int dmg, int cordX, int cordY);
    
    virtual bool isYour(bool player, int x, int y);
    void reveal();
    virtual void interact();
    
    void setHP(int hp);  // Zmienia HP obiektu o hp
    
    
    bool canMove(int targetX, int targetY);
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