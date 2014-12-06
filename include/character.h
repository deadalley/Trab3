#ifndef H_CHARACTER
#define H_CHARACTER

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>

#include "item.h"
#include "inventory.h"
#include "armor.h"
#include "weapon.h"

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

	CharacterType type;

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
	void addToInventory(Item*);

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

	void useHealthPotion();
	void useManaPotion();

	void earnGold(double);
	void spendGold(double);

	void listInventory();
	void equipAll();

	std::string toString();
	bool isAlive();
	virtual void attack(Character&) = 0;
	
};
#endif