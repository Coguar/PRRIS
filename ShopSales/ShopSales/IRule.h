#pragma once
#include "ItemsCart.h"

//интерфейс правила
class IRule
{
public:
	//модифицирует корзину если это возможно (вычитает количество продуктов по которым применена скидка)
	virtual double modifyCartifPossibleAndGetPrice(ItemsCart& cart) = 0;
	//проверяет для всех ли наборов требуемых продуктов должна применяться скидка 
	virtual bool isForAllSets() = 0;
	//возможно ли применение скидки
	virtual bool isPossible(ItemsCart& cart) = 0;
	virtual ~IRule() = default;
};
