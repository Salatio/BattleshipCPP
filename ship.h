#pragma once

#include "CageArray.h"

class Ship: public CageArray {
public:	
	Ship();
	Ship(int _decks);
	virtual ~Ship() {};
	virtual void ChangeCages(int _x, int _y, std::string _st); 
	void SetDirection(std::string _dir);	
	virtual void PrintCages(RenderWindow& window, Sprite spr, int _f, int _l) const;
	void InitShip(int _x, int _y);
	int ReturnDecks() const;
	int ReturnX(int _j) const;
	int ReturnY(int _j) const;
	int ReturnBC() const;
	void BCplus();	
	std::string ReturnDirection() const;
	int ReturnHealth() const;		
private:
	std::string direction; 
	int health; 
	int decks;
	Cage s[4];
	int breakcount;	
};
