#include "ship.h"

Ship::Ship() : direction("RIGHT"), health(0), breakcount(0), decks(0) {};
Ship::Ship(int _health) : direction("RIGHT"), health(_health), breakcount(0), decks(_health) {};
void Ship::SetDirection(std::string _dir) {
	direction = _dir;
}
void Ship::ChangeCages(int _x, int _y, std::string _st) { //receives coordinates and created field 		
	for (int i = 0; i < decks; ++i) {
		if ((s[i].ReturnX() == _x) && (s[i].ReturnY() == _y)) {
			s[i].ChangeStatus(_st);
			if (_st == "DESTROYED")
				health--;
		}
	}
}

void Ship::PrintCages(int v) const {
	for (int x = 0; x < decks; ++x) {		
			s[x].PrintCage();		
		std::cout << "\n";
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

std::ostream& operator<<(std::ostream& out, const Ship& shp) {
	shp.PrintCages(0);
	return out;
}