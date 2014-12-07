#include "character.h"
#include "team.h"

Character::Character(std::string name, Team& team, CharacterType type)
{
	alias = name;
	HP = 100;
	MP = 100;
	XP = 1;

	strength = 25;
	speed = 25;
	dexterity = 25;
	constitution = 25;

	power = 30;
	accuracy = 30;

	this->team = &team;
	this->type = type;

	my_items.setParent(this);

	has_armor = false;
	equipped_weapons = 0;
}

Character::~Character()
{
}

void Character::addXP(int xp)
{
	//Maximum allowed XP = 100
	if (xp + XP > 100){
		XP = 100;
		return;
	}

	if (xp + XP < 0){
		XP = 0;
		return;
	}

	XP += xp;
}

void Character::addMP(int mp)
{
	//Maximum allowed MP = 100
	if (mp + MP > 100){
		MP = 100;
		return;
	}

	if (mp + MP < 0){
		MP = 0;
		return;
	}

	MP += mp;
}

void Character::addHP(int hp)
{
	//Maximum allowed HP = 100
	if (hp + HP > 100){
		HP = 100;
		return;
	}

	if (hp + HP < 0){
		HP = 0;
		return;
	}

	HP += hp;
}

std::string Character::getName()
{
	return alias;
}

int Character::getStrength()
{
	return strength;
}

int Character::getSpeed()
{
	return speed;
}

int Character::getDexterity()
{
	return dexterity;
}

int Character::getConstitution()
{
	return constitution;
}

int Character::getXP()
{
	return XP;
}

int Character::getHP()
{
	return HP;
}

int Character::getMP()
{
	return MP;
}

double Character::getTotalGold()
{
	return my_items.getTotalGold();
}

int Character::getDefensePoints()
{
	return ((0.5*constitution) + (0.2*speed) + (0.3*dexterity) + my_items.getTotalDefensePoints()) * (XP/2);
}

int Character::getAttackPoints()
{
	return ((0.5*strength) + (0.3*dexterity) + (0.2*speed) + my_items.getTotalAttackPoints()) * (XP/3);
}

void Character::setName(std::string name)
{
	alias = name;
}

void Character::setTeam(Team* team)
{
	this->team = team;
}

void Character::setStrength(int st)
{
	strength = st;
}

void Character::setSpeed(int sp)
{
	speed = sp;
}

void Character::setDexterity(int dt)
{
	dexterity = dt;
}

void Character::setConstitution(int ct)
{
	constitution = ct;
}

bool Character::isAlive(){
	if(HP > 0)
		return true;
	
	return false;
}

bool Character::inventoryIsEmpty()
{
	return my_items.isEmpty();
}

void Character::earnGold(double g)
{
	my_items.earnGold(g);
}

void Character::spendGold(double g)
{
	my_items.spendGold(g);
}

void Character::listInventory()
{
	if(my_items.isEmpty()){
		std::cout << "Inventory is empty." << std::endl;
	}
	for (int i = 0; i < my_items.getItemsSize(); i++){
		Item* item = my_items.searchItem(i);
		
		std::cout << "\t" << i+1 << ".   " << item->getName();
		
		if(item->isEquippable()){
		
			Equippable *eq = dynamic_cast<Equippable*>(item);
		
			if(eq->isEquipped())
				std::cout << "(E)";
		
			else std::cout << "(U)";
		}

		std::cout << std::endl;
	}
}

Item* Character::retrieveItem(int k)
{
	if(k > my_items.getItemsSize() || k < 0) return NULL;
	return my_items.searchItem(k);
}

void Character::addToInventory(Item *item)
{
	my_items.insertItem(item);
	std::cout << ">> " << item->getName() << " added to " << alias << "'s inventory." << std::endl;
}

void Character::removeFromInventory(Item* item)
{
	my_items.removeItem(item->getName());
	std::cout << ">> " << item->getName() << " removed from " << alias << "'s inventory." << std::endl;
}

void Character::equipItem(Item* item)
{
	Equippable *eq = dynamic_cast<Equippable*>(item);

	if(!item->isEquippable()){
		std::cout << ">> " << item->getName() << " is not equippable." << std::endl;
		return;
	}

	if(eq->isEquipped()){
		std::cout << ">> " << item->getName() << " is already equipped." << std::endl;
		return;
	}

	if(item->getType() == WeaponType){
		if(equipped_weapons==2){
			std::cout << ">> You can't equip more than two weapons." << std::endl;
			return;
		}
		equipped_weapons++;
	}

	if(item->getType() == ArmorType){
		if(has_armor){
			std::cout << ">> You can't equip more than one armor." << std::endl;
			return;
		}
		has_armor = true;
	}

	eq->equip(this);
}

void Character::unequipItem(Item* item)
{
	Equippable *eq = dynamic_cast<Equippable*>(item);

	if(!item->isEquippable()){
		std::cout << ">> " << item->getName() << " is not equippable." << std::endl;
		return;
	}

	if(!eq->isEquipped()){
		std::cout << ">> " << item->getName() << " is already unequipped." << std::endl;
		return;
	}

	if(item->getType() == WeaponType)
		equipped_weapons--;

	if(item->getType() == ArmorType)
		has_armor = false;

	eq->unequip(this);	
}

void Character::useItem(Item* item)
{
	if(!item->isUsable()){
		std::cout << ">> " << item->getName() << " is not usable." << std::endl;
		return;
	}
	
	Usable* us = dynamic_cast<Usable*>(item);
	us->use(this);
}

std::string Character::toString()
{
	std::string info;
	info = "Name: " + alias + "\n";
	info += "Class: ";

	switch(type){
		case 0:
			info += "Knight";
			break;
		case 1:
			info += "Thief";
			break;
		case 2:
			info += "Wizard";
			break;
	}

	info += "\n";
	info += "Team: " + team->getName() + "\n";

	std::stringstream aux;

	aux << "Gold: " << my_items.getTotalGold() << "\n";
	aux << "------------------\n";
	aux << "Strength: " << strength << "\n";
	aux << "Speed: " << speed << "\n";
	aux << "Dexteriy: " << dexterity << "\n";
	aux << "Constitution: " << constitution << "\n";
	aux << "Total: " << strength+speed+dexterity+constitution << "\n";
	aux << "------------------\n";

	info += aux.str();

	return info;
}