#include "knight.h"

Knight::Knight(std::string name, int power, Team& team) : Character(name, team, KnightType)
{
	if (power < 0)
		power = 0;
	
	this->power = power;
}

void Knight::addPower(int pow)
{
	power += pow;
}

int Knight::getDefensePoints()
{
	return Character::getDefensePoints() + power;
}

int Knight::getAttackPoints()
{
	return Character::getAttackPoints();
}

void Knight::attack(Character& ch)
{	
	int damage = 0;

	//Chance of missing
	if (rand() % (10*XP) == 1){
		std::cout << "MISS! (" << getName() << ")" << std::endl;
		return;
	}

	else {
		damage = this->getAttackPoints() - ch.getDefensePoints() + ((rand()%11)-5);

		if (damage <= 0) damage = 1;

		//Chance of critical strike
		if (rand() % (100*XP) == 2){
			std::cout << "CRITICAL STRIKE! (" << getName() << ")" << std::endl;
			damage = 2*damage;
		}

		std::cout << ch.getName() << " takes -" << damage << " from " << this->getName() << std::endl;
	}

	//Reduce enemy's HP
	ch.addHP(-damage);
}
