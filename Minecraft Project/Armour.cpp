#include "Armour.h"

Armour::Armour()
    Item("Air",false);

///Default Constructor
{
    this->name = " ";
    this->durability = 0.0;
    this->defense = 0.0;
    this->material = " ";
    this->modifier = " ";
    this->modifierLevel = 0;
    this->element = " ";
}

Armour::Armour(const Armour &src)
        Item("Air",false);

///Copy Constructor
{
    this->name = src.name;
    this->durability = src.durability;
    this->defense = src.defense;
    this->material = src.material;
    this->modifier = src.modifier;
    this->modifierLevel = src.modifierLevel;
    this->element = src.element;
}
