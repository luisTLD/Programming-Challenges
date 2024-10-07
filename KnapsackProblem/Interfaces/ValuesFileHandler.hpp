#ifndef VALUESFILEHANDLER_HPP
#define VALUESFILEHANDLER_HPP

#include "Item.hpp"
#include "Knapsack.hpp"

#include <vector>
#include <iostream>

// Handles loading and saving knapsack values from/to files.
class ValuesFileHandler
{
public:
    // Loads items from a file into the knapsack
    static bool loadValuesFromFile(const std::string& filename, Knapsack& knapsack, std::vector<Item>& items);

    // Saves the solution to a file
    static bool saveSolutionToFile(std::stringstream& ss); // Saves the solution to a file
};

#endif
