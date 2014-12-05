#ifndef H_THIEF
#define H_THIEF

#include "character.h"

class Thief : public Character {
protected:
	int stealth;
	
	int getAttackPoints();
	int getDefensePoints();

public:
	Thief(Team&);
	Thief(std::string, int, Team&);

	void addStealth(int);

	void attack(Character&);
};

#endif
