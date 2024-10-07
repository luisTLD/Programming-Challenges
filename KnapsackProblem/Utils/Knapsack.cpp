#include "../Interfaces/Knapsack.hpp"
#include "../Interfaces/ValuesFileHandler.hpp"

#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>

Knapsack::Knapsack() : max_weight(0), used_items() {}
Knapsack::Knapsack(int max_weight) : max_weight(max_weight), used_items() {}

int Knapsack::getMaxWeight() const {return max_weight;}
void Knapsack::setMaxWeight(int weight) {max_weight = weight;}

const std::vector<Item>& Knapsack::getUsedItems() const {return used_items;}
void Knapsack::setUsedItems(const std::vector<Item>& items) {used_items = items;}

void Knapsack::addItem(const Item& item)
{
    // Finds the position of the item using binary search to maintain order by ID
    auto pos = std::lower_bound(used_items.begin(), used_items.end(), item); 
    used_items.insert(pos, item);
}
void Knapsack::clearKnapsack() {used_items.clear();}

void Knapsack::printKnapsack() const
{
    // Using stringstream to collect output
    std::stringstream ss;
    ss << "Knapsack max weight: " << max_weight << std::endl;
    ss << "\nItems used: ";

    // Check if knapsack is empty
    if (used_items.empty())
    {
        std::cout << "The knapsack is empty." << std::endl;
        return;
    }

    int total_amount = 0;
    int total_weight = 0;
    int total_value = 0;
    int current_amount = 0;

    int total_items = used_items.size();
    for (int i = 0; i < total_items; i++)
    {
        current_amount++;

        // Update totals
        total_amount++;
        total_weight += used_items[i].getWeight();
        total_value += used_items[i].getValue();

        // Check for item ID change or end of the list
        if ((i + 1 == total_items) || (used_items[i].getId() != used_items[i + 1].getId()))
        {
            ss << used_items[i].stringItem();
            ss << "Amount: " << current_amount << 
            "    Weight Sum: " << current_amount * used_items[i].getWeight() <<
            "    Value Sum: " << current_amount * used_items[i].getValue() << 
            std::endl;

            current_amount = 0; // Reset for next item
        }
    }

    // Summary of the knapsack
    ss << "\nKnapsack:\nTotal Items:  " << total_amount <<
    "\nTotal weight: " << total_weight <<
    "\nTotal value:  " << total_value << std::endl;

    // Print the collected string output
    std::cout << ss.str();

    // Ask user if they want to save the output to a file
    char choice;
    std::cout << "Do you want to save the solution in a file? (y/n): ";
    std::cin >> choice;

    // If yes, call the save function
    if (choice == 'y' || choice == 'Y') ValuesFileHandler::saveSolutionToFile(ss);
}