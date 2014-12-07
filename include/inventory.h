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
	std::vector<Item*> items;

	int total_defense;
	int total_attack;

	Character* parent;

public:
	Inventory();
	virtual ~Inventory();
	
	//Getters
	double getTotalGold();
	int getAvailableSpace();
	int getTotalDefensePoints();
	int getTotalAttackPoints();
	Character* getParent();
	
	//Setters
	void setSpaces(int);
	void setParent(Character*);

	void spendGold(double);
	void earnGold(double);

	Item* searchItem(std::string);
	Item* searchItem(int);
	void insertItem(Item*);
	void removeItem(std::string);
	void removeItem(int);
	int getItemsSize();

	bool isEmpty();
	bool isFull();
};

#endif
