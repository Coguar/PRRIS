#include "pch.h"
#include "AllSaleRule.h"


AllSaleRule::AllSaleRule(int itemsCount, int saleInPercent)
	: m_itemsCount(itemsCount)
{
	m_saleK = double(100 - saleInPercent) / 100.0;
}

bool AllSaleRule::isPossible(ItemsCart & cart)
{
	return m_itemsCount <= cart.getItemsCount();
}

double AllSaleRule::modifyCartifPossibleAndGetPrice(ItemsCart & cart)
{
	if (!isPossible(cart))
	{
		return 0;
	}
	double price = cart.getFullPrise() * m_saleK;
	cart.clearCart();
	return price;
}
