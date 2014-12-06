#ifndef H_KNIGHT
#define H_KNIGHT

#include "character.h"

class Knight : public Character {
protected:
	int power;

	int getAttackPoints();
	int getDefensePoints();
	
public:
	Knight(std::string, int, Team&);
	
	void addPower(int);

	void attack(Character&);
};

#endif
