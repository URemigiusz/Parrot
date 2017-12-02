#include "Header.h"
#include "Board.h"

static bool win          = 0;
static bool player       = 0;
static int roundNumber         = 1;

int main()
{
	//openFile();
	/*trzeba zrobić aby z pliku wczytało nam
	wymiar planszy
	współżędne figur
	współżędne obiektów
	wszystkie zasoby figur
	*/
	Board board(10, 10); //zmienić na zczytanie z pliku rozmiaru z planszy

	do {
		player = roundNumber % 2;
		std::cout << "tura gracza " << player << std::endl;
		std::string input;
		std::cin >> input;
		int positionX;	 //cyfry
		int	positionY;   //literki
		int	targetX;	//cyfry
		int	targetY;	//literki

<<<<<<< HEAD
=======
        player = round % 2;                                       
        std::cout << "tura gracza " << player << std::endl;       
        std::string input;
        std::cin >> input;
		int positionX,	 //cyfry
			positionY,   //literki
			targetX,	//cyfry
			targetY;	//literki
		
>>>>>>> b423332460d0a1142ff238f18a297087dacd8af4
		if (input.size() == 2) {
			positionY = toint(input[0]);
			positionX = reverse(input[1]);  //prosze napisać reverse now!!!
		}
		else if (input.size() == 3) {
			positionY = toint(input[0]);
			positionX = reverse(input[1] * 10 + input[2]);
<<<<<<< HEAD

=======
>>>>>>> b423332460d0a1142ff238f18a297087dacd8af4
		}

		else if (input.size() == 5) {
			positionY = toint(input[0]);
			positionX = reverse(input[1]);
			targetY = toint(input[3]);
			targetX = reverse(input[4]);
		}
		else if (input.size() == 6) {
			positionY = toint(input[0]);
			if (input[2] == ' ') {
				positionX = reverse(input[1]);
				targetY = toint(input[3]);
				targetX = reverse(input[4] * 10 + input[5]);
			}
			else {
				positionX = reverse(input[1] * 10 + input[2]);
				targetY = toint(input[4]);
				targetX = reverse(input[5]);
			}
		}
		else if (input.size() == 7) {
			positionY = toint(input[0]);
			positionX = reverse(input[1] * 10 + input[2]);
			targetY = toint(input[4]);
			targetX = reverse(input[5] * 10 + input[6]);
		}
		else error("Za duży input!");

<<<<<<< HEAD
	} while (!win);
	std::cin.get();
}
=======
		//positionX, positionY, targetX, targetY maja w sobie dobre wartosci

>>>>>>> b423332460d0a1142ff238f18a297087dacd8af4
//===========================================================================//
/*
		Figure* address = (Figure*)board[positionX][positionY];
		Figure* targetAddress = (Figure*)board[targetX][targetY];
       
        if (input.size() == 5 || input.size() == 6 || input.size() == 7)
        {
			if (targetAddress->Name == "Field")
			{
				if (address->canMove(targetX, targetY))
				{
					board.swap(positionX, positionY, targetX, targetY);
					roundNumber++;
				}
				else error("Nie możesz wykonać takiego ruchu");
			}
			else if (targetAddress->Name == "Obstacle") error("walisz w przeszkode");           
            else if(address->isYour(player))  //Sprawdź czy ruszasz swój pionek
            {               
                GameObject* targetAddress = board[targetX][targetY];               
                    //sprawdz czy to twój pionek
                    if(!address->isYour(player)) //sprawdz jaki pionek tam stoi
                    {
						if (address->canAttak(int targetX, int targetY))
						{
							targetAddress->setHP(-address->dmg); //setHp to znaczy zadaj dmg
							round++;
						}
                        else error("nie możesz go zaatakować");                       
                    }
                    else error("To twój pionek"); // atakujesz swój pionek łosiu               
            }
            else error("To nie twoja figura!");
        }
        else error("Zly input!!");
    }while(!win);
    std::cin.get();
}
/*=======================================[KONIEC JAK BEDZIE WIECEJ NIZ 100 TO SIE ZABIJE]========================================*/