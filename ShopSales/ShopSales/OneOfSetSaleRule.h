#pragma once
#include "SetItemRule.h"

//класс правила скидки применяемой к 1 выбранному продукту
class OneOfSetSaleRule :
	public SetItemRule
{
public:
	//конструктор
	OneOfSetSaleRule(std::list<ItemType> types, ItemType saleItemType, int saleInPercent);

private:
	//перегрузка метода получения стоимости
	double getPrice() override;

	ItemType m_saleItemType;
};

