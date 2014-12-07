#include "item.h"

Item::Item(std::string name, double price)
{	
	if(price < 0) price = 1;
		
	this->name = name;
	this->price = price;
}

Item::Item(Item& item)
{
	this->name = item.getName();
	this->price = item.getPrice();

	this->is_equippable = item.isEquippable();
	this->is_usable = item.isUsable();
}

Item::~Item()
{
}

std::string Item::getName()
{
	return name;
}

double Item::getPrice()
{
	return price;
}

ItemType Item::getType()
{
	return type;
}

bool Item::isEquippable()
{
	return is_equippable;
}

bool Item::isUsable()
{
	return is_usable;
}

void Item::setType(ItemType item_type)
{
	type = item_type;
}