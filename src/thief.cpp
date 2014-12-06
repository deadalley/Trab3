#include "thief.h"

Thief::Thief(std::string name, int stealth, Team& team) : Character(name, team, ThiefType)
{
	if (stealth < 0){
		std::cout << "Invalid stealth value (" << stealth << "). Set to 0." << std::endl;
		this->stealth = 0;
	}
	
	else this->stealth = stealth;
	type = ThiefType;
}

int Thief::getAttackPoints()
{
	return Character::getAttackPoints() + stealth;
}

int Thief::getDefensePoints()
{
	return Character::getDefensePoints();
}

void Thief::addStealth(int st)
{
	stealth += st;
}

void Thief::attack(Character& ch)
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
