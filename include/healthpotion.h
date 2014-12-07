#ifndef H_HEALTHPOTION
#define H_HEALTHPOTION

#include "potion.h"

class HealthPotion : public Potion {
public:
	HealthPotion(std::string, double, int);
	~HealthPotion();
	
	void use(Character *ch);
};

#endif
