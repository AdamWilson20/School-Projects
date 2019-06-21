#ifndef TOOL_H_INCLUDED
#define TOOL_H_INCLUDED

#include "Item.h"

/**
 * This class represents one tool--as found in most video games. This includes
 * pickaxes and shovels.
 *
 * Tools may not be stacked. All Constructors must initialize Item::stackable
 * to false.
 */
 ///Tool = child & Item = Parent
class Tool : public Item{
    private:

    protected:
        double      durability;    ///< decreases each time the tool is used
        double      speed;         ///< base harvest/mine speed
        std::string material;      ///< material out of which the tool is composed
        std::string modifier;      ///< one of efficiency, fortune, or unbreaking
        int         modifierLevel; ///< modifier level in the range 1 to 5

    public:
        /**
         * Default to a tool with an empty name
         */
        Tool();

        /**
         * Copy Constructor
         */
        Tool( const Tool &src );

         virtual void display(std::ostream &outs) const;

        /**
         * Read the item from an input stream
         */
        virtual void read(std::istream& ins) = 0;

        /**
         * Copy this Item--i.e., duplicate this Item
         */
        virtual Item* clone() const = 0;

};



#endif
