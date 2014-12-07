#include "healthpotion.h"
#include "character.h"

HealthPotion::HealthPotion(std::string name, double price, int rp) : Potion(name, price, rp)
{
	setType(HealthPotionType);
}

HealthPotion::~HealthPotion()
{
}

void HealthPotion::use(Character *ch)
{
	if (ch == NULL)
		return;

	std::cout << ">> " << ch->getName() << " used " << getName() << " (+" << getRestorePoints() << "HP)!" << std::endl;
	ch->addHP(getRestorePoints());

	ch->removeFromInventory(this);
}
