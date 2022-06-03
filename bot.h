#pragma once

#include "field.h"

class Bot {
public:
	Bot();
	Bot(int d);
	void BotPutShip(Field& _fld, Ship* _fleet);
	void PutShip_0(Field& _fld, Ship* _fleet);
	void PutShip_1(Field& _fld, Ship* _fleet);
	int BotStrikeField(Field& _fld, Ship* _fleet);
	int StrikeF_0(Field& _fld, Ship* _fleet);
	int StrikeF_1(Field& _fld, Ship* _fleet);
	bool hitted();
	void SetDif(int _dif);
	int ReturnDif();
private:
	int dif;
	bool hit;
	std::string pos;
	bool R, L, U, D;
	int x, y;
};