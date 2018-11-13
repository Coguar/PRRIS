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
	//подсчет общей стоимости без скидок
	for (auto& type : m_ruletypes)
	{
		price += Item(type).getPrice();
	}
	//умножение общей стоимости на скидочный коэфицент (скидка 15% - коэффицент 0.85)
	return price * m_saleK;
}
