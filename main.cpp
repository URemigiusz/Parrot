#include "Header.h"
#include "Board.h"

static bool win          = 0;
static bool player       = 0;
static int round         = 1;

int main()
{
    
        
{   
    //openFile();
	/*trzeba zrobić aby z pliku wczytało nam
	wymiar planszy
	współżędne figur
	współżędne obiektów
	wszystkie zasoby figur
	*/
    do{
                

        player = round % 2;                                       
        std::cout << "tura gracza " << player << std::endl;       
        std::string input;
        std::cin >> input;
        
        
        int positionX, positionY;
        positionX = toint(input[0]);
        positionY = reverse(input[1]);			//przypisz pierwszy adres jako in 0, 1
        
		GameObject* address = Board[positionX][positionY]; //nie wiemy jaki typ :C
        // GameObject*  lub  GameObjectPtr
        if (input.size() == 2)
        {
            address->reveal();
        }
        else if (input.size() == 5)
        {
            
            
            
            if(isYour(player, positionX, positionY))  //Sprawdź czy ruszasz swój pionek
            {
                int targetX, targetY;
                
                targetX = toint(input[3]);
                targetY = reverse(input[4]);		// przypisz in3,4 jako target
                
                int targetAddress = Board[targetX][targetY];
                
                if (targetAddress->Name == "Field")
                {
                    if (targetAddress->canMove(positionX, positionY, targetX, targetY))
                    {
                        targetAddress->move(positionX, positionY, targetX, targetY));
                        round++;
                    }
                    
                }
                else if (targetAddress->Name == "Obstacle")
                    error("interact with Obstacle");
                else
                {
                    //sprawdz czy to twój pionek
                    if(!isYour(player, targetX, targetY)) //sprawdz jaki pionek tam stoi
                    {
                        if(address->canAttak(int positionX, int positionY, int targetX, int targetY))
                        {
                            targetAddress->setHP(-address->dmg); //setHp to znaczy zadaj dmg
                            
                            round++;
                        }
                        else error("nie możesz go zaatakować");
                        
                    }
                    else error("To twój pionek"); // atakujesz swój pionek łosiu
                }
                
                
            }
            else error("To nie twoja figura!");
        }
        else error("Zly input!!");
    }while(!win);
    std::cin.get();
}
/*=======================================[KONIEC JAK BEDZIE WIECEJ NIZ 100 TO SIE ZABIJE]========================================*/
