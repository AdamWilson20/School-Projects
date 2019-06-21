#include "Tool.h"

Tool::Tool()
    :Item("Air",false)

 ///Default Constructor
{
    this->name = " ";
    this->durability = 0.0;
    this->speed = 0.0;
    this->material = " ";
    this->modifier = " ";
    this->modifierLevel = 0;
}


Tool::Tool(const Tool &src)
    :Item("Air",false)

///Copy Constructor
{
    this->name = src.name;
    this->durability = src.durability;
    this->speed = src.speed;
    this->material = src.material;
    this->modifier = src.modifier;
    this->modifierLevel = src.modifierLevel;
}

