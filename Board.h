#pragma once
#include <functional>
#include "Header.h"

class Line
{
private:
    unsigned lineSize;
    GameObject** Fields;

public:
    Line() = default;

    explicit Line(unsigned size);

    GameObject* &operator[](unsigned index);
    ~Line();
    //unsigned getY() {return lineSize;}

    //GameObject *&get(unsigned int index, int y);
};


class Board
{
private:
    unsigned X;
    unsigned Y;
    Line* Rows;
public:
    Board(unsigned x, unsigned y);
    Board() = default;
    ~Board();

    Line& operator[](unsigned index);

    int getX() const;
    int getY() const;

    void swap(unsigned x1, unsigned y1, unsigned x2, unsigned y2);
    void swap(std::string a, std::string b);
    void swap(std::string a);

    void add_rand_obstacles(/*int x, int y,*/ int obsChance);
    void GetBoard_from_File(std::string fileName);


    bool canMove(int cordX, int cordY, int targetX, int targetY);

    void add_rand_obstacles(/*int x, int y,*/ const std::function<bool(int, int)> &obs);
    bool styleA(Figure &fig, int cordX, int cordY, int targetX, int targetY);
    bool styleB(Figure &fig, int cordX, int cordY, int targetX, int targetY);
    bool canAttack(int cordX, int cordY, int targetX, int targetY);
};

Board GetFromStream(std::istream& theStream);
Board GetFromString(const std::string& theString);
Board GetFromFile(const std::string& fileName);
Board GetFromFile();
