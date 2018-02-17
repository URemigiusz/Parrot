#include <sstream>
#include "Header.h"
#include "Board.h"

enum OurFileError { FILE_NOT_GOOD };

Board GetFromStream(std::istream& file) {

    // Sprawdzenie, czy plik istnieje

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

    // Zmienne Board_File_X i Board_file_Y zawierają w sobie rozmiary planszy (x i y)

    //tu zaimplementowac podmiane planszy...
    Board board(Board_File_X, Board_File_Y);

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
            Position_File_Y = Position_File_Y * 10 + (int)line[iterator] - 48;
        }

        // Position_File_Y zawiera w sobie współrzędną y pola

        iterator++;

        for(; line[iterator] != ','; iterator++)
        {
            Position_File_X = Position_File_X * 10 + (int)line[iterator] - 48;
        }

        // Position_File_X zawiera w sobie współrzędną x pola

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

        if(line[iterator] == '0')
        {
            Own_File = 0;
        }
        else
        {
            Own_File = 1;
        }

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

        //new Pawn(HP_File,Dmg_File,"COS",Own_File,Position_File_X,Position_File_Y);

        if (Name_File == figNames[PAWN])
            board[Position_File_X][Position_File_Y] = new Pawn(Own_File, HP_File, Dmg_File);
        else if (Name_File == figNames[BISHOP])
            board[Position_File_X][Position_File_Y] = new Bishop(Own_File, HP_File, Dmg_File);
        else if (Name_File == figNames[ROOK])
            board[Position_File_X][Position_File_Y] = new Rook(Own_File, HP_File, Dmg_File);
        else if (Name_File == figNames[QUEEN])
            board[Position_File_X][Position_File_Y] = new Queen(Own_File, HP_File, Dmg_File);
        else if (Name_File == figNames[KNIGHT])
            board[Position_File_X][Position_File_Y] = new Knight(Own_File, HP_File, Dmg_File);
        else if (Name_File == figNames[KING])
            board[Position_File_X][Position_File_Y] = new King(Own_File, HP_File, Dmg_File);
        else if (Name_File == figNames[KNIGHT])
            board[Position_File_X][Position_File_Y] = new Knight(Own_File, HP_File, Dmg_File);

        //tutaj tworzymy figure...

    }
    return board;
}

Board GetFromString(const std::string& theString) {
    std::istringstream s(theString);
    return GetFromStream(s);
}

Board GetFromFile(const std::string& fileName) {
    std::fstream file;
    file.open(fileName, std::ios::in);

    // Otwarcie pliku

    if (!file.good()) {
        error("File is not Exist!!!");
        throw FILE_NOT_GOOD;
    } else {
        auto r = GetFromStream(file);
        file.close();
        return r;
    }
}

Board GetFromFile() {
    return GetFromFile("save.txt");
}
