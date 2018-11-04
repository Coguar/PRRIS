#pragma once
#include <list>
#include <memory>
#include "IRule.h"
#include "ItemsCart.h"

class RuleList
{
public:
	void addRule(std::shared_ptr<IRule> rule);
	double executeRulesAndGetPrice(ItemsCart& cart);

private:
	std::list<std::shared_ptr<IRule>> m_rules;
};

