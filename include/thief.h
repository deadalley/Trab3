#ifndef H_THIEF
#define H_THIEF

#include "character.h"

class Thief : public Character {
protected:
	int stealth;

public:
	Thief(std::string, int, Team&);

	//Add
	void addStealth(int);

	//Getters
	int getDefensePoints();
	int getAttackPoints();

	void attack(Character&);
};

#endif
