#include "ship.h"

Ship::Ship() : direction("RIGHT"), health(0), breakcount(0), decks(0) {};
Ship::Ship(int _decks) : direction("RIGHT"), health(_decks), breakcount(0), decks(_decks) {};

void Ship::SetDirection(std::string _dir) {
	direction = _dir;
}
void Ship::ChangeCages(int _x, int _y, std::string _st) { 		
	for (int i = 0; i < decks; ++i) {
		if ((s[i].ReturnX() == _x) && (s[i].ReturnY() == _y)) {
			s[i].ChangeStatus(_st);
			if (_st == "DESTROYED")
				health--;
		}
	}
}

void Ship::PrintCages(RenderWindow& window, Sprite spr, int _f, int _l) const {
	int f = _f, l = _l;	
	if (breakcount) {
		if (health) 
			spr.setTextureRect(IntRect(64, 0, 64, 64));
		else if (!health)
			spr.setTextureRect(IntRect(64, 64, 64, 64));
		for (int i = 0; i < decks; ++i) {
			spr.setPosition(f, l);
			window.draw(spr);
			l += 26;
		}
	}
}

void Ship::InitShip(int _x, int _y) {
	int cnt = 0;
	std::string _st = "ACTIVE";
	if (direction == "RIGHT") {
		while (cnt < decks) {
			s[cnt++].SetXY(_x, _y++);
			s[cnt-1].ChangeStatus(_st);
		}
	}
	else if (direction == "DOWN") {
		while (cnt < decks) {
			s[cnt++].SetXY(_x++, _y);
			s[cnt-1].ChangeStatus(_st);
		}
	}
	else if (direction == "LEFT") {
		while (cnt < decks) {
			s[cnt++].SetXY(_x, _y--);
			s[cnt-1].ChangeStatus(_st);
		}
	}
	else if (direction == "UP") {
		while (cnt < decks) {
			s[cnt++].SetXY(_x--, _y);
			s[cnt-1].ChangeStatus(_st);
		}
	}
}

int Ship::ReturnDecks() const {
	return decks;
}

int Ship::ReturnX(int _j) const {
	return s[_j].ReturnX();
}

int Ship::ReturnY(int _j) const {
	return s[_j].ReturnY();
}

int Ship::ReturnBC() const {
	return breakcount;
}

void Ship::BCplus() {
	breakcount++;
}

std::string Ship::ReturnDirection() const {
	return direction;
}

int Ship::ReturnHealth() const {
	return health;
}