#pragma once

#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <stdexcept>
#include <Windows.h>
#include <limits>
#include <conio.h>
using namespace sf;

//void GoToXY(int x, int y);
//void CursorVisible(bool visible);
//void ClearS();
//
//enum ConsoleColor
//{
//	Black = 0,
//	Blue = 1,
//	Green = 2,
//	Cyan = 3,
//	Red = 4,
//	Magenta = 5,
//	Brown = 6,
//	LightGray = 7,
//	DarkGray = 8,
//	LightBlue = 9,
//	LightGreen = 10,
//	LightCyan = 11,
//	LightRed = 12,
//	LightMagenta = 13,
//	Yellow = 14,
//	White = 15
//};
//
//void SetColor(int text, int background);
//void SetColor(int text, ConsoleColor/*int*/ background);

class Cage {
public:	
	Cage();
	void ChangeStatus(std::string _st); //receives status name
	void PrintCage() const; //printing status of the cage	
	std::string Status() const; //return status
	int ReturnX() const;
	int ReturnY() const;
	void SetXY(int _x, int _y);
private:	
	std::string local_status; //status of the cage: INIT (initiated), ACTIVE, DESTROYED or MISSED
	int X, Y;
};