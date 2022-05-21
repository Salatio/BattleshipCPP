#include "cage.h"

//Функции курсора
void GoToXY(int x, int y)
{
	COORD pos = { x, y };
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(handle, pos);
}

void CursorVisible(bool visible)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(handle, &structCursorInfo);
	structCursorInfo.bVisible = visible;
	SetConsoleCursorInfo(handle, &structCursorInfo);
}
void ClearS() {
	GoToXY(0, 0);
	SetColor(LightCyan, Cyan);
	for (int i = 0; i < 40; ++i) {
		std::cout << " . . . . .        . . .             . . .         . . .             \n";
	}
	/*GoToXY(0, 0);
	std::cout <<"______________$$_____________________ $$\n"
		"____________$$$__$__________________$__$$$___\n"
		"___________$$$___$$________________$$___$$$\n"
		"___________$$$$$$$$________________$$$$$$$$\n"
		"____________$$$$$$__________________$$$$$$\n"
		"_____________$$$$____$$0$$$$$0$$$____$$$$\n"
		"_______________$$__$$$$$$$$$$$$$$$$__$$\n"
		"___________$$___$$$$$$$$$$$$$$$$$$$$$$___$$\n"
		"_________$$__$$__$$$$$$$$$$$$$$$$$$$$__$$__$$\n"
		"________$______$$$$$$$$$$$$$$$$$$$$$$$$______$\n"
		"________$__$$$____$$$$$$$$$$$$$$$$$$____$$$__$\n"
		"__________$___$$$$_$$$$$$$$$$$$$$$$_$$$$___$\n"
		"_________$_________$_$$$$$$$$$$$$_$_________$\n"
		"_________$______$$$________________$$$______$\n"
		"_______________$______________________$\n"
		"______________$________________________$\n"
		"______________$_______________________ _$ \n";*/
	SetColor(White, Black);
	GoToXY(0, 0);
}

// устанавливает цвет текста и подложки в консоли
void SetColor(int text, int background)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

// устанавливает цвет текста и подложки в консоли 
void SetColor(int text, ConsoleColor/*int*/ background)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

Cage::Cage(): local_status("INIT"), X(-1), Y(-1) {} //Initializated
void Cage::ChangeStatus(std::string _st) {
	local_status = _st;
}
void Cage::PrintCage() const {
	if (local_status == "INIT") {
		SetColor(White, LightBlue);
		std::cout << " ~ ";		
	}
	else if (local_status == "ACTIVE") {
		SetColor(White, White);
		std::cout << "   ";		
	}
	else if (local_status == "DESTROYED") {
		SetColor(Red, White);
		std::cout << " X ";		
	}
	else if (local_status == "MISSED") {
		SetColor(White, Yellow);
		std::cout << "   ";		
	}
	else if (local_status == "ELIMINATED") {
		SetColor(White, Red);
		std::cout << "   ";		
	}
	else if (local_status == "NOTHERE") {
		SetColor(White, LightRed);
		std::cout << "   ";
	}
	else if (local_status == "POINT") {
		SetColor(White, Magenta);
		std::cout << "   ";
	}
	SetColor(White, Black);
}
std::string Cage::Status() const {
	return local_status;
}

int Cage::ReturnX() const {
	return X;
}

int Cage::ReturnY() const {
	return Y;
}

void Cage::SetXY(int _x, int _y) {
	X = _x;
	Y = _y;
}
