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
	for (int i = 0; i < 35; ++i) {
		std::cout << "                                                      \n";
	}
	GoToXY(0, 0);
}

Cage::Cage(): local_status("INIT"), X(-1), Y(-1) {} //Initializated
void Cage::ChangeStatus(std::string _st) {
	local_status = _st;
}
void Cage::PrintCage() const {
	if (local_status == "INIT")
		std::cout << " ~ ";
	else if (local_status == "ACTIVE")
		std::cout << " O ";
	else if (local_status == "DESTROYED")
		std::cout << " X ";
	else if (local_status == "MISSED")
		std::cout << " * ";
	else if (local_status == "ELIMINATED")
		std::cout << " # ";
	else if (local_status == "NOTHERE")
		std::cout << " ? ";
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
