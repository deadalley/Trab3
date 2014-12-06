#include "armor.h"

Armor::Armor(std::string name, double price, int dp, double wg) : Item(name, price)
{
	//Defense points 1~80
	if(dp > 80) dp = 80;
	if(dp < 1) dp = 1;
	
	defense_points = dp;
	weight = wg;

	setType(ArmorType);
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
