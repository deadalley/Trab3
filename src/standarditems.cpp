#include "standarditems.h"

StandardItems::StandardItems(){

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
    std_weapons.push_back(dagger);
    std_weapons.push_back(short_sword);
    std_weapons.push_back(long_sword);
    std_weapons.push_back(scythe);
    std_weapons.push_back(axe);
}

void StandardItems::print(std::vector<Item*>& v){
    std::vector<Item*>::iterator it;
    int i = 1;
    for(it = v.begin(); it != v.end(); ++it){
        std::cout << i << " ";
        std::cout << (*it)->getName() << std::endl;
        i++;
    }
}

static void StandardItems::printArmors(){
    print(std_armors);
}

void StandardItems::printHealthPotions(){
    print(std_health_potions);
}

void StandardItems::printManaPotions(){
    print(std_mana_potions);
}

void StandardItems::printWeapons(){
    print(std_weapons);
}

static Armor* StandardItems::getArmor(int k){
    return dynamic_cast<Armor*>(StandardItems::std_armors.at(k));
}

HealthPotion* StandardItems::getHealthPotion(int k){
    return dynamic_cast<HealthPotion*>(std_health_potions.at(k));
}

ManaPotion* StandardItems::getManaPotion(int k){
    return dynamic_cast<ManaPotion*>(std_mana_potions.at(k));
}

Weapon* StandardItems::getWeapon(int k){
    return dynamic_cast<Weapon*>(std_weapons.at(k));
}