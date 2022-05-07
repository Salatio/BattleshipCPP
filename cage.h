#pragma once

#include <cstdlib>
#include <iostream>
#include <vector>
#include <stdexcept>
#include <Windows.h>

void GoToXY(int x, int y);
void CursorVisible(bool visible);
void ClearS();

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