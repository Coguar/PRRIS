#include "pch.h"
#include "RuleList.h"

void RuleList::addRule(std::shared_ptr<IRule> rule)
{
	m_rules.push_back(rule);
}

double RuleList::executeRulesAndGetPrice(ItemsCart& cart)
{
	double price = 0;
	for (auto& rule : m_rules)
	{
		if (rule->isForAllSets())
		{
			while (rule->isPossible(cart))
			{
				price += rule->modifyCartifPossibleAndGetPrice(cart);
			}
		}
		else
		{
			price += rule->modifyCartifPossibleAndGetPrice(cart);
		}
	}
	return price + cart.getFullPrise();
}
