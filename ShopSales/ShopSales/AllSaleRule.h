#pragma once
#include "AbstractRule.h"
class AllSaleRule :
	public AbstractRule
{
public:
	AllSaleRule(int itemsCount, int saleInPercent);
	
	bool isPossible(ItemsCart& cart) override;
	double modifyCartifPossibleAndGetPrice(ItemsCart& cart) override;

private:
	int m_itemsCount = 0;
};

