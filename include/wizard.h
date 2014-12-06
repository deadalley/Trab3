#ifndef H_WIZARD
#define H_WIZARD

#include "character.h"

class Wizard : public Character {
protected:
	int wisdom;
	
	int getAttackPoints();
	int getDefensePoints();
	
public:
	Wizard(std::string, int, Team&);
	
	void addWisdom(int);

	void attack(Character&);
};

#endif
