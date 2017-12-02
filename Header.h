#pragma once

#include <iostream>
#include <cstdlib>
#include <string>
#include <queue>
#include <array>
#include <math.h>
#include <fstream>


inline void error(const std::string message);
int toint(char c);
int reverse(unsigned x);
int wartoscBezwzgledna(int x);

class GameObject{
private:

public:
    std::string Name;        
    GameObject(std::string name = "uninitialized");   
    virtual void reveal();
	int cordX;
	int cordY;
};

class Figure : public GameObject{
private:
    double movement;
public:
	bool owner;
	int figureHP;        
    int figureDMG; 
	std::string figureName;
	Figure(std::string name, bool own, int HP, int dmg, int cordX, int cordY);
	Figure() = default;
    virtual bool isYour(bool player);
    void reveal();    
    void setHP(int hp);  // Zmienia HP obiektu o hp        
    //bool canMove(int targetX, int targetY);
    virtual bool canAttack(int targetX, int targetY) = 0;
};

//dziedziczenie po klasie Figure
class Pawn : public Figure  //pionek
{
public:
	Pawn(int HP, int dmg, std::string name);
    bool canAttack(int targetX, int targetY);
    bool canMove(int targetX, int targetY);
};

class Horseman : public Figure  //koń
{
public:
	Horseman(int HP, int dmg, std::string name);
    bool canAttack(int targetX, int targetY);
    bool canMove(int targetX, int targetY);
};

class Tower : public Figure //wieża
{
public:
	Tower(int HP, int dmg, std::string name);
    bool canAttack(int targetX, int targetY);
    bool canMove(int targetX, int targetY);
};

class Bishop : public Figure  //goniec
{
public:
	Bishop(int HP, int dmg, std::string name);
    bool canAttack(int targetX, int targetY);
    bool canMove(int targetX, int targetY);
};

class Queen : public Figure  //królowa
{
public:
	Queen(int HP, int dmg, std::string name);
    bool canAttack(int targetX, int targetY);
    bool canMove(int targetX, int targetY);
};

class King : public Figure  //król
{
public:
	King(int HP, int dmg, std::string name);
    bool canAttack(int targetX, int targetY);
    bool canMove(int targetX, int targetY);
};

