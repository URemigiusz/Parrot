#pragma ones

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
    Board(unsigned x, unsigned y, unsigned ostChance);
    ~Board();
    
    Line& operator[](unsigned index);
    
    void swap(unsigned x1, unsigned y1, unsigned x2, unsigned y2);
    void swap(std::string a, std::string b);
    void swap(std::string a);
    
    /*
     Create_Std_Board(int x, int y);
     Create_Std_Board_With_Obstacles(int x, int y, int obsChance);
     GetBoard_from_File(string fileName);
     
     */

};


