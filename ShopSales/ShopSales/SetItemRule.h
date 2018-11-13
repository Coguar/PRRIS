#pragma once
#include <list>
#include "AbstractRule.h"

//класс правила на скидку применяемую на набор продуктов одновременно
class SetItemRule :
	public AbstractRule
{
public:
	SetItemRule(std::list<ItemType> types, int saleInPercent, bool isForAllSets = true);

	//перегрузка методов интерфейса
	double modifyCartifPossibleAndGetPrice(ItemsCart& cart) override;
	bool isForAllSets() override;

private:

	bool m_isForAllSets = false;
};

