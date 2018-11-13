#include "pch.h"
#include "SetItemRule.h"


SetItemRule::SetItemRule(std::list<ItemType> types, int saleInPercent, bool isForAllSets)
{
	//типы требуемые для скидки
	m_ruletypes = types;
	//для каждого ли набора таких элементов будет скидка
	m_isForAllSets = isForAllSets;
	//скидочный коэфицент
	m_saleK = double(100 - saleInPercent) / 100.0;
}

double SetItemRule::modifyCartifPossibleAndGetPrice(ItemsCart& cart)
{
	if (!isPossible(cart))
	{
		//если скидка невозможно возвращаем 0
		return 0;
	}
	//проходим по типам продуктав заявленых для скидки
	for (auto type : m_ruletypes)
	{
		//убираем их кол-во из корзины
		cart.eraiseItemIfAvailable(type);
	}
	//высчитываем стоимость
	return getPrice();
}

bool SetItemRule::isForAllSets()
{
	return m_isForAllSets;
}

