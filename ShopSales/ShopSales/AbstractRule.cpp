#include "pch.h"
#include "AbstractRule.h"


bool AbstractRule::isPossible(ItemsCart & cart)
{
	return cart.checkItems(m_ruletypes);
}

bool AbstractRule::isForAllSets()
{
	return false;
}

double AbstractRule::getPrice()
{
	double price = 0;
	for (auto& type : m_ruletypes)
	{
		price += Item(type).getPrice();
	}
	return price * m_saleK;
}
