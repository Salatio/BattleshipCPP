#include "bot.h"

Bot::Bot() : dif(0), hit(false), x(-1), y(-1), pos("UNKNOWN"), R(true), L(true), U(true), D(true) {};
Bot::Bot(int d) : dif(d), hit(false), x(-1), y(-1), pos("UNKNOWN"), R(true), L(true), U(true), D(true) {}
void Bot::BotPutShip(Field& _fld, Ship* _fleet) {
	std::cout.setstate(std::ios_base::failbit);
	srand(time(0));	
	switch (dif) {
	case 0:
		PutShip_0(_fld, _fleet);
		break;
	case 1:
		PutShip_1(_fld, _fleet);
		break;
	}
	std::cout.clear();
}
void Bot::PutShip_0(Field& _fld, Ship* _fleet) {
	////srand(time(0));	
	//int arr[10] = { 0 }; //array of placed ships
	//bool set = false;
	//while (!set) {
	//	for (int i = 0; i < 10; ++i) {
	//		int j = rand() % 10;	
	//		int n;
	//		do {
	//			n = rand() % 10;
	//		} while (arr[n]);
	//		if (_fld.PutShip(i, j, _fleet, n))
	//			arr[n]++;
	//		if (_fld.ReturnSCount() == 10) {
	//			set = true;
	//			break;
	//		}
	//	}
	//}
	PutShip_1(_fld, _fleet);
}

void Bot::PutShip_1(Field& _fld, Ship* _fleet) {
	//srand(time(0));	
	int arr[10] = { 0 }; //array of placed ships
	bool set = false;
	while (!set) {
		for (int i = 0; i < 10; ++i) {
			int j = rand() % 10;
			int n;
			do {
				n = rand() % 10;
			} while (arr[n]);
			int dr = rand() % 4;
			switch (dr) {
			case 0:
				_fleet[n].SetDirection("RIGHT");
				break;
			case 1:
				_fleet[n].SetDirection("DOWN");
				break;
			case 2:
				_fleet[n].SetDirection("UP");
				break;
			case 3:
				_fleet[n].SetDirection("LEFT");
				break;
			}
			if (_fld.PutShip(i, j, _fleet, n))
				arr[n]++;
			if (_fld.ReturnSCount() == LEN) {
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
	case 1:
		return StrikeF_1(_fld, _fleet);
		break;
	}
}
int Bot::StrikeF_0(Field& _fld, Ship* _fleet) {
	int x = rand() % 10;
	int y = rand() % 10;	
	return _fld.StrikeCages(x, y, _fleet);
}

int Bot::StrikeF_1(Field& _fld, Ship* _fleet) {
	//srand(time(0));
	if (!hit) {
		int _x = rand() % 10;
		int _y = rand() % 10;
		/*int _y = 0;
		if (_fld.ReturnCCount() > 20) {			
			_y = rand() % 10;
		}
		else {
			for (int j = 0; j < 9; j++) {
				if (_fld.ReturnCStat(_x, _y) == "ACTIVE" || _fld.ReturnCStat(_x, _y) == "INIT") {
					_y = j;
					break;
				} 
			}
		}*/
		std::cout.setstate(std::ios_base::failbit);
		int tstrike = _fld.StrikeCages(_x, _y, _fleet);
		std::cout.clear();
		if (tstrike == 2 && _fld.ReturnCStat(_x, _y) != "ELIMINATED") {
			hit = true;
			x = _x;
			y = _y;
		}
		return tstrike;
	}
	else {
		if (R) {
			for (int j = y + 1; j < 10; ++j) {
				if (_fld.ReturnCStat(x, j) == "MISSED" || _fld.ReturnCStat(x, j) == "NOTHERE") {
					R = false;
					break;
				}
				else if (_fld.ReturnCStat(x, j) != "DESTROYED") {
					int striked = _fld.StrikeCages(x, j, _fleet);
					//if (striked != 2)						
					if (_fld.ReturnCStat(x, y) == "ELIMINATED") {
						hit = false;
						R = L = U = D = true;
						x = y = -1;
						//return 2;
					}
					return striked;
				}
			}
		}
		if (L) {
			for (int j = y - 1; j >= 0; --j) {
				if (_fld.ReturnCStat(x, j) == "MISSED" || _fld.ReturnCStat(x, j) == "NOTHERE") {
					L = false;
					break;
				}
				else if (_fld.ReturnCStat(x, j) != "DESTROYED") {
					int striked = _fld.StrikeCages(x, j, _fleet);
					//if (striked != 2)						
					if (_fld.ReturnCStat(x, y) == "ELIMINATED") {
						hit = false;
						R = L = U = D = true;
						x = y = -1;
						//return 2;
					}
					return striked;
				}
			}
		}
		if (D) {
			for (int i = x - 1; i >= 0; --i) {
				if (_fld.ReturnCStat(i, y) == "MISSED" || _fld.ReturnCStat(i, y) == "NOTHERE") {
					D = false;
					break;
				}
				else if (_fld.ReturnCStat(i, y) != "DESTROYED") {
					int striked = _fld.StrikeCages(i, y, _fleet);
					//if (striked != 2)						
					if (_fld.ReturnCStat(x, y) == "ELIMINATED") {
						hit = false;
						R = L = U = D = true;
						x = y = -1;
						//return 2;
					}
					return striked;
				}
			}
		}
		if (U) {
			for (int i = x + 1; i < 10; ++i) {
				if (_fld.ReturnCStat(i, y) == "MISSED" || _fld.ReturnCStat(i, y) == "NOTHERE") {
					U = false;
					break;
				}
				else if (_fld.ReturnCStat(i, y) != "DESTROYED") {
					int striked = _fld.StrikeCages(i, y, _fleet);
					//if (striked != 2)						
					if (_fld.ReturnCStat(x, y) == "ELIMINATED") {
						hit = false;
						R = L = U = D = true;
						x = y = -1;
						//return 2;
					}
					return striked;
				}
			}
		}
	}
}

bool Bot::hitted() {
	return hit;
}

int Bot::ReturnDif() {
	return dif;
}

void Bot::SetDif(int _dif) {
	dif = _dif;
}