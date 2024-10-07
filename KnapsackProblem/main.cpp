#include <iostream>
#include <vector>
#include "Interfaces/AllInterfaces.hpp" 

// g++ -IInterfaces -o main main.cpp Utils/*.cpp

int main()
{
    char choice;

    std::cout << "Do you want to load the values from a file? (y/n): ";
    std::cin >> choice;

    Knapsack knapsack;
    std::vector<Item> items; 

    if (choice == 'y' || choice == 'Y')
    {
        std::string filename;
        std::cout << "Enter the filename: ";
        std::cin >> filename;

        if (!ValuesFileHandler::loadValuesFromFile("Values/" + filename + ".txt", knapsack, items))
        {
            std::cerr << "Error loading Items from file." << std::endl;
            return 1;
        }
    }
    else
    {
        int total_weight = 0;
        std::cout << "Enter the weight of the knapsack: ";
        std::cin >> total_weight;
        knapsack.setMaxWeight(total_weight);

        int total_items = 0;
        std::cout << "Enter the amount of items: ";
        std::cin >> total_items;

        std::cout << "Enter the weight and value of each item (ex: 3 5 -> weight = 3, value = 5)" << std::endl;
        int item_weight = 0;
        int item_value = 0;
        for (int i = 1; i <= total_items; i++)
        {
            std::cin >> item_weight >> item_value;
            items.push_back(Item(i, item_weight, item_value));
        }

    }

    char method_choice;
    std::cout << "Choose a method to solve the knapsack problem (U for Unbounded, B for Bounded): ";
    std::cin >> method_choice;
    
    if (method_choice == 'U' || method_choice == 'u')
    {
        KnapsackSolver::solveUnboundedKnapsack(knapsack, items);
    }
    else if (method_choice == 'B' || method_choice == 'b')
    {
        KnapsackSolver::solveBoundedKnapsack(knapsack, items);
    }
    else
    {
        std::cout << "Invalid choice. Please choose either U (Unbounded) or B (Bounded)." << std::endl;
    }

    knapsack.printKnapsack();

    return 0;
}