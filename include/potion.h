#ifndef H_POTION
#define H_POTION

#include "item.h"

class Potion : public Item {
private:
	int restore_points;
	
public:
	Potion(std::string, double, int);
	Potion(Potion&);
	virtual ~Potion();

	//Getters
	int getRestorePoints();
	
	virtual void use(Character *ch) = 0;
};

#endif
