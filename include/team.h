#ifndef H_TEAM
#define H_TEAM

#include "character.h"

enum Color {
	white,
	black,
	blue,
	red,
	green,
	yellow,
};

class Team {
private:
	std::string name;
	std::vector<Character*> characters;
	
	Color color;
	
	int win;
	int lose;
	int draw;

public:
	Team(std::string, Color);
	virtual ~Team();

	//Getters
	std::string getName();
	std::string getResults();
	std::string toString();
	int getPoints();

	//Setters
	void setName(std::string);
	void setColor(Color);

	void resolveBattle(Team&);
	
	//Gerenciamento de personagens
	void addChar(Character*);
	void removeChar(int);
	void removeChar(Character*);
	Character* searchChar(std::string);
	Character* searchChar(int k);
	int numOfCharacters();

	//Funções auxiliares
	void listCharacters();
};

#endif