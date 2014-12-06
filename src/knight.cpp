#include "knight.h"

Knight::Knight(std::string name, int power, Team& team) : Character(name, team, KnightType)
{
	if (power < 0){
		std::cout << "Invalid power value (" << power << "). Set to 0." << std::endl;
		this->power = 0;
	}
	
	else this->power = power;
	type = KnightType;
}

int Knight::getAttackPoints()
{
	return Character::getAttackPoints();
}

int Knight::getDefensePoints()
{
	return Character::getDefensePoints() + power;
}

void Knight::addPower(int pow)
{
	power += pow;
}

void Knight::attack(Character& ch)
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
