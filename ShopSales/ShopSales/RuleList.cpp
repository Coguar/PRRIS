#include "pch.h"
#include "RuleList.h"

void RuleList::addRule(std::shared_ptr<IRule> rule)
{
	m_rules.push_back(rule);
}

double RuleList::executeRulesAndGetPrice(ItemsCart& cart)
{
	//переменная конечной стоимости
	double price = 0;
	//проход по всем правилам
	for (auto& rule : m_rules)
	{
		//проверка для каждого ли набора продуктов работает правило
		if (rule->isForAllSets())
		{
			//проверка возможно ли применение скидки
			while (rule->isPossible(cart))
			{
				//если возможно убираем "пробитые" продукты из корзины и прибавляем их цену со скидкой
				price += rule->modifyCartifPossibleAndGetPrice(cart);
			}
		}
		else
		{
			//единажды применяем скидку и добавляем сумму если получилось
			price += rule->modifyCartifPossibleAndGetPrice(cart);
		}
	}
	//возвращаем цену со скидкой + полную цену на нескидочные продукты
	return price + cart.getFullPrise();
}
