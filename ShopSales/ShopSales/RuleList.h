#pragma once
#include <list>
#include <memory>
#include "IRule.h"
#include "ItemsCart.h"

//список правил
class RuleList
{
public:
	//добавление правила
	void addRule(std::shared_ptr<IRule> rule);
	//выполнение правила и получение скидочной цены
	double executeRulesAndGetPrice(ItemsCart& cart);

private:
	std::list<std::shared_ptr<IRule>> m_rules;
};

