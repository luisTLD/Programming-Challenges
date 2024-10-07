#ifndef ITEM_HPP
#define ITEM_HPP

#include <iostream>

// Represents an item with an ID, weight, and value.
class Item
{
private:
    int id;       // Unique identifier for the item
    int weight;   // Weight of the item
    int value;    // Value of the item

public:
    Item();  // Default constructor
    Item(int id, int weight, int value);  // Parameterized constructor

    int getId() const;          // Returns the item ID
    void setId(int new_id);     // Sets the item ID

    int getWeight() const;       // Returns the item weight
    void setWeight(int w);       // Sets the item weight

    int getValue() const;        // Returns the item value
    void setValue(int v);        // Sets the item value

    void printItem() const;          // Prints item details to console
    std::string stringItem() const;  // Returns item details as a string

    bool operator<(const Item& other) const;  // Compares items based on value
};

#endif
