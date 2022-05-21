#include "CBattle.h"
#include <string>

CBattle::CBattle() {}
void CBattle::RunGame() {
	ShowCursor(false);
	/*std::string ans = "YES";*/
	while (1) {
		std::cout << "Press Y to start the game \n";
		int k = 0;
		while (1) {
			k = _getch();
			if (k == 'Y' || k == 'y') {
				ClearS();
				NewGame();
				break;
			}
			else if (k == 'N' || k == 'n')
				return;
		} 
	/*	while (1) {			
			if (GetAsyncKeyState('Y')) {
				ClearS();
				NewGame();
				break;
			}
			else if (GetAsyncKeyState('N'))
				return;				
		}*/
		//Sleep(200);
		
		//std::cin >> ans;
		//ClearS();
		//char a = ans[0];
		//switch (a) {
		//case 'Y':
		//	NewGame();
		//	break;
		//case 'N':
		//	return;
		//	break;
		//}
	}
}
void CBattle::GameBody(int dif) {
	while (true) {
		Bot nBot(dif); //crating new bot	
		Field MainField; //creating new field
		Field BotField; //creating bot's field
		Ship fleet[10] = { 1, 1, 1, 1, 2, 2, 2, 3, 3, 4 }; // 0..3 = "1", 4..6 = "2", 7..8 = "3, 9 = "4"  -  creating new fleet  
		Ship BotFleet[10] = { 1, 1, 1, 1, 2, 2, 2, 3, 3, 4 };  //creating bot's field			
		
		int n = 0;
		while (true) {
			ClearS();
			PrintF(MainField, 0);
			PrintF(BotField, 1);
			std::cout << "Set your field! (choose ship, direction, coordinates)  \n";
		//bool setF = false; //main field isn't set 
			std::string dir;
			int k=0, x=0, y=0;
			int f = 1, s = 5;
			std::string sym="";
			//std::cin >> n >> dir >> x >> y;
			while (true) {
				sym = fleet[n].ReturnDirection();
				PrintF(MainField, 0);
				PrintF(BotField, 1);
				GoToXY(f, s);
				SetColor(White, LightGreen);
				int rd = fleet[n].ReturnDecks();
				bool movr = true;
				bool movl = true;
				bool movu = true;
				bool movd = true;
				bool rot = true;
				switch (sym[0]) {
				case 'R':
					if (y + rd >= 10)
						movr = false;
					if (x + rd - 1 >= 10)
						rot = false;
					for (int i = 0; i < rd; i++)
						std::cout << "   ";
					break;
				case 'D':
					if (x + rd >= 10)
						movd = false;
					if (y - rd + 1 < 0)
						rot = false;
					for (int i = s; i < s+rd; i++) {
						GoToXY(f, i);
						std::cout << "   ";						
					}
					break;
				case 'L':
					if (y - rd < 0)
						movl = false;
					if (x - rd + 1 < 0)
						rot = false;
					GoToXY(f - rd*3+3, s);
					for (int i = 0; i < rd; i++)
						std::cout << "   ";
					break;
				case 'U':	
					if (x - rd < 0)
						movu = false;
					if (y + rd - 1 >= 10)
						rot = false;
					for (int i = s - rd + 1; i <= s; i++) {
						GoToXY(f, i);
						std::cout << "   ";
					}
				}				
				k = _getch();
				if (k != 'N' && k != 'n') {
					switch (k) {
					case 'A': case 'a':
						if (y > 0 && movl) {
							y--;
							f -= 3;
						}
						break;
					case 'D': case 'd':
						if (y < 9 && movr) {
							y++;
							f += 3;
						}
						break;
					case 'W': case 'w':
						if (x > 0 && movu) {
							x--;
							s -= 1;
						}
						break;
					case 'S': case 's':
						if (x < 9 && movd) {
							x++;
							s += 1;
						}
						break;
					case 'R': case 'r':
						switch (sym[0]) {
						case 'R':
							if (rot) 
								fleet[n].SetDirection("DOWN");
							break;
						case 'D':
							if (rot) 
								fleet[n].SetDirection("LEFT");
							break;
						case 'L':
							if (rot) 
								fleet[n].SetDirection("UP");
							break;
						case 'U':
							if (rot) 
								fleet[n].SetDirection("RIGHT");
							break;
						}
						break;
					}
				}
				else
					break;
				SetColor(White, Black);
			}
			GoToXY(0, 0);
			SetColor(White, Red);
			if (MainField.PutShip(x, y, fleet, n))
				n++;
			else
				Sleep(1000);
			if (MainField.ReturnSCount() == LEN)
				break;			
		}		

		ClearS();		
		std::cout << "Enemy's setting field..\n";
		PrintF(MainField, 0);
		PrintF(BotField, 1);		
		Sleep(3000);
		nBot.BotPutShip(BotField, BotFleet);

		while ( true /*MainField.ReturnSCount() != 0 || BotField.ReturnSCount() != 0*/) {
			std::string temp1; //main field
			std::string temp2; //bot field			
			int x=0, y=0;
			int f=36, s=5;
			int k = 0;
			//ClearS();
			do {
				ClearS();
				PrintF(MainField, 0);
				PrintF(BotField, 1);
				if (BotField.ReturnSCount() == 0)
					break;
				std::cout << "Your turn!\n";			
				
				//std::string a = BotField.ReturnCStat(f, s);
				//BotField.ChangeCages(f, s, "POINT");							
				while (1) {
					//ClearS();
					PrintF(MainField, 0);
					PrintF(BotField, 1);
					GoToXY(f, s);
					SetColor(White, LightGreen);
					std::cout << "   ";
					k = _getch();
					if (k != 'N' && k != 'n') {
						switch (k) {
						case 'A': case 'a':
							if (y > 0) {
								y--;
								f -= 3;								
							}
							break;
						case 'D': case 'd':
							if (y < 9) {
								y++;
								f +=3;								
							}
							break;
						case 'W': case 'w':
							if (x > 0) {
								x--;
								s -= 1;								
							}
							break;
						case 'S': case 's':
							if (x < 9) {
								x++;
								s += 1;								
							}
							break;
						}						
					}
					else
						break;
					SetColor(White, Black);
				}				
				//std::cin >> x >> y;
				GoToXY(0, 0);
				SetColor(White, Red);
				int strkf = BotField.StrikeCages(x, y, BotFleet);
				if (strkf == 0)
					Sleep(1000);
				else 
					if (strkf == 1) 
						break;				
			} while (true);
			if (BotField.ReturnSCount() == 0) {
				ClearS();
				std::cout << "You won! \n";
				PrintF(MainField, 0);
				PrintF(BotField, 1);
				Sleep(2000);
				break;
			}
				
			ClearS();
			std::cout << "You missed! \n";
			PrintF(MainField, 0);			
			PrintF(BotField, 1);
			Sleep(2000);			

			ClearS();
			std::cout << "Enemy's thinking..\n";
			PrintF(MainField, 0);
			PrintF(BotField, 1);
			//Sleep(1000);			
			int t = 1500;
			//int t = 0;
			while (true) {
				int strb = nBot.BotStrikeField(MainField, fleet);
				if (strb) {
					Sleep(t - 500);
					if (strb == 1)
						break;
				}
				/*GoToXY(19, 0);
				std::cout << "..";*/
				/*if (MainField.ReturnCCount() > 15) {
					if (nBot.hitted())
						Sleep(t);
					Sleep(t - 500);
				}
				else
					Sleep(t - 1000);*/
				/*if (t > 30)
					t -= 30;*/
				PrintF(MainField, 0);			
				PrintF(BotField, 1);
				if (MainField.ReturnSCount() == 0)
					break;
			}
			//Sleep(t-1000);
			/*if (t > 30)
				t -= 30;*/
			if (MainField.ReturnSCount() == 0) {
				ClearS();
				std::cout << "Enemy's won! \n";
				PrintF(MainField, 0);
				PrintF(BotField, 1);
				Sleep(2000);
				break;
			}
			ClearS();			
			std::cout << "Enemy missed! \n";
			PrintF(MainField, 0);			
			PrintF(BotField, 1);		
			Sleep(3000);
		}
		ClearS();
		std::cout << "Want to try another match? \n";
	/*	std::string ans;
		std::cin >> ans;
		char a = ans[0];
		ClearS();
		switch (a) {
		case 'Y':
			continue;			
		case 'N':
			return;			
		}*/
		int k = 0;
		while (1) {
			k = _getch();
			if (k == 'Y' || k == 'y') {
				ClearS();
				break;
			}
			else if (k == 'N' || k == 'n') {
				ClearS();				
				return;
			}
		}
	}
}
void CBattle::NewGame() {	
	srand(time(0)); //random
	std::cout << "difficulty of bot? (E for easy and H for hard) \n";
	//int d; //difficulty
	//std::cin >> d;

	int k = 0;
	while (1) {
		k = _getch();
		if (k == 'H' || k == 'h') {
			ClearS();
			GameBody(1);
			return;
		}
		else if (k == 'E' || k == 'e') {
			ClearS();
			GameBody(0);
			return;
		}
	} 

	/*while (1) {		
		if (GetAsyncKeyState('E')) {
			ClearS();
			GameBody(1);
			return;
		}
		else if (GetAsyncKeyState('H')) {
			ClearS();
			GameBody(0);
			return;
		}			
	}*/

	//ClearS();
	//GameBody(d);
}

void CBattle::PrintF(Field& _fld, int c) {
	std::string m = "";
	//int p = 0;
	switch (c) {
	case 0:
		m = "Your field, captain!";
		//p = 2;
		break;
	case 1:
		m = "Enemy's field!";
		//p = 16;
		break;
	}	
	//GoToXY(0, p);	
	_fld.PrintCages(c);
	//_fld.PrintCages();	//печать поля
	/*std::cout << "           \n";
	std::cout << _fld.ReturnSCount() << " ship(s) on the field \n";*/
	std::cout << "           \n";
}
