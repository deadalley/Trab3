#ifndef H_KNIGHT
#define H_KNIGHT

#include "character.h"

class Knight : public Character {
protected:
	int power;
	
public:
	Knight(std::string, int, Team&);
	
	//Add
	void addPower(int);

	//Getters
	int getDefensePoints();
	int getAttackPoints();

	void attack(Character&);
};

#endif
