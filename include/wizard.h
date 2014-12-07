#ifndef H_WIZARD
#define H_WIZARD

#include "character.h"

class Wizard : public Character {
protected:
	int wisdom;
	
public:
	Wizard(std::string, int, Team&);
	
	//Add
	void addWisdom(int);

	//Getters
	int getDefensePoints();
	int getAttackPoints();

	void attack(Character&);
};

#endif
