#include "item.h"

Item::Item(std::string name, double price)
{
	while (name.size() == 0){
		std::cout << "Insert valid Item name: ";
		std::cin >> name;
	}
	
	while (price <= 0){
		std::cout << "Insert valid Item price: ";
		std::cin >> price;
	}
		
	this->name = name;
	this->price = price;
}

Item::Item(Item& item)
{
	this->name = item.getName();
	this->price = item.getPrice();
}

Item::~Item()
{
}

int Item::getAttackPoints()
{
	return 0;
}

int Item::getDefensePoints()
{
	return 0;
}

std::string Item::getName()
{
	return name;
}

double Item::getPrice()
{
	return price;
}

//Retorna o tipo do item (armor, weapon ou potion)
ItemType Item::getType()
{
	return type;
}

//Seta o tipo do item
void Item::setType(ItemType item_type)
{
	type = item_type;
}