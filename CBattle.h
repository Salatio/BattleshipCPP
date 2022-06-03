#pragma once

#include "field.h"
#include "bot.h"

class CBattle {
public:
	CBattle();
	void RunGame();
	void GameMenu(RenderWindow& window);
	void GameBody(RenderWindow& window);
	void NewGame(); ///
	void PrintF(Field& _fld, int c); //
private:
	int BotDec, MapDec;
};