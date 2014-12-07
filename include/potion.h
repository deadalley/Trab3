#ifndef H_POTION
#define H_POTION

#include "item.h"
#include "usable.h"

class Potion : public Item, public Usable {
private:
	int restore_points;
	
public:
	Potion(std::string, double, int);
	Potion(Potion&);
	virtual ~Potion();

	//Getters
	int getRestorePoints();
	int getDefensePoints();
	int getAttackPoints();
};

#endif
