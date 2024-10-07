#ifndef KNAPSACKSOLVER_HPP
#define KNAPSACKSOLVER_HPP

#include "Item.hpp"
#include "Knapsack.hpp"

class KnapsackSolver
{ 
public:
    // Method to solve the unbounded knapsack problem
    static Knapsack solveUnboundedKnapsack(Knapsack& knapsack, std::vector<Item>& items_available);

    // Method to solve the bounded knapsack problem
    static Knapsack solveBoundedKnapsack(Knapsack& knapsack, std::vector<Item>& items_available);
};

#endif
