#pragma once
#include "IRule.h"
class AbstractRule :
	public IRule
{
public:
	bool isPossible(ItemsCart& cart) override;
	bool isForAllSets() override;

protected:
	virtual double getPrice();

	std::list<ItemType> m_ruletypes;
	double m_saleK = 0;
};

