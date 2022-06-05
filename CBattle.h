#pragma once

#include "field.h"
#include "bot.h"

class CBattle {
public:
	CBattle();
	void RunGame();
	bool GameMenu(RenderWindow& window);
	bool GameBody(RenderWindow& window);	
private:
	int BotDec, MapDec;
	Bot* nBot;
	Field* MainField;
	Field* BotField;
	Ship* fleet;
	Ship* BotFleet;
};