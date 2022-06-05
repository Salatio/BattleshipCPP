#include "cage.h"

Cage::Cage(): local_status("INIT"), X(-1), Y(-1) {} //Initializated
void Cage::ChangeStatus(std::string _st) {
	local_status = _st;
}

std::string Cage::Status() const {
	return local_status;
}

int Cage::ReturnX() const {
	return X;
}

int Cage::ReturnY() const {
	return Y;
}

void Cage::SetXY(int _x, int _y) {
	X = _x;
	Y = _y;
}
