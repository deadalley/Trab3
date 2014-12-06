#ifndef H_INVENTORY
#define H_INVENTORY

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "item.h"

class Character;

class Inventory{
private:
	int spaces;
	double gold;
	std::vector<std::pair<Item*, bool> > items;

	//Defesa e ataque de todos os items do inventário somados
	int total_defense;
	int total_attack;

	//Indica se uma armadura já está equipada
	bool has_armor;
	//Indica quantas armas estão equipadas (máx 2)
	int equipped_weapons;
	//Personagem ao qual o inventário se refere
	Character* parent;

public:
	Inventory();
	virtual ~Inventory();
	
	//Getters
	double getTotalGold();
	int getAvailableSpace();
	int getTotalDefensePoints();
	int getTotalAttackPoints();
	
	//Setters
	void spendGold(double);
	void earnGold(double);

	void setSpaces(int);

	//Controle de items
	Item* searchItem(std::string);
	Item* searchItem(int);
	void insertItem(Item*);
	void removeItem(std::string);
	void removeItem(int);

	//Funções auxiliares/debuggers
	int getItemsSize();
	bool isEmpty();
	void equipItem(Item*);
	void setParent(Character*);
	Character* getParent();
};

#endif
