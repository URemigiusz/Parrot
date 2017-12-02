#pragma once
#include "Header.h"

using GameObjectPtr = GameObject*;


class Line
{
private:
    unsigned lineSize;
    GameObject** Fields;
    
public:
    Line() = default;
    Line(unsigned size);
    
    GameObject* &operator[](unsigned index);
    ~Line();
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
    
    void add_rand_obstacles(int x, int y, int obsChance);
    void GetBoard_from_File(std::string fileName);
};

Board board;

