#include "pch.h"
#include "Item.h"


Item::Item(ItemType type)
{
	m_type = type;
	m_price = PriceList.find(type)->second;
}

double Item::getPrice() const
{
	return m_price;
}

ItemType Item::getType() const
{
	return m_type;
}

bool Item::isChecked() const
{
	return m_isChecked;
}

void Item::setChecked(bool check)
{
	m_isChecked = check;
}
