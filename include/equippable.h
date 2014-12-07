#ifndef H_EQUIPPABLE
#define H_EQUIPPABLE

#include "character.h"

//Class the defines the behavior of equippable items
class Equippable {
protected:
	bool is_equipped;
public:
	bool isEquipped();

	virtual void equip(Character*) = 0;
	virtual void unequip(Character*) = 0;
};

#endif