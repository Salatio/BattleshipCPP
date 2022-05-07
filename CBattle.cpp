#include "CBattle.h"
#include <string>

CBattle::CBattle() {}
void CBattle::RunGame() {
	std::string ans = "YES";
	while ("YES" == ans) {
		std::cout << "Hi, wanna play a game? \n";		
		std::cin >> ans;
		ClearS();
		char a = ans[0];
		switch (a) {
		case 'Y':
			NewGame();
			break;
		case 'N':
			return;
			break;
		}
	}
}
void CBattle::GameBody(int dif) {
	while (true) {
		Bot nBot(dif); //crating new bot	
		Field MainField; //creating new field
		Field BotField; //creating bot's field
		Ship fleet[10] = { 1, 1, 1, 1, 2, 2, 2, 3, 3, 4 }; // 0..3 = "1", 4..6 = "2", 7..8 = "3, 9 = "4"  -  creating new fleet  
		Ship BotFleet[10] = { 1, 1, 1, 1, 2, 2, 2, 3, 3, 4 };  //creating bot's field			
		
		while (true) {			
			PrintF(MainField, 0);
			PrintF(BotField, 1);
			std::cout << "Set your field! (choose ship, direction, coordinates)  \n";
		//bool setF = false; //main field isn't set 
			std::string dir;
			int n, x, y;
			std::cin >> n >> dir >> x >> y;
			fleet[n].SetDirection(dir);
			ClearS();
			MainField.PutShip(x, y, fleet, n);					
			if (MainField.ReturnSCount() == 1)
				break;
		}		

		nBot.BotPutShip(BotField, BotFleet);

		while (MainField.ReturnSCount() != 0 || BotField.ReturnSCount() != 0) {
			std::string temp1; //main field
			std::string temp2; //bot field			
			int x, y;
			ClearS();
			do {				
				PrintF(MainField, 0);			
				PrintF(BotField, 1);				
				std::cout << "Your turn!\n";
				std::cin >> x >> y;
				ClearS();
			} while (BotField.StrikeCages(x, y, BotFleet) != 1);
			ClearS();
			std::cout << "You missed! \n";

			PrintF(MainField, 0);			
			PrintF(BotField, 1);
			Sleep(2000);

			if (MainField.ReturnSCount() == 0 || BotField.ReturnSCount() == 0)
				break;

			ClearS();
			std::cout << "Enemy's thinking..\n";
			PrintF(MainField, 0);
			PrintF(BotField, 1);
			Sleep(3000);			
			while (nBot.BotStrikeField(MainField, fleet) != 1) {
				std::cout << ".";	
				Sleep(3000);
				PrintF(MainField, 0);			
				PrintF(BotField, 1);				
			}
			ClearS();			
			std::cout << "Enemy missed! \n";
			PrintF(MainField, 0);			
			PrintF(BotField, 1);		
			Sleep(3000);
		}
		ClearS();
		std::cout << "Want to try another match? \n";
		std::string ans;
		std::cin >> ans;
		char a = ans[0];
		ClearS();
		switch (a) {
		case 'Y':
			continue;			
		case 'N':
			return;			
		}
	}
}
void CBattle::NewGame() {
	srand(time(0)); //random
	std::cout << "difficulty of bot? (only 0 and 1 are available) \n";
	int d; //difficulty
	std::cin >> d;	
	ClearS();
	GameBody(d);
}

void CBattle::PrintF(Field& _fld, int c) {
	std::string m = "";
	int p = 0;
	switch (c) {
	case 0:
		m = "Your field, captain!";
		p = 2;
		break;
	case 1:
		m = "Enemy's field!";
		p = 16;
		break;
	}	
	GoToXY(0, p);
	std::cout << m << "\n";
	_fld.PrintCages();	//печать поля
	std::cout << "           \n";
	std::cout << _fld.ReturnSCount() << " ship(s) on the field \n";
	std::cout << "           \n";
}
