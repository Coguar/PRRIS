#include "pch.h"
#include <algorithm>
#include "OneOfSetSaleRule.h"



OneOfSetSaleRule::OneOfSetSaleRule(std::list<ItemType> types, ItemType saleItemType, int saleInPercent)
	: SetItemRule(types, saleInPercent, false)
{
	m_saleItemType = saleItemType;
	if (std::find(types.begin(), types.end(), saleItemType) == types.end())
	{
		m_saleItemType = types.front();
	}
}

double OneOfSetSaleRule::getPrice()
{
	double price = 0;
	for (auto type : m_ruletypes)
	{
		if (type != m_saleItemType)
		{
			price += Item(type).getPrice();
		}
	}
	return price + Item(m_saleItemType).getPrice() * m_saleK;
}
