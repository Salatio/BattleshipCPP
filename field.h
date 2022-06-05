#pragma once

#include "CageArray.h"
#include "ship.h"

class Field: public CageArray {
public:	
	Field();
	virtual ~Field() {};
	virtual void PrintCages(RenderWindow& window, Sprite spr, int _f, int _l) const;
	virtual void ChangeCages(int _x, int _y, std::string _st); 	
	int StrikeCages(int _x, int _y, Ship* _fleet);	
	void ChangeField(int _x, int _y, Ship* _fleet, int n);
	int PutShip(int _x, int _y, Ship* _fleet, int n);
	int ReturnSCount();
	std::string ReturnCStat(int _x, int _y);		
private:
	Cage ShipField[10][10]; 
	int ShipCount;	
};
