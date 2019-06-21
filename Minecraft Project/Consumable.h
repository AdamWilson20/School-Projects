#ifndef CONSUMABLE_H_INCLUDED
#define CONSUMABLE_H_INCLUDED

#include "Item.h"

/**
 * This class represents one Consumable Item--as found in most video games. This includes
 * food.
 *
 * Consumable Items must be stackable. All Constructors must initialize Item::stackable
 * to true.
 */
class Consumable : public Item{
    private:

    protected:
        std::string effect; ///< effect recieved by using the Item
        int uses;           ///< number of times this Item can be used

    public:
        /**
         * Default to a Consumable Item with an empty name
         */
        Consumable();

        /**
         * Copy Constructor
         */
        Consumable( const Consumable &src );

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
