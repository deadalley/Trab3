#include "inventory.h"
#include "armor.h"
#include "character.h"

Inventory::Inventory()
{
	gold = 100;
	total_defense = 0;
	total_attack = 0;
	spaces = 8;

	has_armor = false;
	equipped_weapons = 0;
}

Inventory::~Inventory()
{
	std::pair<Item*, bool> p;
	std::vector<std::pair<Item*, bool> >::iterator it;
	for (int i = 0; i < items.size(); i++){
		p = items.at(i);
		it = items.begin() + i;
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
	if(g > gold) return;
	gold -= g;
}

void Inventory::earnGold(double g)
{	
	gold += g;
}

Item* Inventory::searchItem(std::string item_name)
{
	if (item_name.size() == 0){
		std::cout << "[Search] Invalid item name.\n";
		return NULL;
	}
	
	for (int i = 0; i < items.size(); i++){
		if (items.at(i).first->getName() == item_name)
			return items.at(i).first;
	}

	return NULL;
}

Item* Inventory::searchItem(int k)
{
	if(k > items.size() || k < 0) return NULL;

	return items.at(k).first;
}

void Inventory::insertItem(Item* item)
{
	if(isFull()) return;
	std::pair <Item*, bool> p = std::make_pair(item, false);
	
	items.push_back(p);
}

void Inventory::removeItem(std::string item_name)
{
	if(isEmpty()) return;
		
	std::pair<Item*, bool> p;
	for (int i = 0; i < items.size(); i++){
		p = items.at(i);
		if (item_name.compare(p.first->getName()) == 0){
			//If the item is equipped, updates total_defense and total_attack
			if (p.second){
				total_attack -= p.first->getAttackPoints();
				total_defense -= p.first->getDefensePoints();
			}

			std::vector<std::pair<Item*, bool> >::iterator it;
			
			it = items.begin() + i;
			items.erase(it);
		}
	}
}

void Inventory::removeItem(int k)
{
	if(k > items.size() || k < 0) return;
	
	std::pair<Item*, bool> p = items.at(k);

	//If the item is equipped, updates total_defense and total_attack
	if (p.second){
		total_attack -= p.first->getAttackPoints();
		total_defense -= p.first->getDefensePoints();
	}
	
	std::vector<std::pair<Item*, bool> >::iterator it;
	
	it = items.begin() + k;
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

//Equipa um dado item no inventário
void Inventory::equipItem(Item* item)
{
	if (item == NULL)
		return;

	//Não é possível equipar poções, apenas usá-las
	if (item->getType() == HealthPotionType || item->getType() == ManaPotionType){
		std::cout << "[EquipItem] Cannot equip " << item->getName() << ".\n";
		return;
	}

	//Verifica se uma armadura já está equipada
	if (item->getType() == ArmorType && has_armor) {
		std::cout << "[EquipItem] Character already has an armor equipped." << std::endl;
		return;
	}

	//Verifica se duas armas já estão equipadas
	if (item->getType() == WeaponType && equipped_weapons == 2) {
		std::cout << "[EquipItem] Impossible to equip more than two weapons." << std::endl;
		return;
	}

	for (int i = 0; i < items.size(); i++){
		if (items.at(i).first == item){
			items.at(i).second = true;

			if (item->getType() == ArmorType){
				has_armor = true;
				Armor *armor = dynamic_cast<Armor*>(item);
				//Calcula o novo valor da speed a partir da formula: s' = s . e^(-w/20)^2
				parent->setSpeed(parent->getSpeed()*exp(- pow((armor->getWeight()/20), 2)));
			}
			else if (item->getType() == WeaponType) equipped_weapons++;

			//Atualiza os totais de ataque e defesa
			total_attack += item->getAttackPoints();
			total_defense += item->getDefensePoints();
			return;
		}
	}

	std::cout << "[EquipItem] Item is not present in inventory." << std::endl;
}