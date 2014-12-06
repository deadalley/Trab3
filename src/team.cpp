#include "team.h"

Team::Team()
{
	name = "INVALID";
}

Team::Team(std::string name, Color color)
{
	//Confere a validade do nome
	while (name.size() == 0){
		std::cout << "Insert valid Team name: ";
		std::cin >> name;
	}

	this->name = name;
	this->color = color;

	win = 0;
	lose = 0;
	draw = 0;
}

Team::~Team()
{
	std::vector<Character*>::iterator it;
	for (int i = 0; i < characters.size(); i++){
		it = characters.begin() + i;
		//delete ch;
		characters.erase(it);
	}
}

std::string Team::getName()
{
	return name;
}

std::string Team::getResults()
{
	std::stringstream results;
	
	results << "Won: " << win << "\n";
	results << "Lost: " << lose << "\n";
	results << "Draws: " << draw << "\n";

	return results.str();
}

std::string Team::toString()
{
	std::string info;
	info = "Team: " + name + "\n";
	info += "Color: ";
	
	switch(color){
		case 0:
			info += "White";
			break;
		case 1:
			info += "Black";
			break;
		case 2:
			info += "Blue";
			break;
		case 3:
			info += "Red";
			break;
		case 4:
			info += "Green";
			break;
		case 5:
			info += "Yellow";
			break;
	}

	info += "\n";

	return info;
}

int Team::getPoints()
{
	int points = 0;

	std::vector<Character*>::iterator it;
	
	for (int i = 0; i < characters.size(); i++){
		points += characters.at(i)->getHP();
	}

	return points / characters.size();
}

void Team::setName(std::string name)
{
	this->name = name;
}

void Team::setColor(Color c)
{
	this->color = c;
}

void Team::resolveBattle(Team& team)
{
	//Derrota
	if (team.getPoints() > this->getPoints())
		lose++;

	//Vitória
	if (team.getPoints() < this->getPoints())
		win++;

	//Empate
	if (team.getPoints() == this->getPoints())
		draw++;
}

void Team::addChar(Character *ch)
{
	if (ch == NULL){
		std::cout << "[AddChar] Invalid character (null).\n";
		return;
	}

	characters.push_back(ch);
}

void Team::removeChar(int k)
{
	if (k > characters.size()){
		std::cout << "[RemoveChar] Invalid position (k>=characters.size())." << std::endl;
		return;
	}

	if (k < 0){
		std::cout << "[RemoveChar] Invalid position (k<0)." << std::endl;
		return;
	}

	std::vector<Character*>::iterator it = characters.begin() + k;
	characters.erase(it);
}

void Team::removeChar(Character *ch)
{
	if (ch == NULL){
		std::cout << "[RemoveChar] Invalid character (null)." << std::endl;
		return;
	}

	if (characters.size() == 0){
		std::cout << "[RemoveChar] Team is empty.\n";
		return;
	}
	
	std::vector<Character*>::iterator it;
	for (int i = 0; i < characters.size(); i++){
		if (ch == characters.at(i)){
			it = characters.begin() + i;
			characters.erase(it);
		}
	}
}

Character* Team::searchChar(std::string ch_name)
{
	if (ch_name.size() == 0){
		std::cout << "[SearchChar] Invalid character name." << std::endl;
		return NULL;
	}
	
	for (int i = 0; i < characters.size(); i++){
		if (ch_name.compare(characters.at(i)->getName()) == 0)
			return characters.at(i);
	}

	return NULL;
}

Character* Team::searchChar(int k)
{
	if (k > characters.size()){
		std::cout << "[Search] Invalid position (k>=characters.size())." << std::endl;
		return NULL;
	}

	if (k < 0){
		std::cout << "[Search] Invalid position (k<0)." << std::endl;
		return NULL;
	}

	return characters.at(k);
}

int Team::numOfCharacters()
{
	return characters.size();
}

//Função que lista os personagens e seus respectivos inventários do time
void Team::listCharacters()
{
	for (int i = 0; i < characters.size(); i++)
		std::cout << i+1 << ". " << characters.at(i)->getName() << std::endl;
}