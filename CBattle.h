#pragma once

#include "field.h"
#include "bot.h"

class CBattle {
public:
	CBattle();
	void RunGame();
	bool GameMenu(RenderWindow& window);
	bool GameBody(RenderWindow& window);
	void NewGame(); ///
	void PrintF(Field& _fld, int c); //
private:
	int BotDec, MapDec;
	Bot* nBot;
	Field* MainField;
	Field* BotField;
	Ship* fleet;
	Ship* BotFleet;
};