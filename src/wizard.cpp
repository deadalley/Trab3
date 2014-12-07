#include "wizard.h"

Wizard::Wizard(std::string name, int wisdom, Team& team) : Character(name, team, WizardType)
{
	if (wisdom < 0)
		wisdom = 0;
	
	this->wisdom = wisdom;
}

void Wizard::addWisdom(int wis)
{
	wisdom += wis;
}

int Wizard::getDefensePoints()
{
	return Character::getDefensePoints() + wisdom/2;
}

int Wizard::getAttackPoints()
{
	return Character::getAttackPoints();
}

void Wizard::attack(Character& ch)
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
