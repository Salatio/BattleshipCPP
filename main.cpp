#include <SFML/Graphics.hpp>
#include "field.h"
#include "bot.h"
#include "CBattle.h"
#include <time.h>

//int main() {
	//CursorVisible(false);
	/*CBattle GAME;
	GAME.RunGame();
	return 0;*/
//}
using namespace sf;//включаем пространство имен sf, чтобы постоянно не писать sf::
int main()
{
	CBattle GAME;	
	GAME.RunGame();
	
	return 0;
}