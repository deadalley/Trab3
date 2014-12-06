#ifndef H_STANDARDITEMS
#define H_STANDARDITEMS

#include <vector>
#include <string>
#include "armor.h"
#include "weapon.h"
#include "healthpotion.h"
#include "manapotion.h"

class StandardItems {
public:
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
    std::vector<Item*> std_armors;
    std::vector<Item*> std_health_potions;
    std::vector<Item*> std_mana_potions;
    std::vector<Item*> std_weapons;

    void print(std::vector<Item*>&);

    StandardItems();

    static void printArmors();
    void printHealthPotions();
    void printManaPotions();
    void printWeapons();

    static Armor* getArmor(int k);
    HealthPotion* getHealthPotion(int k);
    ManaPotion* getManaPotion(int k);
    Weapon* getWeapon(int k);
};

#endif

