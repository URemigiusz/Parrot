#include "Header.h"
#include "Board.h"


Line::Line(unsigned size)
    :lineSize(size)
{
    Fields = new GameObject*[lineSize];
}


GameObject* &Line::operator[](unsigned index)
{
    return Fields[reverse(index) - 1];
}


Board::Board(unsigned x, unsigned y)
:X(x), Y(y)
{
    Rows = new Line[X];
    for(int i = 0; i < X; i++)
    {
        Rows[i] = Line(Y);
        for(int k = 0; k < Y; k++)
        {
            Rows[i][k] = new GameObject("Field");
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
    return Rows[index];
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
    int x1 = toint(a[0], X);
    int y1 = reverse(a[1], Y);
    int x2 = toint(b[0], X);
    int y2 = reverse(b[1], Y);
    
    GameObject* buffer;
    buffer = Rows[x1][y1];
    Rows[x1][y1] = Rows[x2][y2];
    Rows[x2][y2] = buffer;
}


void Board::swap(std::string a)
{
    int x1 = toint(a[0], X);
    int y1 = reverse(a[1], Y);
    int x2 = toint(a[3], X);
    int y2 = reverse(a[4], Y);
    
    GameObject* buffer;
    buffer = Rows[x1][y1];
    Rows[x1][y1] = Rows[x2][y2];
    Rows[x2][y2] = buffer;
}


void Board::add_rand_obstacles(int x, int y, int obsChance)
{
    for(int i = 0; i < X; i++)
    {
        for(int k = 0; k < Y; k++)
        {
            if (i != 0 && i != X-1)
            {
                if (rand() % obsChance == 0)
                    Rows[i][k] = new GameObject("Obstacle");
                else
                    Rows[i][k] = new GameObject("Field");
            }
            else
                Rows[i][k] = new GameObject("Field");
        }
    }
}



