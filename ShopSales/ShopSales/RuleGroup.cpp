#include "pch.h"
#include "RuleGroup.h"


RuleGroup::RuleGroup(std::list<std::shared_ptr<IRule>> const & rules)
	: m_rules(rules)
{
}

double RuleGroup::modifyCartifPossibleAndGetPrice(ItemsCart & cart)
{
	for (auto& rule : m_rules)
	{
		if (rule && rule->isPossible(cart))
		{
			return rule->modifyCartifPossibleAndGetPrice(cart);
		}
	}
	return 0.0;
}
