#include "Header.h"
#include "Board.h"

bool win         = 0;
bool player       = 0;
int round         = 1;

int main()
{
    setTable();
    
    //stworzenie obiektow
    
    openFile();
    do{
        
        
        /*if(player){
         player = 0;
         std::cout << "tura gracza " << player+<<std::endl;
         }else{
         player = 1;
         std::cout << "tura gracza " << player <<std::endl;
         }*/
        if(round%2 == 0){
            player = 1;
            std::cout << "tura gracza " << player<<std::endl;
        }else{
            player = 0;
            std::cout << "tura gracza " << player<<std::endl;
        }// Nie łatwiej    Player = round % 2;                                       ??????
         //                std::cout << "tura gracza " << player << std::endl;       ??????
        std::string input;
        std::cin >> input;
        
        
        int positionX, positionY;
        positionX = toint(input[0]);
        positionY = reverse(input[1]);
        
        int address = Board[positionX][positionY]; //nie wiemy jaki typ :C
        // GameObject*  lub  GameObjectPtr
        if (input.size() == 2)
        {
            address->reveal();
        }
        else if (input.size() == 5)
        {
            
            
            
            if(checkOwner(player, positionX, positionY))
            {
                int targetX, targetY;
                
                targetX = toint(input[3]);
                targetY = reverse(input[4]);
                
                targetAddress == Board[targetX][targetY];
                
                if (address->Name == "Field")
                {
                    if (address->canMove(positionX, positionY, targetX, targetY))
                    {
                        address->move(positionX, positionY, targetX, targetY));
                        round++;
                    }
                    
                }
                else if (address->Name == "Obstacle")
                    error("interact with Obstacle");
                else
                {
                    //sprawdz czy to twój pionek
                    if(!checkOwner(player, targetX, targetY))
                    {
                        if(address->canAttak(int positionX, int positionY, int targetX, int targetY))
                        {
                            
                            targetAddress->setHP(-address->dmg);
                            if(targetAddress->HP <= 0)
                            {
                                targetAddress->Name = "Field";
                            }
                            round++;
                        }
                        else error("nie możesz go zaatakować");
                        
                    }
                    else error("To twój pionek");
                }
                
                
            }
            else error("To nie twoja figura!");
        }
        else error("Zly input!!");
    }while(!win);
    std::cin.get();
}
/*=======================================[KONIEC JAK BEDZIE WIECEJ NIZ 100 TO SIE ZABIJE]========================================*/
