/* Jéssica Bargas Aissa - 8504250               */
/* Trabalho 2 - Programação Orientada a Objetos */

#include "team.h"
#include "character.h"
#include "knight.h"
#include "wizard.h"
#include "thief.h"

#include "inventory.h"
#include "item.h"
#include "weapon.h"
#include "armor.h"

#include "potion.h"
#include "manapotion.h"
#include "healthpotion.h"
#include "standarditems.h"
#include "cstdio"
#include "cstdlib"

using namespace std;

//Armors
Armor* StandardItems::leather_armor = new Armor("Leather Armor", 12.0, 4, 3.0);
Armor* StandardItems::iron_armor = new Armor("Iron Armor", 13.0, 10, 6.0);
Armor* StandardItems::silver_armor = new Armor("Silver Armor", 15.0, 15, 8.0);
Armor* StandardItems::gold_armor = new Armor("Gold Armor", 27.0, 18, 11.0);
Armor* StandardItems::diamond_armor = new Armor("Diamond Armor", 40.0, 19, 14.0);

//Weapons
Weapon* StandardItems::dagger = new Weapon("Dagger", 12.0, 4, 4.0);
Weapon* StandardItems::short_sword = new Weapon("Short Sword", 16.0, 6, 5.0);
Weapon* StandardItems::long_sword = new Weapon("Long Sword", 22.0, 7, 10.0);
Weapon* StandardItems::scythe = new Weapon("Scythe of Doom", 28.0, 9, 16.0);
Weapon* StandardItems::axe = new Weapon("Generic Axe", 30.0, 9, 18.0);

Weapon* StandardItems::spear = new Weapon("Generic Spear", 14.0, 6, 14.0);
Weapon* StandardItems::bow = new Weapon("Generic Bow", 18.0, 9, 28.0);
Weapon* StandardItems::staff = new Weapon("Generic Staff", 23.0, 8, 12.0);
Weapon* StandardItems::wand = new Weapon("Generic Wand", 20.0, 8, 2.0);
Weapon* StandardItems::tesseract = new Weapon("Tesseract", 1300.0, 9, 45.0);

//Potions
ManaPotion* StandardItems::minor_mana_potion = new ManaPotion("Minor Mana Potion", 5.0, 3);
ManaPotion* StandardItems::light_mana_potion = new ManaPotion("Light Mana Potion", 8.0, 5);
ManaPotion* StandardItems::full_mana_potion = new ManaPotion("Full Mana Potion", 10.0, 10);

HealthPotion* StandardItems::minor_health_potion = new HealthPotion("Minor Health Potion", 5.0, 3);
HealthPotion* StandardItems::light_health_potion = new HealthPotion("Light Health Potion", 8.0, 5);
HealthPotion* StandardItems::regular_health_potion = new HealthPotion("Regular Health Potion", 10.0, 8);
HealthPotion* StandardItems::full_health_potion = new HealthPotion("Full Health Potion", 15.0, 10);
HealthPotion* StandardItems::ultra_health_potion = new HealthPotion("Ultra Health Potion", 25.0, 18);

void printTeamVector(vector<Team*>& teams){
	for(int i=0; i<teams.size(); i++)
        cout << i+1 << ". " << teams.at(i)->getName() << endl;
}

void battle(Team t1, Team t2){
	int round = 0;
	Character *ch1;
	Character *ch2;
	//Realiza várias séries de turnos até que algum dos times esteja com 50 pontos
	while (t1.getPoints() > 50 && t2.getPoints() > 50){
		std::cout << "=== ROUND " << round+1 << " ===" <<std::endl;
		//Personagens aleatórios iniciais de cada time
		int x = rand()%4;
		int y = rand()%4;

		int turns = 0;
		while (turns < 8){
			ch1 = t1.searchChar(x);
			ch2 = t2.searchChar(y);
			//0: Team 1 / 1: Team 2
			switch(rand()%2){
				case 0:
					ch1->attack(*ch2);
					break;
				case 1:
					ch2->attack(*ch1);
					break;
			}

			//Faz os personagens utilizarem health potions
			if (ch1->getHP() < 80){
				cout << "    ";
				ch1->useHealthPotion();
			}
			if (ch2->getHP() < 80) {
				cout << "    ";
				ch2->useHealthPotion();
			}

			//O primeiro personagem de cada time é aleatório
			//A partir daí, os personagens são selecionados
			//sequencialmente
			if (x == 3) x = -1;
			if (y == 3) y = -1;

			x++;
			y++;
			turns++;
		}

		cout << "\n";

		t1.resolveBattle(t2);
		t2.resolveBattle(t1);

		//Printa os resultados atuais
		cout << t1.getResults() << endl;
		cout << t2.getResults() << endl;
		round++;
	}
}

CharacterType character_type_menu(){
	int menu_option = 0;

	while(menu_option != 4){
		cout << "1. Knight" << endl;
		cout << "2. Thief" << endl;
		cout << "3. Wizard" << endl;
		cout << ">> ";
		cin >> menu_option;
		switch(menu_option){
			case 1:
				return KnightType;
			case 2:
				return ThiefType;
			case 3:
				return WizardType;
		}
	}
}

Color color_menu(){
	int k = 0, menu_option = 0;

	while(1){
		//cout << "== COLOR ==" << endl;
		cout << "1. White" << endl;
		cout << "2. Black" << endl;
		cout << "3. Blue" << endl;
		cout << "4. Red" << endl;
		cout << "5. Green" << endl;
		cout << "6. Yellow" << endl;
		cout << ">> ";
		cin >> menu_option;
		switch(menu_option){
			case 1:
				return white;
			case 2:
				return black;
			case 3:
				return blue;
			case 4:
				return red;
			case 5:
				return green;
			case 6:
				return yellow;
			default:
				break;
		}
	}
}

Armor* armor_menu(){
    int k = 0;
    StandardItems::printArmors();
    cout << ">> ";
    cin >> k;
    return StandardItems::getArmor(k);
}

Potion* potion_menu(){

}

Weapon* weapon_menu(){

}

void items_store_menu(Character& ch){
    int menu_option = 0;

	while(menu_option != 4){
		cout << "\n== ITEMS STORE ==" << endl;

		cout << ch.toString();

		cout << "1. Armors" << endl;
		cout << "2. Potions" << endl;
		cout << "3. Weapons" << endl;
		cout << "4. Return" << endl;
		cout << ">> ";
		cin >> menu_option;

		switch(menu_option){
			case 1:{
			    Armor* new_armor = armor_menu();
			    ch.addToInventory(new_armor);
			    cout << ">> " << new_armor->getName() << " added to " << ch.getName() << "'s inventory." << endl;
				break;
			}
			case 2:{
				//Set strength
				Potion* new_potion = potion_menu();
			    ch.addToInventory(new_potion);
			    cout << ">> " << new_potion->getName() << " added to " << ch.getName() << "'s inventory." << endl;
				break;
			}
			case 3:{
				//Set speed
				Weapon* new_weapon = weapon_menu();
			    ch.addToInventory(new_weapon);
			    cout << ">> " << new_weapon->getName() << " added to " << ch.getName() << "'s inventory." << endl;
				break;
			}
		}
	}
}

void character_menu(Character& ch){
	int menu_option = 0;

	while(1){
		cout << "\n== CHARACTER ==" << endl;

		cout << ch.toString();

		cout << "1. Edit Name" << endl;
		cout << "2. Set Strength" << endl;
		cout << "3. Set Speed" << endl;
		cout << "4. Set Dexterity" << endl;
		cout << "5. Set Constitution" << endl;
		cout << "6. Inventory" << endl;
		cout << "7. Buy Items" << endl;
		cout << "8. Return" << endl;
		cout << ">> ";
		cin >> menu_option;

		switch(menu_option){
			case 1:{
				//Edit name
				string name;
				cout << "Current name: " << ch.getName() << endl;
				cout << "New name (NO SPACES): \n";
				cout << ">> ";
				cin >> name;
				ch.setName(name);
				cout << ">> Name set to: " << name << endl;
				break;
			}
			case 2:{
				//Set strength
				int st;
				cout << "New strength value: " << endl;
				cout << ">> ";
				cin >> st;
				ch.setStrength(st);
				break;
			}
			case 3:{
				//Set speed
				int sp;
				cout << "New speed value: " << endl;
				cout << ">> ";
				cin >> sp;
				ch.setSpeed(sp);
				break;
			}
			case 4:{
				//Set dexterity
				int dt;
				cout << "New dexterity value: " << endl;
				cout << ">> ";
				cin >> dt;
				ch.setDexterity(dt);
				break;
			}
			case 5:{
				//Set constitution
				int ct;
				cout << "New constitution value: " << endl;
				cout << ">> ";
				cin >> ct;
				ch.setConstitution(ct);
				break;
			}
			case 6:{
				//Access character inventory
				ch.listInventory();
				cout << ">> [ENTER]";
				getchar();
				getchar();
			    break;
			}
			case 7:{
				//Open items store
				items_store_menu(ch);
				break;
			}
			case 8:{
				//Exit
				if((ch.getStrength() + ch.getSpeed() + ch.getDexterity() + ch.getConstitution()) > 100){
					cout << ">> ";
					cout << "Total attributes are over 100. Please adjust the attributes!\n";
					cout << ">> [ENTER]";
					getchar();
					getchar();
				}
				else return;
				break;
			}
		}
	}
}

void team_menu(Team& team){
	int k = 0, menu_option = 0;
	while(menu_option != 6){
		cout << "\n== TEAM ==" << endl;

		cout << team.toString();

		cout << "1. Edit Name" << endl;
		cout << "2. Edit Color" << endl;
		cout << "3. Add Character" << endl;
		cout << "4. Remove Character" << endl;
		cout << "5. Edit Character" << endl;
		cout << "6. Return" << endl;
		cout << ">> ";
		cin >> menu_option;

		switch(menu_option){
			case 1:{
				//Edit name
				string name;
				cout << "Current name: " << team.getName() << endl;
				cout << "New name (NO SPACES): \n";
				cout << ">> ";
				cin >> name;
				team.setName(name);
				cout << ">> Name set to: " << name << endl;
				break;
			}
			case 2:{
				//Edit color
				Color color = color_menu();
				team.setColor(color);
				cout << ">> Color set to: ";
				switch(color){
					case 0:
						cout << "White" << endl;
						break;
					case 1:
						cout << "Black" << endl;
						break;
					case 2:
						cout << "Blue" << endl;
						break;
					case 3:
						cout << "Red" << endl;
						break;
					case 4:
						cout << "Green" << endl;
						break;
					case 5:
						cout << "Yellow" << endl;
						break;
				}
				break;
			}
			case 3:{
				//Add character
				Character* ch;
				string name;
				CharacterType type = character_type_menu();
				cout << "Name: " << endl;
				cout << ">> ";
				cin >> name;
				//Characters start out with default 5 power/stealth/wisdom
				if(type == KnightType) ch = new Knight(name, 5, team);
				if(type == ThiefType) ch = new Thief(name, 5, team);
				if(type == WizardType) ch = new Wizard(name, 5, team);
				character_menu(*ch);
				ch->addToInventory(NULL);
				team.addChar(ch);
				break;
			}
			case 4:{
				//Remove character
				int k = 0;
				if(team.numOfCharacters()==0){
					cout << ">> No characters in " << team.getName() << ". Please add characters." << endl;
				}
				else{
					team.listCharacters();
					cout << ">> ";
					cin >> k;
					k--;
					Character *ch = team.searchChar(k);
					team.removeChar(ch);
					cout << ">> ";
					cout << ch->getName() << " removed successfully from " << team.getName() << endl;
				}
				cout << ">> [ENTER]";
				getchar();
				getchar();
				break;
			}
			case 5:{
				//Edit character
				int k = 0;
				if(team.numOfCharacters()==0){
					cout << ">> No characters in " << team.getName() << ". Please add characters." << endl;
					cout << ">> [ENTER]";
					getchar();
					getchar();
				}
				else{
					team.listCharacters();
					cout << ">> ";
					cin >> k;
					k--;
					Character *ch = team.searchChar(k);
					character_menu(*ch);
				}
				break;
			}
		}
	}
}

void main_menu(vector<Team*>& teams){
	int k = 0, menu_option = 0;
	while(menu_option != 4){
		cout << "== MENU ==" << endl;
		cout << "1. New Team" << endl;
		cout << "2. Edit Team" << endl;
		cout << "3. FIGHT!" << endl;
		cout << "4. Exit" << endl;
		cout << ">> ";
		cin >> menu_option;

		switch(menu_option){
			case 1:{
				//New team
				Team* team;
				string name;
				cout << "Name (NO SPACES): " << endl;
				cout << ">> ";
				cin >> name;
				cout << "Color:" << endl;
				Color color = color_menu();
				team = new Team(name, color);
				team_menu(*team);
				teams.push_back(team);
				break;
			}
			case 2:{
				//Edit team
				int k = 0;
				printTeamVector(teams);
				cout << ">> ";
				cin >> k;
				k--;
				Team *team = teams.at(k);
				team_menu(*team);
				break;
			}
			case 3:{
				//Battle
                int k = 0;
				cout << ">> Pick Team A for battle:" << endl;
				printTeamVector(teams);
				cout << ">> ";
				cin >> k;
				k--;
				Team *teamA = teams.at(k);
				cout << ">> Pick Team B for battle:" << endl;
				printTeamVector(teams);
				cout << ">> ";
				cin >> k;
				k--;
				Team* teamB = teams.at(k);

				//battle
				break;
			}
		}
	}
}

int main(void){
	srand(time(0));
	vector<Team*> teams;

	main_menu(teams);

	return 0;
}