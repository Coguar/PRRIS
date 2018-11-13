#pragma once
#include <list>
#include <memory>
#include "AbstractRule.h"

//класс группы правил
//в такой группе правил применится только первое подходящее правило
class RuleGroup :
	public AbstractRule
{
public:
	RuleGroup(std::list<std::shared_ptr<IRule>> const& rules);
	//перегрузка метода модификации корзины и получения стоимости
	double modifyCartifPossibleAndGetPrice(ItemsCart& cart) override;

private:
	std::list<std::shared_ptr<IRule>> m_rules;
};

