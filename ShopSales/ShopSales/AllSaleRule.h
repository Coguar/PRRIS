#pragma once
#include "AbstractRule.h"

//класс скидки "На Все"
class AllSaleRule :
	public AbstractRule
{
public:
	AllSaleRule(int itemsCount, int saleInPercent);
	
	//перегрузка методов интерфейса
	bool isPossible(ItemsCart& cart) override;
	double modifyCartifPossibleAndGetPrice(ItemsCart& cart) override;

private:
	int m_itemsCount = 0;
};

