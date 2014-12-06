#ifndef H_ARMOR
#define H_ARMOR

#include "item.h"

class Armor : public Item {
protected:
	int defense_points;
	double weight;

public:
	Armor(std::string, double, int, double);
	Armor(Armor&);

	//Getters
	double getWeight();

	int getDefensePoints();
	int getAttackPoints();

	//Setters
	void setWeight(double);

	void use(Character*);
};

#endif
