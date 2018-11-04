#pragma once
#include <list>
#include <map>
#include "Item.h"

class ItemsCart
{
public:
	ItemsCart(std::map<ItemType, int> const& itemsCount);
	~ItemsCart();
	void clearCart();
	int getItemsCount() const;
	bool eraiseItemIfAvailable(ItemType type);
	bool checkItems(std::list<ItemType>& types);
	double getFullPrise() const;

private:
	std::map<ItemType, int> m_itemsCount;
};

