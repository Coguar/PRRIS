#include "pch.h"
#include "AllSaleRule.h"


AllSaleRule::AllSaleRule(int itemsCount, int saleInPercent)
	: m_itemsCount(itemsCount)
{
	//вычисление скидочного коэфицента
	m_saleK = double(100 - saleInPercent) / 100.0;
}

bool AllSaleRule::isPossible(ItemsCart & cart)
{
	//сравнение кол-ва товаров в корзине с требуемым
	return m_itemsCount <= cart.getItemsCount();
}

double AllSaleRule::modifyCartifPossibleAndGetPrice(ItemsCart & cart)
{
	if (!isPossible(cart))
	{
		//возвращает 0, если скидка не проходит
		return 0;
	}
	//вычисляет цену со скидкой
	double price = cart.getFullPrise() * m_saleK;
	//чистит корзину т.к. скидка применилась ко всем продуктам 
	cart.clearCart();
	return price;
}
