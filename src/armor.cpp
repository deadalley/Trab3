#include "armor.h"

Armor::Armor(std::string name, double price, int dp, double wg) : Item(name, price)
{
	while (dp > 20 || dp < 1){
		std::cout << "Insert valid Armor defense points (1~20): ";
		std::cin >> dp;
	}
	
	while (wg > 20 || wg < 1){
		std::cout << "Insert valid Armor weight (1~20): ";
		std::cin >> wg;
	}
	
	defense_points = dp;
	weight = wg;

	setType(ArmorType);
}

Armor::Armor(Armor& armor) : Item(armor.getName(), armor.getPrice())
{
	defense_points = armor.getDefensePoints();
	weight = armor.getWeight();
}

int Armor::getDefensePoints()
{
	return defense_points;
}

int Armor::getAttackPoints()
{
	return 0;
}

double Armor::getWeight()
{
	return weight;
}

//A função use não tem implementação em armor
void Armor::use(Character *ch)
{
}
