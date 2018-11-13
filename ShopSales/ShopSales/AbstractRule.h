#pragma once
#include "IRule.h"

//абстрактное правило, наследуется от интерфейса правила
class AbstractRule :
	public IRule
{
public:
	bool isPossible(ItemsCart& cart) override;
	bool isForAllSets() override;

protected:
	//получение цены со скидкой
	virtual double getPrice();

	std::list<ItemType> m_ruletypes;
	double m_saleK = 0;
};

