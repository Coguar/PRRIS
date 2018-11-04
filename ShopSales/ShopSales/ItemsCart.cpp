#include "pch.h"
#include "ItemsCart.h"




ItemsCart::ItemsCart(std::map<ItemType, int> const & itemsCount)
{
	m_itemsCount = itemsCount;
}

ItemsCart::~ItemsCart()
{
}

void ItemsCart::clearCart()
{
	m_itemsCount.clear();
}

int ItemsCart::getItemsCount() const
{
	int count = 0;
	for (auto& it : m_itemsCount)
	{
		count += it.second;
	}
	return count;
}

bool ItemsCart::eraiseItemIfAvailable(ItemType type)
{
	auto item = m_itemsCount.find(type);
	if (item != m_itemsCount.end() && item->second > 0) {
		item->second -= 1;
		return true;
	}
	return false;
}

bool ItemsCart::checkItems(std::list<ItemType>& types)
{
	for (auto& type : types)
	{
		auto it = m_itemsCount.find(type);
		if (it == m_itemsCount.end() || it->second <= 0)
		{
			return false;
		}
	}
	return true;
}

double ItemsCart::getFullPrise() const
{
	double fullPrice = 0;
	for (auto& it : m_itemsCount) 
	{
		if (it.second > 0)
		{
			fullPrice += Item(it.first).getPrice() * it.second;
		}
	}
	return fullPrice;
}
