#ifndef KNAPSACK_HPP
#define KNAPSACK_HPP

#include "Item.hpp"

#include <vector>

// Represents a knapsack that can hold items with a maximum weight limit.
class Knapsack
{
private:
    int max_weight;                // Maximum weight the knapsack can hold
    std::vector<Item> used_items;  // Items used in the knapsack

public:
    Knapsack();                    // Default constructor
    Knapsack(int max_weight);      // Parameterized constructor

    int getMaxWeight() const;       // Returns the maximum weight
    void setMaxWeight(int weight);  // Sets the maximum weight

    const std::vector<Item>& getUsedItems() const;      // Returns items in the knapsack
    void setUsedItems(const std::vector<Item>& items);  // Sets items in the knapsack

    void addItem(const Item& item);     // Adds an item, maintaining order by ID
    void clearKnapsack();               // Clears all items from the knapsack

    void printKnapsack() const;         // Prints the contents of the knapsack
};

#endif
