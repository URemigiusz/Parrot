#pragma once

#include <iostream>
#include <cstdlib>
#include <string>
#include <queue>
#include <array>
#include <cmath>
#include <fstream>


const bool WHITE = false;
const bool BLACK = true;
enum figType {
	PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING
};
static const short unsigned int figHPvalues[] = {5, 3, 7, 8, 12, 20};
static const short unsigned int figDMGvalues[] = {2, 5, 3, 2, 3, 2};
static const std::string figNames[] =
		{"Pionek", "Kon", "Goniec", "Wieza", "Hetman", "Krol"};
static const std::string figEngNames[] =
        {"Pawn", "Knight", "Bishop", "Rook", "Queen", "King"};
static const std::string emptyFieldNameString = "Field";
static const std::string obstacleNameString = "Obstacle";

inline void error(const std::string &message);
int toInt(char c, int x);
int reverse(unsigned x, int y);


class GameObject{
//private:
public:
    virtual const std::string* name()= 0;
    //GameObject(std::string name = "uninitialized");
    virtual void reveal();

	//virtual bool canMove(int targetX, int targetY, Board &board)=0;
	virtual bool canAttack(int cordX, int cordY, int targetX, int targetY) = 0;
	virtual void addHP(int hp) = 0; // bo mi sie nie chce teraz castowac
    virtual bool isEmpty(){ //sprawdzanie czy jest puste
        return false;
    }
    virtual bool isObstacle(){
        return false;
    }
    virtual const figType* getFigType(){
        return nullptr;
    }
};
using GameObjectPtr = GameObject*;

class EmptyField : public GameObject {
public:
	EmptyField() = default;;
	const std::string* name() override {
		return &emptyFieldNameString;
	}
	//bool canMove(int targetX, int targetY, Board &board) override {
	//	return false;
	//}
	bool canAttack(int cordX, int cordY, int targetX, int targetY) override {
		return false;
	};
	void addHP(int hp) override {} //bo mi sie nie chce teraz castowac
    bool isEmpty() override { //no prawda bo puste
        return true;
    }
};

class Obstacle : public GameObject {
public:
	Obstacle() = default;
	const std::string* name() override {
		return &obstacleNameString;
	}
	//bool canMove(int targetX, int targetY, Board &board) override {
	//	return false;
	//}
	bool canAttack(int cordX, int cordY, int targetX, int targetY) override {
		return false;
	};
	void addHP(int hp) override {} //bo mi sie nie chce teraz castowac
    bool isEmpty() override {
        return false;
    }

	bool isObstacle() override {
        return true;
    }
};

class Figure : public GameObject{
private:
    //double movement;
public:
	bool owner;
	int figureHP;
    int figureDMG;
    int movePoints;
	const figType &type;
	//Figure(std::string name, bool own, int HP, int dmg, int cordX, int cordY);
	Figure(const figType &type, bool owner)
			: type(type), owner(owner),
			  figureDMG(figDMGvalues[type]), figureHP(figHPvalues[type]) {
	}
	Figure(const figType &type, bool owner, int HP)
			: type(type), owner(owner),
			  figureDMG(figDMGvalues[type]), figureHP(HP) {}
	Figure(const figType &type, bool owner, int HP, int dmg)
			: type(type), owner(owner), figureHP(HP), figureDMG(dmg) {}
    virtual bool isYour(bool player);
    void reveal() override;
    const std::string* name() override {
		return &figNames[type];
	}

	void addHP(int hp) override;  // Zmienia HP obiektu o hp, znaczy dodaje tyle HP
	//bool canMove(int targetX, int targetY);
	//bool canMove(int targetX, int targetY, Board &board);
	//virtual bool canAttack(int cordX, int cordY, int targetX, int targetY) = 0;
    bool isEmpty() override {
        return false;
    }
    const figType* getFigType() override {
        return &type;
    }
};

//dziedziczenie po klasie Figure
class Pawn : public Figure  //pionek
{
public:

	explicit Pawn(bool owner) : Figure(PAWN, owner) {}
	Pawn(bool owner, int HP) : Figure(PAWN, owner, HP) {}
	Pawn(bool owner, int HP, int dmg)
			: Figure(PAWN, owner, HP, dmg) {}
	bool canAttack(int cordX, int cordY, int targetX, int targetY) override;
	static bool canThisAttack(int cordX, int cordY, int targetX, int targetY);
};

class Knight : public Figure  //koń
{
public:

	explicit Knight(bool owner) : Figure(KNIGHT, owner) {}
	Knight(bool owner, int HP) : Figure(KNIGHT, owner, HP) {}
	Knight(bool owner, int HP, int dmg)
			: Figure(KNIGHT, owner, HP, dmg) {}

	bool canAttack(int cordX, int cordY, int targetX, int targetY) override;
	static bool canThisAttack(int cordX, int cordY, int targetX, int targetY);
};

class Rook : public Figure //wieża
{
public:

	explicit Rook(bool owner) : Figure(ROOK, owner) {}
	Rook(bool owner, int HP) : Figure(ROOK, owner, HP) {}
	Rook(bool owner, int HP, int dmg)
			: Figure(ROOK, owner, HP, dmg) {}

	bool canAttack(int cordX, int cordY, int targetX, int targetY) override;
	static bool canThisAttack(int cordX, int cordY, int targetX, int targetY);
};

class Bishop : public Figure  //goniec
{
public:

	explicit Bishop(bool owner) : Figure(BISHOP, owner) {}
	Bishop(bool owner, int HP) : Figure(BISHOP, owner, HP) {}
	Bishop(bool owner, int HP, int dmg)
			: Figure(BISHOP, owner, HP, dmg) {}

	bool canAttack(int cordX, int cordY, int targetX, int targetY) override;
	static bool canThisAttack(int cordX, int cordY, int targetX, int targetY);
};

class Queen : public Figure  //królowa
{
public:

	explicit Queen(bool owner) : Figure(QUEEN, owner) {}
	Queen(bool owner, int HP) : Figure(QUEEN, owner, HP) {}
	Queen(bool owner, int HP, int dmg)
			: Figure(QUEEN, owner, HP, dmg) {}
    bool canAttack(int cordX, int cordY, int targetX, int targetY) override;
	static bool canThisAttack(int cordX, int cordY, int targetX, int targetY);
};

//commit testowy

class King : public Figure  //król
{
public:

	explicit King(bool owner) : Figure(KING, owner) {}
	King(bool owner, int HP) : Figure(KING, owner, HP) {}
	King(bool owner, int HP, int dmg)
			: Figure(KING, owner, HP, dmg) {}

	bool canAttack(int cordX, int cordY, int targetX, int targetY) override;
	static bool canThisAttack(int cordX, int cordY, int targetX, int targetY);
};

bool canThisAttack(figType type, int cordX, int cordY, int targetX, int targetY);
bool setHP(int dmg, Figure *target, bool player);