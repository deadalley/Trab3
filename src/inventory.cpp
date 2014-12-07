#include "inventory.h"
#include "armor.h"
#include "character.h"

Inventory::Inventory()
{
	gold = 100;
	total_defense = 0;
	total_attack = 0;
	spaces = 8;
}

Inventory::~Inventory()
{
	std::vector<Item*>::iterator it;
	for(it = items.begin(); it != items.end(); it++){
		items.erase(it);
	}
}

double Inventory::getTotalGold()
{
	return gold;
}

int Inventory::getAvailableSpace()
{
	return spaces - items.size();
}

int Inventory::getTotalDefensePoints()
{
	return total_defense;
}

int Inventory::getTotalAttackPoints()
{
	return total_attack;
}

Character* Inventory::getParent()
{
	return parent;
}

void Inventory::setSpaces(int s)
{
	if(s < 0) return;
	spaces = s;
}

void Inventory::setParent(Character *parent)
{
	this->parent = parent;
}

void Inventory::spendGold(double g)
{
	if(g > gold){
		std::stringstream aux;
		aux << ">> " << parent->getName() << " does not have " << g << "G to spend.";
		aux << " Total gold (" << gold << "G).\n";
		std::cout << aux.str();
		return;
	}
	gold -= g;
}

void Inventory::earnGold(double g)
{	
	gold += g;
	std::stringstream aux;
	aux << ">> " << parent->getName() << " earned " << g << "G." << std::endl;
	std::cout << aux.str();
}

Item* Inventory::searchItem(std::string item_name)
{
	std::vector<Item*>::iterator it;	
	for(it = items.begin(); it != items.end(); it++){
		if ((*it)->getName() == item_name)
			return (*it);
	}

	return NULL;
}

Item* Inventory::searchItem(int k)
{
	if(k > items.size() || k < 0) return NULL;

	return items.at(k);
}

void Inventory::insertItem(Item* item)
{
	if(isFull()) return;
	
	items.push_back(item);
}

void Inventory::removeItem(std::string item_name)
{
	if(isEmpty()) return;

	std::vector<Item*>::iterator it;
	int i = 0;
	for (it = items.begin(); it != items.end(); it++){
		if (item_name.compare((*it)->getName()) == 0){
			//If the item is equipped, updates total_defense and total_attack
			std::cout << ">> Deleting " << (*it)->getName() << std::endl;
			std::stringstream s;
			s << items.size();
			std::cout << ">> Size of items: " << s.str() << std::endl;
			std::stringstream a;
			a << i;
			std::cout << ">> it at " << a.str() << std::endl;
			i++;
			if((*it)->isEquippable()){
				Equippable *eq = dynamic_cast<Equippable*>(*it);
				eq->unequip(parent);

				total_attack -= (*it)->getAttackPoints();
				total_defense -= (*it)->getDefensePoints();
			}
			items.erase(it);
		}
	}
}

void Inventory::removeItem(int k)
{
	if(k > items.size() || k < 0) return;

	std::vector<Item*>::iterator it = items.begin() + k;
	//If the item is equipped, updates total_defense and total_attack
	if((*it)->isEquippable()){
		Equippable *eq = dynamic_cast<Equippable*>((*it));
		eq->unequip(parent);

		total_attack -= (*it)->getAttackPoints();
		total_defense -= (*it)->getDefensePoints();
	}

	items.erase(it);
}

int Inventory::getItemsSize()
{
	return items.size();
}

bool Inventory::isEmpty()
{
	if(items.size()==0) return true;
	return false;
}

bool Inventory::isFull()
{
	if(items.size() == spaces) return true;
	return false;
}