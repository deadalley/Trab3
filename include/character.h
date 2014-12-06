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

protected:
	int XP;
	int strength;
	int speed;
	int dexterity;
	int constitution;

	int power;
	int accuracy;

	Team* team;
	CharacterType type;

public:
	Character(std::string, Team&, CharacterType);
	virtual ~Character();
	
	//Add
	void addXP(int);
	void addMP(int);
	void addHP(int);
	
	//Setters
	void setName(std::string);
	void setStrength(int);
	void setSpeed(int);
	void setDexterity(int);
	void setConstitution(int);
	void setTeam(Team*);
	
	//Getters
	std::string getName();
	int getStrength();
	int getSpeed();
	int getDexterity();
	int getConstitution();
	int getHP();
	double getTotalGold();
	std::string toString();
	//Funções getAP e getDP foram mudadas de protected para public
	//para funcionamento correto na classe team
	virtual int getDefensePoints();
	virtual int getAttackPoints();
	
	virtual void attack(Character&) = 0;
	
	//Funções auxiliares
	void reduceHP(int);
	void addToInventory(Item*);
	void listInventory();
	void equipAll();
	void useHealthPotion();
	void useManaPotion();
	void earnGold(double);
	void spendGold(double);
	bool isAlive();
};
#endif