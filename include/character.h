#ifndef H_CHARACTER
#define H_CHARACTER

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>

#include "item.h"
#include "inventory.h"
#include "equippable.h"
#include "usable.h"

class Team;

enum CharacterType {
	KnightType,
	ThiefType,
	WizardType
};

class Character {
private:
	std::string alias;
	Inventory my_items;

	int HP;
	int MP;

	CharacterType type;		//indentifies the type of character

	bool has_armor;			//indicates if an armor has been equipped
	int equipped_weapons;	//maximum 2

protected:
	int XP;
	int strength;
	int speed;
	int dexterity;
	int constitution;

	int power;
	int accuracy;

	Team* team;

public:
	Character(std::string, Team&, CharacterType);
	virtual ~Character();
	
	//Add
	void addXP(int);
	void addMP(int);
	void addHP(int);

	//Getters
	std::string getName();

	int getStrength();
	int getSpeed();
	int getDexterity();
	int getConstitution();
	
	int getXP();
	int getHP();
	int getMP();
	
	double getTotalGold();
	
	virtual int getDefensePoints();
	virtual int getAttackPoints();
	
	//Setters
	void setName(std::string);
	void setTeam(Team*);
	void setStrength(int);
	void setSpeed(int);
	void setDexterity(int);
	void setConstitution(int);

	bool isAlive();
	bool inventoryIsEmpty();

	void earnGold(double);
	void spendGold(double);

	void listInventory();
	
	Item* retrieveItem(int);
	
	void addToInventory(Item*);
	void removeFromInventory(Item*);
	
	void equipItem(Item*);
	void unequipItem(Item*);
	void useItem(Item*);

	void useHealthPotion();

	std::string toString();

	virtual void attack(Character&) = 0;
	
};
#endif
