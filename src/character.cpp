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

void Character::useHealthPotion()
{
	Item *item;
	for (int i = 0; i < my_items.getItemsSize(); i++){
		item = my_items.searchItem(i);
		if (item->getType() == HealthPotionType){
			item->use(this);
			my_items.removeItem(i);
			return;
		}
	}

	std::cout << ">> No Health Potions available (" << getName() << ").\n";
}

void Character::useManaPotion()
{
	Item *item;
	for (int i = 0; i < my_items.getItemsSize(); i++){
		item = my_items.searchItem(i);
		if (item->getType() == ManaPotionType){
			item->use(this);
			my_items.removeItem(i);
			return;
		}
	}

	std::cout << ">> No Mana Potions available (" << getName() << ").\n";
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
	std::cout << ">> Listing " << getName() << "'s inventory: " << std::endl;
	if(my_items.isEmpty()){
		std::cout << "Inventory is empty." << std::endl;
	}
	for (int i = 0; i < my_items.getItemsSize(); i++){
		std::cout << "\t" << i+1 << ".   " << my_items.searchItem(i)->getName() << std::endl;
	}
}

void Character::addToInventory(Item *item)
{
	my_items.insertItem(item);
}

void Character::equipAll()
{
	Item *item;
	for (int i = 0; i < my_items.getItemsSize(); i++){
		item = my_items.searchItem(i);
		if (item->getType() != HealthPotionType && item->getType() != ManaPotionType)
			my_items.equipItem(my_items.searchItem(i));
	}
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

bool Character::isAlive(){
	if(this->HP > 0)
		return true;
	else
		return false;
}