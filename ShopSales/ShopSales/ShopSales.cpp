// ShopSales.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include "ItemsCart.h"
#include "OneOfSetSaleRule.h"
#include "RuleGroup.h"
#include "SetItemRule.h"
#include "AllSaleRule.h"
#include "RuleList.h"

//начало программы
int main()
{
	//заполнение листа правил правилами
	RuleList ruleList;
	ruleList.addRule(std::make_shared<SetItemRule>(std::list<ItemType>({ ItemType::A, ItemType::B }), 10));
	ruleList.addRule(std::make_shared<SetItemRule>(std::list<ItemType>({ ItemType::D, ItemType::E }), 5));
	ruleList.addRule(std::make_shared<SetItemRule>(std::list<ItemType>({ ItemType::E, ItemType::F, ItemType::G }), 5));
	ruleList.addRule(std::make_shared<RuleGroup>(std::list<std::shared_ptr<IRule>>({
				std::make_shared<OneOfSetSaleRule>(std::list<ItemType>({ ItemType::A, ItemType::K }), ItemType::K, 5),
				std::make_shared<OneOfSetSaleRule>(std::list<ItemType>({ ItemType::A, ItemType::L }), ItemType::L, 5),
				std::make_shared<OneOfSetSaleRule>(std::list<ItemType>({ ItemType::A, ItemType::M }), ItemType::M, 5)
			})
		)
	);
	ruleList.addRule(std::make_shared<RuleGroup>(std::list<std::shared_ptr<IRule>>({
				std::make_shared<AllSaleRule>(5, 20),
				std::make_shared<AllSaleRule>(4, 10),
				std::make_shared<AllSaleRule>(3, 5)
			})
		)
	);
	
	//заполнение корзины с продуктами
	ItemsCart cart({
		{ItemType::A, 2},
		{ItemType::B, 1},
		{ItemType::C, 1},
		{ItemType::D, 2}
	});
	std::cout << ruleList.executeRulesAndGetPrice(cart);
}