#include "weapon.h"

Weapon::Weapon(std::string name, double price, int ap, double ra) : Item(name, price)
{
	//Attack points 1~120
	if(ap > 120) ap = 120;
	if(ap < 1) ap = 1;

	setType(WeaponType);
}

Weapon::Weapon(Weapon& weapon) : Item(weapon.getName(), weapon.getPrice())
{
	attack_points = weapon.getAttackPoints();
	range = weapon.getRange();

	setType(WeaponType);
}

double Weapon::getRange()
{
	return range;
}

int Weapon::getDefensePoints()
{
	return 0;
}

int Weapon::getAttackPoints()
{
	return attack_points;
}

void Weapon::setRange(double r)
{
	range = r;
}

void Weapon::use(Character *ch)
{
}
