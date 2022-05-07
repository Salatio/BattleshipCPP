#pragma once

#include "CageArray.h"

#define LEN 10 

class Ship: public CageArray {
public:	
	Ship();
	Ship(int _health); //receives the amount of decks
	virtual ~Ship() {};
	virtual void ChangeCages(int _x, int _y, std::string _st); //put ship on the field
	void SetDirection(std::string _dir);	
	virtual void PrintCages() const;		
	void InitShip(int _x, int _y);
	int ReturnDecks() const;
	int ReturnX(int _j) const;
	int ReturnY(int _j) const;
	int ReturnBC() const;
	void BCplus();	
	std::string ReturnDirection() const;
	int ReturnHealth() const;		
private:
	std::string direction; //ship direction on the field
	int health; //deck count 
	int decks;
	Cage s[4];
	int breakcount;	
};

std::ostream& operator<<(std::ostream& out, const Ship& shp);