#include "potion.h"

Potion::Potion(std::string name, double price, int rp) : Item(name, price)
{
	if (rp < 0) {
		std::cout << "Invalid restore points for potion. Setting to 1.\n";
		rp = 1;
	}

	restore_points = rp;
}

Potion::Potion(Potion& potion) : Item(potion.getName(), potion.getPrice())
{
	restore_points = potion.getRestorePoints();
}

Potion::~Potion()
{
}

int Potion::getRestorePoints()
{
	return restore_points;
}