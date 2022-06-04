#include "field.h"

Field::Field() : ShipCount(0), CageCount(100) {};

void Field::PrintCages(int v) const {	

}
void Field::ChangeCages(int _x, int _y, std::string _st) {
		ShipField[_x][_y].ChangeStatus(_st);	
}

void Field::ChangeField(int _x, int _y, Ship * _fleet, int n) {
	int cnt = 0;
	std::string _st = "ACTIVE";
	if (_fleet[n].ReturnDirection() == "RIGHT") {
		while (cnt++ < _fleet[n].ReturnDecks()) {
			ChangeCages(_x, _y++, _st);
		}
	}
	else if (_fleet[n].ReturnDirection() == "DOWN") {
		while (cnt++ < _fleet[n].ReturnDecks()) {
			ChangeCages(_x++, _y, _st);
		}
	}
	else if (_fleet[n].ReturnDirection() == "LEFT") {
		while (cnt++ < _fleet[n].ReturnDecks()) {
			ChangeCages(_x, _y--, _st);
		}
	}
	else if (_fleet[n].ReturnDirection() == "UP") {
		while (cnt++ < _fleet[n].ReturnDecks()) {
			ChangeCages(_x--, _y, _st);
		}
	}
}



int Field::PutShip(int _x, int _y, Ship* _fleet, int n) {
	int excode = 0; // exit code
	if (!_fleet[n].ReturnBC()) {
		bool offsite = false;
		bool nplaced = true; //not placed
		if (_x < 0 || _x > 9 || _y < 0 || _y > 9)
			offsite = true; 
		else if (_fleet[n].ReturnDirection() == "RIGHT") {
			if (_y + (_fleet[n].ReturnDecks() - 1) > 9)
				offsite = true;
			for (int i = _x - 1; i <= _x + 1; ++i) {
				for (int j = _y - 1; j <= _y + _fleet[n].ReturnDecks(); ++j) {
					if (i >= 0 && i <= 9 && j >= 0 && j <= 9) {
						if (ShipField[i][j].Status() == "ACTIVE") {
							nplaced = false;
							break;
						}
					}
				}
			}
		}
		else if (_fleet[n].ReturnDirection() == "DOWN") {
			if (_x + (_fleet[n].ReturnDecks() - 1) > 9)
				offsite = true;
			for (int i = _x - 1; i <= _x + _fleet[n].ReturnDecks(); ++i) {
				for (int j = _y - 1; j <= _y + 1; ++j) {
					if (i >= 0 && i <= 9 && j >= 0 && j <= 9) {
						if (ShipField[i][j].Status() == "ACTIVE") {
							nplaced = false;
							break;
						}
					}
				}
			}
		}
		else if (_fleet[n].ReturnDirection() == "LEFT") {
			if (_y - (_fleet[n].ReturnDecks() - 1) < 0)
				offsite = true;
			for (int i = _x - 1; i <= _x + 1; ++i) {
				for (int j = _y + 1; j >= _y - _fleet[n].ReturnDecks(); --j) {
					if (i >= 0 && i <= 9 && j >= 0 && j <= 9) {
						if (ShipField[i][j].Status() == "ACTIVE") {
							nplaced = false;
							break;
						}
					}
				}
			}
		}
		else if (_fleet[n].ReturnDirection() == "UP") {
			if (_x - (_fleet[n].ReturnDecks() - 1) < 0)
				offsite = true;
			for (int i = _x + 1; i >= _x - _fleet[n].ReturnDecks(); --i) {
				for (int j = _y - 1; j <= _y + 1; ++j) {
					if (i >= 0 && i <= 9 && j >= 0 && j <= 9) {
						if (ShipField[i][j].Status() == "ACTIVE") {
							nplaced = false;
							break;
						}
					}
				}
			}
		}		

		if (!offsite) { //if ship can be placed 
			if (nplaced) {
				ShipCount++;				
				_fleet[n].BCplus();
				ChangeField(_x, _y, _fleet, n);
				_fleet[n].InitShip(_x, _y);
				excode = 1;
			}
			else
				std::cout << "Area is busy \n";
		}
		else
			std::cout << "offsite! \n";
	}
	else
		std::cout << "Ship has been already placed \n";
	return excode;
}
int Field::StrikeCages(int _x, int _y, Ship* _fleet) {	
	int excode = 0; //exit code
	if (!(_x < 0 || _x > 9 || _y < 0 || _y > 9)) {
		if (ShipField[_x][_y].Status() == "DESTROYED" || ShipField[_x][_y].Status() == "MISSED" || ShipField[_x][_y].Status() == "ELIMINATED" || ShipField[_x][_y].Status() == "NOTHERE") {
			std::cout << "The spot has been already striked \n";
			return 0;
		}
		bool missed = true;
		for (int i = 0; i < 10; ++i) { //!!!
			for (int j = 0; j < _fleet[i].ReturnDecks(); ++j) {
				if ((_x == _fleet[i].ReturnX(j)) && (_y == _fleet[i].ReturnY(j))) { //ship with the coordinates has been found
					std::string _st = "DESTROYED";
					ChangeCages(_x, _y, _st);
					_fleet[i].ChangeCages(_x, _y, _st);
					excode = 2;
					CageCount--;
					if (_fleet[i].ReturnHealth() == 0) {
						ShipCount--;						
						int cnt = 0;
						std::string _st = "ELIMINATED";
						if (_fleet[i].ReturnDirection() == "RIGHT") {
							while (cnt++ < _fleet[i].ReturnDecks()) {
								ChangeCages(_x, _fleet[i].ReturnY(cnt - 1), _st);
							}
							int a = i;
							for (int i = _fleet[a].ReturnX(0) - 1; i <= _fleet[a].ReturnX(0) + 1; ++i) {
								for (int j = _fleet[a].ReturnY(0) - 1; j <= _fleet[a].ReturnY(0) + _fleet[a].ReturnDecks(); ++j) {
									if (i >= 0 && i <= 9 && j >= 0 && j <= 9) {
										if (ShipField[i][j].Status() == "INIT") {
											ChangeCages(i, j, "NOTHERE");
											CageCount--;
										}
									}
								}
							}
						}
						else if (_fleet[i].ReturnDirection() == "DOWN") {
							while (cnt++ < _fleet[i].ReturnDecks()) {
								ChangeCages(_fleet[i].ReturnX(cnt - 1), _y, _st);
							}
							int a = i;
							for (int i = _fleet[a].ReturnX(0) - 1; i <= _fleet[a].ReturnX(0) + _fleet[a].ReturnDecks(); ++i) {
								for (int j = _fleet[a].ReturnY(0) - 1; j <= _fleet[a].ReturnY(0) + 1; ++j) {
									if (i >= 0 && i <= 9 && j >= 0 && j <= 9) {
										if (ShipField[i][j].Status() == "INIT") {
											ChangeCages(i, j, "NOTHERE");
											CageCount--;
										}
									}
								}
							}
						}
						else if (_fleet[i].ReturnDirection() == "LEFT") {
							int temp = _fleet[i].ReturnDecks() - 1;
							while (cnt++ < _fleet[i].ReturnDecks()) {
								ChangeCages(_x, _fleet[i].ReturnY(temp--), _st);
							}
							int a = i;
							for (int i = _fleet[a].ReturnX(0) - 1; i <= _fleet[a].ReturnX(0) + 1; ++i) {
								for (int j = _fleet[a].ReturnY(0) + 1; j >= _fleet[a].ReturnY(_fleet[a].ReturnDecks()-1) -1; --j) {
									if (i >= 0 && i <= 9 && j >= 0 && j <= 9) {
										if (ShipField[i][j].Status() == "INIT") {
											ChangeCages(i, j, "NOTHERE");
											CageCount--;
										}
									}
								}
							}
						}
						else if (_fleet[i].ReturnDirection() == "UP") {
							int temp = _fleet[i].ReturnDecks() - 1;
							while (cnt++ < _fleet[i].ReturnDecks()) {
								ChangeCages(_fleet[i].ReturnX(temp--), _y, _st);
							}
							int a = i;
							for (int i = _fleet[a].ReturnX(0) + 1; i >= (_fleet[a].ReturnX(0) - _fleet[a].ReturnDecks()); --i) {
								for (int j = _fleet[a].ReturnY(0) - 1; j <= _fleet[a].ReturnY(0) + 1; ++j) {
									if (i >= 0 && i <= 9 && j >= 0 && j <= 9) {
										if (ShipField[i][j].Status() == "INIT") {
											ChangeCages(i, j, "NOTHERE");
											CageCount--;
										}
									}
								}
							}
						}						
					}
					missed = false;
					break;
				}
			}
		}
		if (missed) {
			ChangeCages(_x, _y, "MISSED");
			excode = 1;
			CageCount--;
		}
	}
	else
		std::cout << "Out of field range! \n";
	return excode;
}

int Field::ReturnSCount() {
	return ShipCount;
}

std::string Field::ReturnCStat(int _x, int _y) {
	if (_x >= 0 || _x <= 9 || _y >= 0 || _y <= 9)
		return ShipField[_x][_y].Status();
	else
		return 0;
}

int Field::ReturnCCount() {
	return CageCount;
}

std::ostream& operator<<(std::ostream& out, const Field& fld) {
	fld.PrintCages(0);
	return out;
}