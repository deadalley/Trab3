#include "weapon.h"

Weapon::Weapon(std::string name, double price, int ap, double ra) : Item(name, price)
{
	while (ap > 9 || ap < 1){
		std::cout << "Insert valid Item attack points (1~9): ";
		std::cin >> ap;
	}
	
	attack_points = ap;
	range = ra;

	setType(WeaponType);
}

Weapon::Weapon(Weapon& weapon) : Item(weapon.getName(), weapon.getPrice())
{
	attack_points = weapon.getAttackPoints();
	range = weapon.getRange();
}

int Weapon::getAttackPoints()
{
	return attack_points;
}

int Weapon::getDefensePoints()
{
	return 0;
}

double Weapon::getRange()
{
	return range;
}

void Weapon::use(Character *ch)
{
}
