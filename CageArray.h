#pragma once

#include "cage.h"

class CageArray {
public:
	CageArray(){};
	virtual ~CageArray(){};
	virtual void ChangeCages(int _x, int _y, std::string _st) = 0;	 
	virtual void PrintCages() const = 0;
};