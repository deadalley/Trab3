#include "character.h"
#include "team.h"

Character::Character()
{
	alias = "INVALID";
}

Character::Character(std::string name, Team* team, CharacterType type)
{
	//Confere a validade do nome
	while (name.size() == 0){
		std::cout << "Insert valid Character name: ";
		std::cin >> name;
	}

	alias = name;
	HP = 100;
	XP = 1;
	MP = 0;

	//Atributos setados
	strength = 25;
	speed = 25;
	dexterity = 25;
	constitution = 25;

	power = 30;
	accuracy = 30;

	gold = 100;

	this->team = team;
	this->type = type;

	//Valor inicial
	my_items.setSpaces(8);
	my_items.earnGold(100);

	my_items.setParent(this);
}

Character::~Character()
{
}

int Character::getDefensePoints()
{
	return ((0.5*constitution) + (0.2*speed) + (0.3*dexterity) + my_items.getTotalDefensePoints()) * (XP/2);
}

int Character::getAttackPoints()
{
	return ((0.5*strength) + (0.3*dexterity) + (0.2*speed) + my_items.getTotalAttackPoints()) * (XP/3);
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
	info += "Team: " + team->getName() + "\n\n";

	std::stringstream aux;

	aux << "Gold: " << gold << "\n";
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

void Character::setName(std::string name)
{
	alias = name;
}

void Character::setTeam(Team* team)
{
	this->team = team;
}

void Character::addXP(int xp)
{
	if (xp + XP > 100){
		//std::cout << "[AddXP] Invalid xp value (TotalXP>100). Setting to 100.\n";
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
	if (mp + MP > 100){
		//std::cout << "[AddMP] Invalid mp value (TotalMP>100). Setting to 100.\n";
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
	if (hp + HP > 100){
		//std::cout << "[AddHP] Invalid hp value (TotalHP>100). Setting to 100.\n";
		HP = 100;
		return;
	}

	if (hp + HP < 0){
		HP = 0;
		return;
	}

	HP += hp;
}

void Character::setStrength(int st)
{
	if (st <= 0){
		std::cout << "[Strength] Invalid strength value (st<=0).\n";
		return;
	}

	strength = st;
}

void Character::setSpeed(int sp)
{
	if (sp <= 0){
		std::cout << "[Speed] Invalid speed value (sp<=0).\n";
		return;
	}

	speed = sp;
}

void Character::setDexterity(int dt)
{
	if (dt <= 0){
		std::cout << "[Dexterity] Invalid dexterity value (dt<=0).\n";
		return;
	}

	dexterity = dt;
}

void Character::setConstitution(int ct)
{
	if (ct <= 0){
		std::cout << "[Constitution] Invalid constitution value (ct<=0).\n";
		return;
	}

	constitution = ct;
}

//Adiciona um item ao inventário do personagem
void Character::addToInventory(Item *item)
{
	my_items.insertItem(item);
}

//Retorna o HP do personagem
int Character::getHP()
{
	return HP;
}

//Dá dano ao personagem
void Character::reduceHP(int dam)
{
	if (dam <= 0)
		return;

	if (dam > HP)
		HP = 0;
	else
		HP = HP - dam;
}

//Lista o inventário do personagem (debug)
void Character::listInventory()
{
	std::cout << ">> Listing " << getName() << "'s inventory: " << std::endl;
	std::stringstream aux;
	for (int i = 0; i < my_items.getItemsSize(); i++){
		/*aux << i+1;
		std::cout << "\t   " << aux.str() + ". ";
		my_items.searchItem(i);
		if (my_items.searchItem(i) == NULL) std::cout << "\t\tNULL at " << i << "\n";
		else std::cout << my_items.searchItem(i)->getName() << std::endl;
		aux.str("");*/
		std::cout << "\t" << i+1 << "   " << my_items.searchItem(i)->getName() << std::endl;
	}
}

//Função que equipa todos os itens possíveis do inventário
void Character::equipAll()
{
	Item *item;
	for (int i = 0; i < my_items.getItemsSize(); i++){
		item = my_items.searchItem(i);
		//Confere se o item é poção
		if (item->getType() != HealthPotionType && item->getType() != ManaPotionType)
			my_items.equipItem(my_items.searchItem(i));
	}
}

//Função que usa uma health potion qualquer disponível no inventário
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

	std::cout << "No Health Potions available (" << getName() << ")\n";
}

//Função que usa uma mana potion qualquer disponível no inventário
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

	std::cout << "No Mana Potions available (" << getName() << ")\n";
}
