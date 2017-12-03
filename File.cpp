#include "Header.h"
#include "Board.h"

void GetFromFile(Board &board)
{
    std::fstream file;
    file.open("Save.txt",std::ios::in);

    if(!file.good())
    {
        error("File is not Exist!!!");
        return;
    }

    //plik istnieje

    std::string line;

    int iterator;

    getline(file,line);

    //pobrana zostala linia z wymiarami planszy

    int Board_File_X = 0;
    int Board_File_Y = 0;

    for(iterator = 6; line[iterator] != 'x'; iterator++)
    {
        Board_File_Y = Board_File_Y * 10 + (int)line[iterator] - 48;
    }

    iterator ++;

    for(; line[iterator] != ';'; iterator++)
    {
        Board_File_X = Board_File_X * 10 + (int)line[iterator] - 48;
    }


    //tu zaimplementowac podmiane planszy...

    //wczytane zostaly zmienne Board_File_Y i Board_File_X

    while(!file.eof())       //wczytywanie kolejnych pol
    {
        getline(file,line);

        int Position_File_X = 0;
        int Position_File_Y = 0;
        std::string Name_File;
        bool Own_File;
        int HP_File = 0;
        int Dmg_File = 0;
        int help;

        for(iterator = 6; line[iterator] != ','; iterator+=1)
        {
            Position_File_Y = Position_File_Y * 10 + (int)line[iterator]-48;
        }

        iterator++;

        for(; line[iterator] != ','; iterator++)
        {
            Position_File_X = Position_File_X * 10 + (int)line[iterator] - 48;
        }


        //wczytana lokalizacja pola Position_File_Y i Position_File_X

        iterator++;

        for(int i = 0; line[iterator] != ','; iterator++)
        {
            if(line[iterator] == ';')
            {
                break;
            }
            Name_File[i] = line[iterator];
            i++;
        }

        if(Name_File == obstacleNameString)
        {
            board[Position_File_X][Position_File_Y] = new Obstacle;
            continue;
        }       //tu jest tworzone, jesli mamy przeszkode

        //mam nazwe pola Name_File

        iterator++;

        Own_File = line[iterator];

        //mam Own_File

        iterator++;

        for(; line[iterator] != ','; iterator++)
        {
            HP_File = HP_File * 10 + line[iterator];
            iterator++;
        }

        //mam HP_File

        for(; line[iterator] != ';'; iterator++)
        {
            Dmg_File = Dmg_File * 10 + line[iterator];
            iterator++;
        }

        //mam Dmg_File

        if (Name_File == figNames[PAWN])
            board[Position_File_X][Position_File_Y] = //new Pawn(HP_File,Dmg_File,"COS",Own_File,Position_File_X,Position_File_Y);
                    new Pawn(Own_File, HP_File, Dmg_File);
        else if (Name_File == figNames[KNIGHT])
            board[Position_File_X][Position_File_Y] = //new Horseman(HP_File,Dmg_File,"COS",Own_File,Position_File_X,Position_File_Y);
                    new Knight(Own_File, HP_File, Dmg_File);
        else if (Name_File == figNames[BISHOP])
            board[Position_File_X][Position_File_Y] = //new Bishop(HP_File,Dmg_File,"COS",Own_File,Position_File_X,Position_File_Y);
                    new Bishop(Own_File, HP_File, Dmg_File);
        else if (Name_File == figNames[ROOK])
            board[Position_File_X][Position_File_Y] = //new Tower(HP_File,Dmg_File,"COS",Own_File,Position_File_X,Position_File_Y);
                    new Rook(Own_File, HP_File, Dmg_File);
        else if (Name_File == figNames[QUEEN])
            board[Position_File_X][Position_File_Y] = //new Queen(HP_File,Dmg_File,"COS",Own_File,Position_File_X,Position_File_Y);
                    new Queen(Own_File, HP_File, Dmg_File);
        else if (Name_File == figNames[KING])
            board[Position_File_X][Position_File_Y] = //new King(HP_File,Dmg_File,"COS",Own_File,Position_File_X,Position_File_Y);
                    new King(Own_File, HP_File, Dmg_File);

        //tutaj tworzymy figure...

    }


    file.close();
}