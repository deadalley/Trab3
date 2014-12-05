#ifndef "H_STANDARDITEMS"
#define "H_STANDARDITEMS"

#include <vector>
#include "armor.h"
#include "weapon.h"
#include "healthpotion.h"
#include "manapotion.h"

class StandardItems {
    //Armors
    static Armor leather_armor("Leather Armor", 12.0, 4, 3.0);
    static Armor iron_armor("Iron Armor", 13.0, 10, 6.0);
    static Armor silver_armor("Silver Armor", 15.0, 15, 8.0);
    static Armor gold_armor("Gold Armor", 27.0, 18, 11.0);
    static Armor diamond_armor("Diamond Armor", 40.0, 19, 14.0);

    //Weapons
    static Weapon dagger("Dagger", 12.0, 4, 4.0);
    static Weapon short_sword("Short Sword", 16.0, 6, 5.0);
    static Weapon long_sword("Long Sword", 22.0, 7, 10.0);
    static Weapon scythe("Scythe of Doom", 28.0, 9, 16.0);
    static Weapon axe("Generic Axe", 30.0, 9, 18.0);

    static Weapon spear("Generic Spear", 14.0, 6, 14.0);
    static Weapon bow("Generic Bow", 18.0, 9, 28.0);
    static Weapon staff("Generic Staff", 23.0, 8, 12.0);
    static Weapon wand("Generic Wand", 20.0, 8, 2.0);
    static Weapon tesseract("Tesseract", 1300.0, 9, 45.0);

    //Potions
    static ManaPotion minor_mana_potion("Minor Mana Potion", 5.0, 3);
    static ManaPotion light_mana_potion("Light Mana Potion", 8.0, 5);
    static ManaPotion full_mana_potion("Full Mana Potion", 10.0, 10);

    static HealthPotion minor_health_potion("Minor Health Potion", 5.0, 3);
    static HealthPotion light_health_potion("Light Health Potion", 8.0, 5);
    static HealthPotion regular_health_potion("Regular Health Potion", 10.0, 8);
    static HealthPotion full_health_potion("Full Health Potion", 15.0, 10);
    static HealthPotion ultra_health_potion("Ultra Health Potion", 25.0, 18);

    //Arrays
    static std::vector<Armor> std_armors;
    static std::vector<HealthPotion> std_health_potions;
    static std::vector<ManaPotion> std_mana_potions;
    static std::vector<Weapon> std_weapons;

public:
    StandardItems() {
        //Adding armors to vector
        std_armors.push_back(leather_armor);
        std_armors.push_back(iron_armor);
        std_armors.push_back(silver_armor);
        std_armors.push_back(gold_armor);
        std_armors.push_back(diamond_armor);

        //Adding health potions to vector
        std_health_potions.push_back(minor_health_potion);
        std_health_potions.push_back(light_health_potion);
        std_health_potions.push_back(regular_health_potion);
        std_health_potions.push_back(full_health_potion);
        std_health_potions.push_back(ultra_health_potion);

        //Adding mana potions to vector
        std_mana_potions.push_back(minor_mana_potion);
        std_mana_potions.push_back(light_mana_potion);
        std_mana_potions.push_back(full_mana_potion);

        //Adding weapons to vector
        std_weapons.push_back()
    }
};

#endif
