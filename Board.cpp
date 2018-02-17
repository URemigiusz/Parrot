#include <functional>
#include "Header.h"
#include "Board.h"

Line::Line(unsigned size)
    :lineSize(size)
{
    Fields = new GameObject*[lineSize];
}


GameObject* &Line::operator[](unsigned index)
{
    return Fields[reverse(index, sizeof(Fields)) - 1];
}


Board::Board(unsigned x/*=8*/, unsigned y/*=8*/)
:X(x), Y(y)
{
    Rows = new Line[X];
    for(int i = 0; i < X; i++)
    {
        Rows[i] = Line(Y);
        for(int k = 0; k < Y; k++)
        {
            Rows[i][k] = new EmptyField;
        }
    }
}


Line::~Line()
{
    for(int i = 0; i < lineSize; i++)
    {
        delete Fields[i];
    }
    
    delete[] Fields;
}


Board::~Board()
{
    delete[] Rows;
}


Line& Board::operator[](unsigned index)
{
    return Rows[index - 1];
}


int Board::getX() const
{
    return X;
}

int Board::getY() const
{
    return Y;
}


void Board::swap(unsigned x1, unsigned y1, unsigned x2, unsigned y2)
{
    GameObject* buffer;
    buffer = Rows[x1][y1];
    Rows[x1][y1] = Rows[x2][y2];
    Rows[x2][y2] = buffer;
}


void Board::swap(std::string a, std::string b)
{
    int x1 = toInt(a[0], getX());
    int y1 = reverse(a[1], getY());
    int x2 = toInt(b[0], getX());
    int y2 = reverse(b[1], getY());
    
    GameObject* buffer;
    buffer = Rows[x1][y1];
    Rows[x1][y1] = Rows[x2][y2];
    Rows[x2][y2] = buffer;
}


void Board::swap(std::string a)
{
    int x1 = toInt(a[0], getX());
    int y1 = reverse(a[1], getY());
    int x2 = toInt(a[0], getX());
    int y2 = reverse(a[1], getY());
    
    GameObject* buffer;
    buffer = Rows[x1][y1];
    Rows[x1][y1] = Rows[x2][y2];
    Rows[x2][y2] = buffer;
}


void Board::add_rand_obstacles(const std::function<bool(int, int)> &obs)
{
    for(int i = 0; i < X; i++)
    {
        for(int k = 0; k < Y; k++)
        {
            if (i != 0 && i != X-1)
            {
                if (obs(i,k))//(rand() % obsChance == 0)
                    Rows[i][k - 1] = new Obstacle;
                else
                    Rows[i][k] = new EmptyField;
            }
            else
                Rows[i][k] = new EmptyField;
        }
    }
}

void Board::add_rand_obstacles(int obsChance) {
    add_rand_obstacles(
            [obsChance](int i, int k) {
                return rand() % obsChance == 0;
            });
}