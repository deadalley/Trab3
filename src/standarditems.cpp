#include "standarditems.h"

std::vector<Item*> StandardItems::std_armors;
std::vector<Item*> StandardItems::std_potions;
std::vector<Item*> StandardItems::std_weapons;

void StandardItems::setVectors()
{
    //Adding armors to vector
    std_armors.push_back(leather_armor);
    std_armors.push_back(iron_armor);
    std_armors.push_back(silver_armor);
    std_armors.push_back(gold_armor);
    std_armors.push_back(diamond_armor);

    //Adding health potions to vector
    std_potions.push_back(minor_health_potion);
    std_potions.push_back(light_health_potion);
    std_potions.push_back(regular_health_potion);
    std_potions.push_back(full_health_potion);
    std_potions.push_back(ultra_health_potion);

    //Adding mana potions to vector
    std_potions.push_back(minor_mana_potion);
    std_potions.push_back(light_mana_potion);
    std_potions.push_back(full_mana_potion);

    //Adding weapons to vector
    std_weapons.push_back(dagger);
    std_weapons.push_back(short_sword);
    std_weapons.push_back(long_sword);
    std_weapons.push_back(scythe);
    std_weapons.push_back(axe);
    std_weapons.push_back(spear);
    std_weapons.push_back(bow);
    std_weapons.push_back(staff);
    std_weapons.push_back(wand);
    std_weapons.push_back(tesseract);
}

void StandardItems::print(std::vector<Item*>& v)
{
    std::vector<Item*>::iterator it;
    int i = 1;
    for(it = v.begin(); it != v.end(); ++it){
        std::cout << i << ". ";
        std::cout << (*it)->getName();
        std::stringstream stream;
        stream << " (" << (*it)->getPrice() << "G)\n";
        std::cout << stream.str();
        i++;
    }
}

void StandardItems::printArmors()
{
    print(std_armors);
}

void StandardItems::printPotions()
{
    print(std_potions);
}

void StandardItems::printWeapons()
{
    print(std_weapons);
}

Armor* StandardItems::getArmor(int k)
{
    return dynamic_cast<Armor*>(StandardItems::std_armors.at(k));
}

Potion* StandardItems::getPotion(int k)
{
    return dynamic_cast<Potion*>(std_potions.at(k));
}

Weapon* StandardItems::getWeapon(int k)
{
    return dynamic_cast<Weapon*>(std_weapons.at(k));
}