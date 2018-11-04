#pragma once
#include <list>
#include "AbstractRule.h"

class SetItemRule :
	public AbstractRule
{
public:
	SetItemRule(std::list<ItemType> types, int saleInPercent, bool isForAllSets = true);

	double modifyCartifPossibleAndGetPrice(ItemsCart& cart) override;
	bool isForAllSets() override;

private:

	bool m_isForAllSets = false;
};

