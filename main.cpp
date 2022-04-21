#include "field.h"
#include "bot.h"
#include <time.h>

void PrintF(Field& _fld) {	
	_fld.PrintCages();	//������ ����
	std::cout << "           \n";
	std::cout << _fld.ReturnSCount() << " ship(s) on the field \n";
	std::cout << "           \n";
}

int main() {	
	srand(time(0)); //random
	std::cout << "difficulty of bot? (only 0 is available \n";
	int d; //difficulty
	std::cin >> d;
	Bot nBot(d); //crating new bot
	Field MainField; //creating new field
	Field BotField; //creating bot's field
	Ship fleet[10] = { 1, 1, 1, 1, 2, 2, 2, 3, 3, 4 }; // 0..3 = "1", 4..6 = "2", 7..8 = "3, 9 = "4"  -  creating new fleet  
	Ship BotFleet[10] = { 1, 1, 1, 1, 2, 2, 2, 3, 3, 4 };  //creating bot's field

	std::cout << "Your field, captain! \n";
	PrintF(MainField);

	std::cout << "Enemy's field! \n";
	PrintF(BotField);
	std::cout << "----------------------- \n";
	std::cout << "\n";

	std::cout << "Set your field! (choose ship, direction, coordinates)  \n";
	//bool setF = false; //main field isn't set 
	while (true) {
		std::string dir;
		int n, x, y;
		std::cin >> n >> dir >> x >> y;
		fleet[n].SetDirection(dir);
		MainField.PutShip(x, y, fleet, n);
		std::cout << "Your field, captain! \n";
		PrintF(MainField);
		if (MainField.ReturnSCount() == 2)
			break;
	}	
	std::cout << "----------------------- \n";
	std::cout << "\n";

	nBot.BotPutShip(BotField, BotFleet);	

	while (MainField.ReturnSCount() != 0 || BotField.ReturnSCount() != 0) {		
		std::string temp1; //main field
		std::string temp2; //bot field			
		int x, y;		
		do {
			std::cout << "Your field, captain! \n";
			PrintF(MainField);
			std::cout << "Enemy's field! \n";
			PrintF(BotField);
			std::cout << "----------------------- \n";
			std::cout << "\n";
			std::cout << "Your turn! \n";
			std::cin >> x >> y;
		} while (BotField.StrikeCages(x, y, BotFleet) != 1);	
		std::cout << "You missed! \n";	

		std::cout << "Your field, captain! \n";
		PrintF(MainField);
		std::cout << "Enemy's field! \n";
		PrintF(BotField);
		std::cout << "----------------------- \n";
		std::cout << "\n";

		if (MainField.ReturnSCount() == 0 || BotField.ReturnSCount() == 0)
			break;

		std::cout << "enemy's turn!\n";
		while (nBot.BotStrikeField(MainField, fleet) != 1) {			
			std::cout << "Your field, captain! \n";
			PrintF(MainField);
			std::cout << "Enemy's field! \n";
			PrintF(BotField);
			std::cout << "----------------------- \n";
			std::cout << "\n";
		} 
		std::cout << "Your field, captain! \n";
		PrintF(MainField);
		std::cout << "Enemy's field! \n";
		PrintF(BotField);		

		std::cout << "Enemy missed! \n";
		std::cout << "----------------------- \n";
		std::cout << "\n";
		std::cout << "NEXT ROUND \n";
	}	
	return 0;
}