#pragma once

#include "field.h"

class Bot {
public:
	Bot();
	Bot(int d);
	void BotPutShip(Field& _fld, Ship* _fleet);
	void PutShip_0(Field& _fld, Ship* _fleet);
	int BotStrikeField(Field& _fld, Ship* _fleet);
	int StrikeF_0(Field& _fld, Ship* _fleet);
private:
	int dif;
};