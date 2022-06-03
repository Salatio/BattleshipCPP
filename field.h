#pragma once

#include "CageArray.h"
#include "ship.h"

class Field: public CageArray {
public:	
	Field();
	virtual ~Field() {};
	virtual void PrintCages(int v) const; 
	virtual void ChangeCages(int _x, int _y, std::string _st); //change cage status to ACTIVE (receives coordinates)	
	int StrikeCages(int _x, int _y, Ship* _fleet);	
	void ChangeField(int _x, int _y, Ship* _fleet, int n);
	int PutShip(int _x, int _y, Ship* _fleet, int n);
	int ReturnSCount();
	std::string ReturnCStat(int _x, int _y);
	int ReturnCCount();
	/*void ReduceSCount();
	void SCountPlus();*/	
private:
	Cage ShipField[10][10]; //creating field of the sea batle
	int ShipCount;
	int CageCount;
};
std::ostream& operator<<(std::ostream& out, const Field& fld);