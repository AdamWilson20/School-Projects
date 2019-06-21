#include "Consumable.h"

Consumable::Consumable()
    :Item("Air",true)

///Default Constructor
{
    this->name = " ";
    this->effect = " ";
    this->uses = 0;
}


Consumable::Consumable(const Consumable &src)
    :Item("Air",true)

{
    this->name = src.name;
    this->effect = src.effect;
    this->uses = src.uses;
}
