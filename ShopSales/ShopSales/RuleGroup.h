#pragma once
#include <list>
#include <memory>
#include "AbstractRule.h"

class RuleGroup :
	public AbstractRule
{
public:
	RuleGroup(std::list<std::shared_ptr<IRule>> const& rules);
	double modifyCartifPossibleAndGetPrice(ItemsCart& cart) override;

private:
	std::list<std::shared_ptr<IRule>> m_rules;
};

