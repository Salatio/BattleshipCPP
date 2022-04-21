#include "bot.h"

Bot::Bot() : dif(0) {};
Bot::Bot(int d) : dif(d) {}
void Bot::BotPutShip(Field& _fld, Ship* _fleet) {
	switch (dif) {
	case 0:
		PutShip_0(_fld, _fleet);
		break;
	}
}
void Bot::PutShip_0(Field& _fld, Ship* _fleet) {
	//srand(time(0));
	bool set = false;
	while (!set) {
		for (int i = 0; i < 10; ++i) {
			int j = rand() % 10;
			int n = rand() % 10;
			_fld.PutShip(i, j, _fleet, n);
			if (_fld.ReturnSCount() == 10) {
				set = true;
				break;
			}
		}
	}
}

int Bot::BotStrikeField(Field& _fld, Ship* _fleet) {
	switch (dif) {
	case 0:		
		return StrikeF_0(_fld, _fleet);
		break;
	}
}
int Bot::StrikeF_0(Field& _fld, Ship* _fleet) {
	//srand(time(0));
	int x = rand() % 10;
	int y = rand() % 10;
	return _fld.StrikeCages(x, y, _fleet);
}