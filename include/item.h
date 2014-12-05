#ifndef H_ITEM
#define H_ITEM

#include <iostream>
#include <string>

//Identifica os tipos de item
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

	//Identifica qual o tipo do item
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
	//Os métodos getAP e getDP mudaram de protected para public para
	//funcionarem corretamente na classe inventory
	virtual int getAttackPoints();
	virtual int getDefensePoints();

	virtual void use(Character *ch) = 0;

	//Funções auxiliares
	ItemType getType();
};

#endif
