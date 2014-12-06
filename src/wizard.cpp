#include "wizard.h"

Wizard::Wizard(std::string name, int wisdom, Team& team) : Character(name, team, WizardType)
{
	if (wisdom < 0){
		std::cout << "Invalid wisdom value (" << wisdom << "). Set to 0." << std::endl;
		this->wisdom = 0;
	}
	
	else this->wisdom = wisdom;
	type = WizardType;
}

int Wizard::getAttackPoints()
{
	return Character::getAttackPoints();
}

int Wizard::getDefensePoints()
{
	return Character::getDefensePoints() + wisdom/2;
}

void Wizard::addWisdom(int wis)
{
	wisdom += wis;
}

void Wizard::attack(Character& ch)
{	
	int damage = 0;

	//Chance de errar completamente o golpe
	if (rand() % (10*XP) == 1){
		std::cout << "MISS! (" << getName() << ")" << std::endl;
		return;
	}

	else {
		damage = this->getAttackPoints() - ch.getDefensePoints() + ((rand()%11)-5);

		if (damage <= 0) damage = 1;

		//Chance de critical strike
		if (rand() % (100*XP) == 2){
			std::cout << "CRITICAL STRIKE! (" << getName() << ")" << std::endl;
			damage = 2*damage;
		}

		std::cout << ch.getName() << " takes -" << damage << " from " << this->getName() << std::endl;
	}

	//Reduz HP do inimigo
	ch.reduceHP(damage);
}
