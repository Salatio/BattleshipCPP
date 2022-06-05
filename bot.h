#pragma once

#include "field.h"

class Bot {
public:
	Bot();
	Bot(int d);
	void BotPutShip(Field& _fld, Ship* _fleet);	
	int BotStrikeField(Field& _fld, Ship* _fleet);
	int StrikeF_0(Field& _fld, Ship* _fleet);
	int StrikeF_1(Field& _fld, Ship* _fleet);	
	void SetDif(int _dif);
	int ReturnDif();
private:
	int dif;
	bool hit;	
	bool R, L, U, D;
	int x, y;
};