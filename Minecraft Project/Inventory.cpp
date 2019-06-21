#include <iomanip>
#include <utility>

#include "Inventory.h"

// Allow the compiler to define the remaining 
// comparison operators
using namespace std::rel_ops;

/**
 *
 */
Inventory::Inventory()
{
    this->capacity    = 10;
}

/**
 *
 */
Inventory::Inventory(int n)
{
    this->capacity = n;
}

/**
 *
 */
bool Inventory::addItems(ItemStack itemStack)
{
    Iterator matchingIterator = findMatchingItemStackIterator(itemStack);

    // A match was found && 
    if(matchingIterator != slots.end()) {  
        // the item is stackable     
        if (matchingIterator->permitsStacking()) {

            matchingIterator->addItems(itemStack.size());
            return true;
        }        
    }

    // There is no space for a new `ItemStack`
    if(this->isFull()) {
        return false;
    }

    // This is a new type of item and there is plenty of room
    addItemStackNoCheck(itemStack);
    return true;
}

/**
 *
 */
bool Inventory::isFull() const
{
    return (slots.size() == capacity);
}

/**
 *
 */
void Inventory::display(std::ostream &outs) const
{
    // Compute % full rounded to nearest whole number
    int percent_filled = (100.0 * slots.size() / capacity) + 0.5;

    // Print the usage summary
    outs << " -Used " << std::right << std::setw(3)
         << percent_filled << "\% of " 
         << capacity << " slots" << "\n";

    // Print the Items
    for(ItemStack slot : slots){
        outs << slot << "\n";
    }
}

/**
 *
 */
Inventory::Iterator Inventory::findMatchingItemStackIterator(const ItemStack& itemStack)
{
    Inventory::Iterator it = slots.begin();

    // search for a matching stack
    while(it != slots.end()){
        if(*it == itemStack) {
            return it;
        }

        it++;
    }

    // No match was found
    return slots.end();
}

/**
 *
 */
void Inventory::addItemStackNoCheck(ItemStack itemStack)
{
    slots.push_back(itemStack);
}