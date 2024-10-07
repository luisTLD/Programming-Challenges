#include "../Interfaces/ValuesFileHandler.hpp"

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

// Load values from a file into the knapsack and item list
bool ValuesFileHandler::loadValuesFromFile(const std::string& filename, Knapsack& knapsack, std::vector<Item>& items)
{
    std::ifstream file(filename);
    
    if (!file.is_open())
    {
        std::cerr << "Error opening file: " << filename << std::endl;
        return false;
    }

    std::string line;
    
    if (std::getline(file, line)) // Read the first line for max weight
    {
        std::stringstream ss(line);
        int maxWeight;
        ss >> maxWeight; // Get max weight from the line
        knapsack.setMaxWeight(maxWeight); // Set max weight in the knapsack
    }

    int id = 1; // Initialize item ID
    while (std::getline(file, line)) // Read the rest of the lines for items
    {
        std::stringstream ss(line);
        int weight, value;
        ss >> weight >> value; // Get weight and value from the line
        items.push_back(Item(id++, weight, value)); // Add new item to the list
    }

    file.close();
    return true;
}

bool ValuesFileHandler::saveSolutionToFile(std::stringstream& ss)
{
    std::string filename;
    std::cout << "Enter the filename to save the solution: ";
    std::cin >> filename;

    std::ofstream output_file("Solutions/" + filename + ".txt");
    if (output_file.is_open())
    {
        output_file << ss.str(); // Write the solution to the file
        output_file.close();
    }
    else
    {
        std::cerr << "Unable to open file for writing." << std::endl;
    }
}
