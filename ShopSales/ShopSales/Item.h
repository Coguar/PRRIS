#pragma once
#include <map>

//тип продуктов
enum class ItemType{
	A = 0,
	B,
	C, 
	D,
	E,
	F,
	G,
	H,
	I,
	J,
	K,
	L,
	M
};

// карта цен на продукты
namespace {
	static const std::map<ItemType, double> PriceList = {
		{ItemType::A, 5.0}, {ItemType::B, 7.0}, {ItemType::C, 6.0}, {ItemType::D, 10.0},
		{ItemType::E, 11.0}, {ItemType::F, 8.0}, {ItemType::G, 9.0}, {ItemType::H, 12.0},
		{ItemType::I, 14.0}, {ItemType::J, 20.0}, {ItemType::K, 10.0}, {ItemType::L, 7.0},
		{ItemType::M, 4.0}
	};
}

//класс продукта
class Item
{
public:
	Item(ItemType type);
	~Item() = default;
	//получение цены
	double getPrice() const;
	//получение типа
	ItemType getType() const;
	bool isChecked() const;

	void setChecked(bool check);

private:
	double m_price = 0.0;
	ItemType m_type;
	bool m_isChecked = false;
};

