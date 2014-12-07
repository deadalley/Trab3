#ifndef H_STANDARDITEMS
#define H_STANDARDITEMS

#include <vector>
#include <string>
#include <sstream>
#include "armor.h"
#include "weapon.h"
#include "healthpotion.h"
#include "manapotion.h"

//Defines the standard items in the game. Extra items cannot be created outside of this class
class StandardItems {
private:
    StandardItems();

    //Armors
    static Armor *leather_armor;
    static Armor *iron_armor;
    static Armor *silver_armor;
    static Armor *gold_armor;
    static Armor *diamond_armor;

    //Weapons
    static Weapon *dagger;
    static Weapon *short_sword;
    static Weapon *long_sword;
    static Weapon *scythe;
    static Weapon *axe;
    static Weapon *spear;
    static Weapon *bow;
    static Weapon *staff;
    static Weapon *wand;
    static Weapon *tesseract;

    //Potions
    static ManaPotion *minor_mana_potion;
    static ManaPotion *light_mana_potion;
    static ManaPotion *full_mana_potion;

    static HealthPotion *minor_health_potion;
    static HealthPotion *light_health_potion;
    static HealthPotion *regular_health_potion;
    static HealthPotion *full_health_potion;
    static HealthPotion *ultra_health_potion;

    //Arrays
    static std::vector<Item*> std_armors;
    static std::vector<Item*> std_potions;
    static std::vector<Item*> std_weapons;

    void static print(std::vector<Item*>&);

public:
    static void setVectors();
    static void printArmors();
    static void printPotions();
    static void printWeapons();

    static Armor* getArmor(int k);
    static Potion* getPotion(int k);
    static Weapon* getWeapon(int k);
};

#endif

