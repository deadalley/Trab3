#ifndef H_WEAPON
#define H_WEAPON

#include "item.h"
#include "equippable.h"

class Weapon : public Item, public Equippable {
protected:
	int attack_points;
	double range;
	
public:
	Weapon(std::string, double, int, double);
	Weapon(Weapon&);

	//Getters
	double getRange();

	int getDefensePoints();
	int getAttackPoints();

	//Setters
	void setRange(double);

	void equip(Character*);
	void unequip(Character*);
	void use(Character*);
};

#endif
