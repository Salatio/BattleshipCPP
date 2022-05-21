#pragma once

#include "field.h"
#include "bot.h"

class CBattle {
public:
	CBattle();
	void RunGame();
	void GameBody(int dif);
	void NewGame();
	void PrintF(Field& _fld, int c);
private:

};