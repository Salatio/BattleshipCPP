#pragma once

#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <time.h>
#include <iostream>
using namespace sf;

class Cage {
public:	
	Cage();
	void ChangeStatus(std::string _st);	
	std::string Status() const;
	int ReturnX() const;
	int ReturnY() const;
	void SetXY(int _x, int _y);
private:	
	std::string local_status; 
	int X, Y;
};