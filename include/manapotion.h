#ifndef H_MANAPOTION
#define H_MANAPOTION

#include "potion.h"

class ManaPotion : public Potion {
public:
	ManaPotion(std::string, double, int);
	~ManaPotion();
	
	void use(Character *ch);
};

#endif