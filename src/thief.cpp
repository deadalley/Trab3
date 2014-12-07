#include "thief.h"

Thief::Thief(std::string name, int stealth, Team& team) : Character(name, team, ThiefType)
{
	if (stealth < 0)
		stealth = 0;
	
	this->stealth = stealth;
}

void Thief::addStealth(int st)
{
	stealth += st;
}

int Thief::getDefensePoints()
{
	return Character::getDefensePoints();
}

int Thief::getAttackPoints()
{
	return Character::getAttackPoints() + stealth;
}

void Thief::attack(Character& ch)
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
	ch.addHP(-damage);}
