#include "pch.h"
#include "SetItemRule.h"


SetItemRule::SetItemRule(std::list<ItemType> types, int saleInPercent, bool isForAllSets)
{
	m_ruletypes = types;
	m_isForAllSets = isForAllSets;
	m_saleK = double(100 - saleInPercent) / 100.0;
}

double SetItemRule::modifyCartifPossibleAndGetPrice(ItemsCart& cart)
{
	if (!isPossible(cart))
	{
		return 0;
	}
	for (auto type : m_ruletypes)
	{
		cart.eraiseItemIfAvailable(type);
	}
	return getPrice();
}

bool SetItemRule::isForAllSets()
{
	return m_isForAllSets;
}

