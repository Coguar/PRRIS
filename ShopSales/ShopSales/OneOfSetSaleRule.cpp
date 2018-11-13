#include "pch.h"
#include <algorithm>
#include "OneOfSetSaleRule.h"



OneOfSetSaleRule::OneOfSetSaleRule(std::list<ItemType> types, ItemType saleItemType, int saleInPercent)
	: SetItemRule(types, saleInPercent, false)
{
	//товар на который будет скидка
	m_saleItemType = saleItemType;
	//если такого товара нет в списке доступных (ошибка разработчика)
	if (std::find(types.begin(), types.end(), saleItemType) == types.end())
	{
		//устанавливаем первый из списка доступных
		m_saleItemType = types.front();
	}
}

double OneOfSetSaleRule::getPrice()
{
	double price = 0;
	//высчитываем полную стоимость
	for (auto type : m_ruletypes)
	{
		//если товар не является выбранным
		if (type != m_saleItemType)
		{
			//прибовляем стоимость
			price += Item(type).getPrice();
		}
	}
	//к общей стоимости прибавляем стоимость выбранного товара со скидкой
	return price + Item(m_saleItemType).getPrice() * m_saleK;
}
