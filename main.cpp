/* Jéssica Bargas Aissa - 8504250               */
/* Lucas Tomazela - 8124271                     */
/* Trabalho 3 - Programação Orientada a Objetos */

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
#include <cstdio>

using namespace std;

//Armors
Armor* StandardItems::leather_armor = new Armor("Leather Armor", 12.0, 4, 3.0);
Armor* StandardItems::iron_armor = new Armor("Iron Armor", 17.0, 23, 6.0);
Armor* StandardItems::silver_armor = new Armor("Silver Armor", 22.0, 48, 8.0);
Armor* StandardItems::gold_armor = new Armor("Gold Armor", 32.0, 65, 15.0);
Armor* StandardItems::diamond_armor = new Armor("Diamond Armor", 40.0, 78, 20.0);

//Weapons
Weapon* StandardItems::dagger = new Weapon("Dagger", 12.0, 4, 4.0);
Weapon* StandardItems::short_sword = new Weapon("Short Sword", 16.0, 8, 5.0);
Weapon* StandardItems::long_sword = new Weapon("Long Sword", 22.0, 12, 10.0);
Weapon* StandardItems::scythe = new Weapon("Scythe of Doom", 28.0, 18, 16.0);
Weapon* StandardItems::axe = new Weapon("Axe of Damnation", 30.0, 31, 18.0);

Weapon* StandardItems::spear = new Weapon("Spear", 14.0, 6, 14.0);
Weapon* StandardItems::bow = new Weapon("Wooden Bow", 18.0, 16, 28.0);
Weapon* StandardItems::staff = new Weapon("Staff", 23.0, 22, 12.0);
Weapon* StandardItems::wand = new Weapon("Low-Budget Wand", 20.0, 38, 2.0);
Weapon* StandardItems::tesseract = new Weapon("Tesseract", 1300.0, 118, 45.0);

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
				//ch1->useHealthPotion();
			}
			if (ch2->getHP() < 80) {
				cout << "    ";
				//ch2->useHealthPotion();
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
	int k = 0;

	while(1){
		cout << "1. White" << endl;
		cout << "2. Black" << endl;
		cout << "3. Blue" << endl;
		cout << "4. Red" << endl;
		cout << "5. Green" << endl;
		cout << "6. Yellow" << endl;
		cout << ">> ";
		cin >> k;
		switch(k){
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
    Armor* new_armor = NULL;

	StandardItems::printArmors();
    cout << "6. Return" << endl;
    cout << ">> ";
    cin >> k;

    if(k==6) return NULL;
    
    k--;
    new_armor = StandardItems::getArmor(k);

    return new_armor;
}

Potion* potion_menu(){
	int k = 0;
    Potion* new_potion = NULL;

	StandardItems::printPotions();
    cout << "9. Return" << endl;
    cout << ">> ";
    cin >> k;

    if(k==9) return NULL;
    
    k--;
    new_potion = StandardItems::getPotion(k);

    return new_potion;
}

Weapon* weapon_menu(){
	int k = 0;
    Weapon* new_weapon = NULL;

	StandardItems::printWeapons();
    cout << "11. Return" << endl;
    cout << ">> ";
    cin >> k;

    if(k==11) return NULL;
    
    k--;
    new_weapon = StandardItems::getWeapon(k);

    return new_weapon;
}

void items_store_menu(Character& ch){
    int menu_option = 0;

	while(menu_option != 4){
		cout << "\n== ITEMS STORE ==" << endl;

		stringstream stream;
		stream << "Gold: " << ch.getTotalGold() << "\n";
		cout << stream.str();

		cout << "1. Armors" << endl;
		cout << "2. Potions" << endl;
		cout << "3. Weapons" << endl;
		cout << "4. Return" << endl;
		cout << ">> ";
		cin >> menu_option;

		switch(menu_option){
			case 1:{
				//Armors
			    Armor* new_armor = armor_menu();
			    
			    if(new_armor==NULL) break;
			    
			    ch.spendGold(new_armor->getPrice());
			    
			    if(ch.getTotalGold()<new_armor->getPrice())
			    	break;
			    
			    ch.addToInventory(new_armor);
				break;
			}
			case 2:{
				//Potions
				Potion* new_potion = potion_menu();

				if(new_potion==NULL) break;
			    
			    ch.spendGold(new_potion->getPrice());

			    if(ch.getTotalGold()<new_potion->getPrice())
			    	break;

			    ch.addToInventory(new_potion);
				break;
			}
			case 3:{
				//Weapons
				Weapon* new_weapon = weapon_menu();
				
				if(new_weapon==NULL) break;
			    
			    ch.spendGold(new_weapon->getPrice());

				if(ch.getTotalGold()<new_weapon->getPrice())
			    	break;

			    ch.addToInventory(new_weapon);
				break;
			}
		}
	}
}

void inventory_menu(Character& ch){
	int menu_option = 0;

	while(menu_option != 5){
		cout << "\n== INVENTORY ==" << endl;

		cout << "Listing " << ch.getName() << "'s inventory." << endl;
		cout << "---------------------------------------------------------------" << endl;
		ch.listInventory();
		cout << "---------------------------------------------------------------" << endl;
		
		if(ch.inventoryIsEmpty()) break;
		
		cout << "(E): Equipped" << endl;
		cout << "(U): Unequipped" << endl;

		cout << "1. Equip Item" << endl;
		cout << "2. Unequip Item" << endl;
		cout << "3. Use Item" << endl;
		cout << "4. Sell Item" << endl;
		cout << "5. Return" << endl;
		cout << ">> ";
		cin >> menu_option;

		switch(menu_option){
			case 1:{
				//Equip item
				int k = 0;
				cout << ">> Select item to equip:" << endl;
				cout << ">> ";
				cin >> k;
				k--;
				Item* item = ch.retrieveItem(k);
				ch.equipItem(item);
				break;
			}
			case 2:{
				//Unequip item
				int k = 0;
				cout << ">> Select item to unequip:" << endl;
				cout << ">> ";
				cin >> k;
				k--;
				Item* item = ch.retrieveItem(k);
				ch.unequipItem(item);
				break;
			}
			case 3:{
				//Use item
				int k = 0;
				cout << ">> Select item to use:" << endl;
				cout << ">> ";
				cin >> k;
				k--;
				Item* item = ch.retrieveItem(k);
				ch.useItem(item);
				break;
			}
			case 4:{
				//Sell item
				int k = 0;
				cout << ">> Select item to sell:" << endl;
				cout << ">> ";
				cin >> k;
				k--;
				Item* item = ch.retrieveItem(k);
				ch.removeFromInventory(item);
				ch.earnGold(item->getPrice());
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

		cout << "\n";
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
				inventory_menu(ch);
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
	int menu_option = 0;
	while(menu_option != 6){
		cout << "\n== TEAM ==" << endl;

		cout << team.toString();

		cout << "\n";
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
					cout << ">> " << ch->getName() << " removed successfully from " << team.getName() << endl;
				}
				break;
			}
			case 5:{
				//Edit character
				int k = 0;
				if(team.numOfCharacters()==0)
					cout << ">> No characters in " << team.getName() << ". Please add characters." << endl;

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
	int menu_option = 0;
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
				int i, j, k, w = 0, y;
				bool found = false;
				vector <Character*> *Achoosen = new vector<Character*>;
				vector <Character*> *Bchoosen = new vector<Character*>;

				//Printando o nome dos times
				for(i = 0; i < (signed)teams.size(); i++)
					cout << "#" << i << " : " << teams.at(i)->getName() << endl; 
				cout << "Escolha o primeiro time que deseja batalhar: \n >>";
				cin >> i;
				//Printando o nome dos outros times
				for(j = 0; j < (signed)teams.size(); j++){
					if(j != i)
						cout << "#" << i << " : " << teams.at(i)->getName() << endl; 
				}
				cout << "Escolha o segundo time que deseja batalhar: \n >>";
				cin << y;

				//Escolhendo os personagens que farão parte da batalha #Time 1
				while(w != -1){
					//Ainda não escolhidos
					cout << "\t\t\t 1# Time " << teams.at(i)->getName() << "\n\t == Integrantes disponiveis\n" << endl;
					for(k = 0; k < (signed)teams.at(i)->numOfCharacters(); k++){
						found = false;
						if(Achoosen->size() != 0){
							//Buscando se o personagem já foi escolhido. Caso já foi, seu nome não será impresso na tela
							for (y = 0; (y < (signed)Achoosen->size()) && (!found); y++)
								//O personagem já foi escolhido
								if(teams.at(i)->searchChar(k)->getName() == Achoosen->at(y)->getName())
									found = true;
						}
						//Personagem não escolhido
						if(!found)
							cout << "- " << k << " : " << teams.at(i)->searchChar(k)->getName()<<endl;
					}
					//Escolhidos
					cout << "\n\t == Integrantes escolhidos\n" << endl;
					if(Achoosen->size() == 0)
						cout << " # Nenhum personagem ainda foi escolhido!" <<endl;
					for(k = 0; k < (signed)Achoosen->size(); k++){
						cout << "- " << k << " : " << Achoosen.at(k)->getName() << endl;
					}
					//Escolhendo
					cout << "Qual personagem você deseja escolher (Digite -1 para sair): \n>> ";
					cin >> w;
					if(w != -1)
						Achoosen->push_back(teams.at(i)->searchChar(w)); 
				}

				//Escolhendo os personagens que farão parte da batalha #Time 2
				while(w != -1){
					//Ainda não escolhidos
					cout << "\t\t\t 1# Time " << teams.at(i)->getName() << "\n\t == Integrantes disponiveis\n" << endl;
					for(k = 0; k < (signed)teams.at(i)->numOfCharacters(); k++){
						found = false;
						if(Achoosen->size() != 0){
							//Buscando se o personagem já foi escolhido. Caso já foi, seu nome não será impresso na tela
							for (y = 0; (y < (signed)Achoosen->size()) && (!found); y++)
								//O personagem já foi escolhido
								if(teams.at(i)->searchChar(k)->getName() == Achoosen->at(y)->getName())
									found = true;
						}
						//Personagem não escolhido
						if(!found)
							cout << "- " << k << " : " << teams.at(i)->searchChar(k)->getName()<<endl;
					}
					//Escolhidos
					cout << "\n\t == Integrantes escolhidos\n" << endl;
					if(Achoosen->size() == 0)
						cout << " # Nenhum personagem ainda foi escolhido!" <<endl;
					for(k = 0; k < (signed)Achoosen->size(); k++){
						cout << "- " << k << " : " << Achoosen.at(k)->getName() << endl;
					}
					//Escolhendo
					cout << "Qual personagem você deseja escolher (Digite -1 para sair): \n>> ";
					cin >> w;
					if(w != -1)
						Achoosen->push_back(teams.at(i)->searchChar(w)); 
				}

				//Igualando o número de personagens na batalha
				if(Achoosen->size() != Bchoosen->size()){
					cout << "# Erro! Existem mais personagens selecionados para batalha no time" << (Achoosen->size() > Bchoose->size() ? teams.at(i)->getName() : teams.at(j)->getName());
					cout << "Abaixo você terá que selecionar quais personagens você terá que deixar fora da batalha" << endl;
					//Se Time 1 tiver selecionado mais personagens que o Time 2
					if(Achoosen->size() > Bchoosen->size()){
						found = false;
						//Enquanto o número de personagens não for igual nos dois times
						while(!found){
							for(i = 0; i < (signed)Achoosen->size(); i++){
								cout << "- " << i << " : " << Achoosen.at(i)->getName() << endl;
							}
							cout << ">> Escolha qual o personagem que você deseja remover: \n >> ";
							if((Achoosen->size() - Bchoosen->size()) == 0)
								found = true;
						}
					}
					//Se Time 2 tiver selecionado mais personagens que o Time 1
					else{
						found = false;
						//Enquanto o número de personagens não for igual nos dois times
						while(!found){
							for(i = 0; i < (signed)Bchoosen->size(); i++){
								cout << "- " << i << " : " << Bchoosen.at(k)->getName() << endl;
							}
							if((Bchoosen->size() - Achoosen->size()) == 0)
								found = true;
						}
					}

				}

				//Ordenando de modo randomico os vetores A e B



				//battle
				break;
			}
		}
	}
}

int main(void){
	srand(time(0));
	StandardItems::setVectors();
	vector<Team*> teams;

	main_menu(teams);

	return 0;
}
