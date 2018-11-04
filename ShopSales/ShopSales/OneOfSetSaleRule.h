#pragma once
#include "SetItemRule.h"

class OneOfSetSaleRule :
	public SetItemRule
{
public:
	OneOfSetSaleRule(std::list<ItemType> types, ItemType saleItemType, int saleInPercent);

private:
	double getPrice() override;

	ItemType m_saleItemType;
};

