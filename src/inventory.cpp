#include "inventory.h"
#include "armor.h"
#include "character.h"

Inventory::Inventory()
{
	//Inicialização padrão dos atributos
	gold = 0;
	total_defense = 0;
	total_attack = 0;
	spaces = 0;

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
	//Espaço total menos espaço ocupado
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

void Inventory::spendGold(double g)
{
	if (g <= 0){
		std::cout << "[Spend] Invalid gold value (g<=0).\n";
		return;
	}
		
	if (g > gold){
		std::cout << "[Spend] Invalid gold value (g>gold).\n";
		return;
	}
	
	gold -= g;
}

void Inventory::earnGold(double g)
{
	if (g <= 0){
		std::cout << "[Earn] Invalid gold value (g<=0).\n";
		return;
	}
	
	gold += g;
}

void Inventory::setSpaces(int s)
{
	if (s <= 0){
		std::cout << "[Spaces] Invalid space value (s<=0).\n";
		return;
	}
		
	spaces = s;
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
	if (k > items.size()){
		std::cout << "[Search] Invalid item position (k>=items.size()).\n";
		return NULL;
	}
	
	if (k < 0){
		std::cout << "[Search] Invalid item position (k<0).\n";
		return NULL;
	}

	return items.at(k).first;
}

void Inventory::insertItem(Item* item)
{
	if (item == NULL){
		std::cout << "[Insert] Invalid item (item=NULL).\n";
		return;
	}

	if (items.size() == spaces){
		std::cout << "[Insert] Not enough space.\n";
		return;
	}

	//Todo item é adicionado desequipado
	std::pair <Item*, bool> p = std::make_pair(item, false);
	
	items.push_back(p);
}

void Inventory::removeItem(std::string item_name)
{
	if (item_name.size() == 0){
		std::cout << "[Remove] Invalid item name.\n";
		return;
	}

	if (items.size() == 0){
		std::cout << "[Remove] Inventory empty.\n";
		return;
	}
		
	std::pair<Item*, bool> p;
	for (int i = 0; i < items.size(); i++){
		p = items.at(i);
		if (item_name.compare(p.first->getName()) == 0){
			//Se o item estiver equipado, atualiza os valores de ataque e defesa
			if (p.second){
				total_attack -= p.first->getAttackPoints();
				total_defense -= p.first->getDefensePoints();
			}

			std::vector<std::pair<Item*, bool> >::iterator it;
			//Remove o item do inventário
			it = items.begin() + i;
			items.erase(it);
		}
	}
}

void Inventory::removeItem(int k)
{
	if (k > items.size()){
		std::cout << "[Remove] Invalid item position (k>=items.size()).\n";
		return;
	}
	
	if (k < 0){
		std::cout << "[Remove] Invalid item position (k<0).\n";
		return;
	}

	if (items.size() == 0){
		std::cout << "[Remove] Inventory empty.\n";
		return;
	}
	
	std::pair<Item*, bool> p = items.at(k);

	//Atualiza os valores de ataque e defesa totais
	if (p.second){
		total_attack -= p.first->getAttackPoints();
		total_defense -= p.first->getDefensePoints();
	}
	
	std::vector<std::pair<Item*, bool> >::iterator it;
	//Remove o item do inventário
	it = items.begin() + k;
	items.erase(it);
}

int Inventory::getItemsSize()
{
	return items.size();
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

//Seta o character que é dono do inventário
void Inventory::setParent(Character *parent)
{
	this->parent = parent;
}

//Retorna o character dono do inventário
Character* Inventory::getParent()
{
	return parent;
}