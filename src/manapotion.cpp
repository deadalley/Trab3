#include "manapotion.h"
#include "character.h"

ManaPotion::ManaPotion(std::string name, double price, int rp) : Potion(name, price, rp)
{
	setType(ManaPotionType);
}

ManaPotion::~ManaPotion()
{
}

void ManaPotion::use(Character *ch)
{
	if (ch == NULL)
		return;

	std::cout << ch->getName() << " used " << getName() << " (+" << getRestorePoints() << "MP)!" << std::endl;
	ch->addMP(getRestorePoints());
}
