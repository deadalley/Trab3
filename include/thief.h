#ifndef H_THIEF
#define H_THIEF

#include "character.h"

class Thief : public Character {
protected:
	int stealth;

public:
	Thief(std::string, int, Team&);

	int getAttackPoints();
	int getDefensePoints();

	void addStealth(int);

	void attack(Character&);
};

#endif
