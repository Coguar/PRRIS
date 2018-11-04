#pragma once
#include "ItemsCart.h"

class IRule
{
public:
	virtual double modifyCartifPossibleAndGetPrice(ItemsCart& cart) = 0;
	virtual bool isForAllSets() = 0;
	virtual bool isPossible(ItemsCart& cart) = 0;
	virtual ~IRule() = default;
};
