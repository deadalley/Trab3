#include "armor.h"

Armor::Armor(std::string name, double price, int dp, double wg) : Item(name, price), Equippable()
{
	//Defense points 1~80
	if(dp > 80) dp = 80;
	if(dp < 1) dp = 1;
	
	defense_points = dp;
	weight = wg;

	setType(ArmorType);

	is_usable = false;

	is_equippable = true;
	is_equipped = false;
}

Armor::Armor(Armor& armor) : Item(armor.getName(), armor.getPrice())
{
	defense_points = armor.getDefensePoints();
	weight = armor.getWeight();

	setType(ArmorType);
}

double Armor::getWeight()
{
	return weight;
}

int Armor::getDefensePoints()
{
	return defense_points;
}

int Armor::getAttackPoints()
{
	return 0;
}

void Armor::setWeight(double w)
{
	weight = w;
}

void Armor::use(Character *ch)
{
}

void Armor::equip(Character* ch)
{
	is_equipped = true;

	std::stringstream aux;
	aux << ">> " << getName() << " equipped.\n";
	aux << ">> " << ch->getName() << "'s speed reduce from " << ch->getSpeed();
	
	ch->setSpeed(ch->getSpeed()*exp(-pow((this->getWeight()/20), 2)));
	aux << " to " << ch->getSpeed() << "\n";

	std::cout << aux.str();
}

void Armor::unequip(Character* ch)
{
	//Remove speed
	is_equipped = false;

	std::cout << ">> " << getName() << " unequipped.\n";
}