#ifndef H_WEAPON
#define H_WEAPON

#include "item.h"

class Weapon : public Item {
protected:
	int attack_points;
	double range;
	
public:
	Weapon(std::string, double, int, double);
	Weapon(Weapon&);

	//Getters
	int getAttackPoints();
	int getDefensePoints();
	double getRange();

	void use(Character*);
};

#endif
