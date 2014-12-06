#ifndef H_ITEM
#define H_ITEM

#include <iostream>
#include <string>

enum ItemType {
	ArmorType,
	HealthPotionType,
	ManaPotionType,
	WeaponType
};

class Character;

class Item {
private:
	std::string name;
	double price;

	ItemType type;

protected:
	void setType(ItemType);

public:
	Item(std::string, double);
	Item(Item&);
	virtual ~Item();

	//Getters
	std::string getName();
	double getPrice();
	ItemType getType();
	
	virtual int getDefensePoints() = 0;
	virtual int getAttackPoints() = 0;

	virtual void use(Character *ch) = 0;
};

#endif