#include "../Interfaces/KnapsackSolver.hpp"

#include <algorithm>
#include <vector>

Knapsack KnapsackSolver::solveUnboundedKnapsack(Knapsack& knapsack, std::vector<Item>& items_available)
{
    knapsack.clearKnapsack();

    // Get the total number of available items
    int total_items = items_available.size();

    // Get the maximum weight capacity of the knapsack
    int capacity = knapsack.getMaxWeight();

    // Create a DP array to store the maximum value for each weight capacity
    std::vector<int> array_dp(capacity + 1, 0);

    // Create an array to track which items were taken for each weight capacity
    std::vector<int> item_taken(capacity + 1, -1);

    // Iterate through each capacity from 0 to max capacity
    for (int i = 0; i <= capacity; ++i)
    {
        // Check each item to see if it can fit in the current capacity
        for (int j = 0; j < total_items; ++j)
        {
            // Get the weight of the current item
            int current_weight = items_available[j].getWeight();

            // Check if the current item can fit in the current capacity
            if (current_weight <= i)
            {
                // Check if taking this item increases the value at the current capacity
                if (array_dp[i] < array_dp[i - current_weight] + items_available[j].getValue())
                {
                    // Update the maximum value at this capacity
                    array_dp[i] = array_dp[i - current_weight] + items_available[j].getValue();

                    // Record that we took this item
                    item_taken[i] = j;
                }
            }
        }
    }

    // Start with the full capacity to determine which items to take
    int current_capacity = capacity;
    std::vector<int> items_used; 

    // Backtrack to find which items were used
    while (current_capacity > 0)
    {
        int item_index = item_taken[current_capacity];
        // If an item was taken, add it to the list of used items

        if (item_index != -1)
        {
            items_used.push_back(item_index);

            // Reduce the current capacity by the weight of the taken item
            current_capacity -= items_available[item_index].getWeight();
        } 
        else
        {
            // If no item was taken, we are done
            break;
        }
    }

    // Add the used items to the knapsack
    for (int used : items_used)
    {
        knapsack.addItem(items_available[used]);
    }

    return knapsack; // Return the knapsack with the selected items
}

// Method to solve the bounded knapsack problem
Knapsack KnapsackSolver::solveBoundedKnapsack(Knapsack& knapsack, std::vector<Item>& items_available)
{
    knapsack.clearKnapsack();

    int total_items = items_available.size();
    int capacity = knapsack.getMaxWeight();
    
    std::vector<std::vector<int>> matrix_dp(total_items + 1, std::vector<int>(capacity + 1, 0));

    for (int i = 1; i <= total_items; ++i)
    {
        for (int j = 1; j <= capacity; ++j)
        {
            // If the current item can fit into the capacity j
            if (items_available[i - 1].getWeight() <= j)
            {
                // Decide whether to take the item or not
                matrix_dp[i][j] = std::max(matrix_dp[i - 1][j], 
                    matrix_dp[i - 1][j - items_available[i - 1].getWeight()] + items_available[i - 1].getValue());
            }
            else
            {
                // If the item can't fit, just carry forward the value without taking it
                matrix_dp[i][j] = matrix_dp[i - 1][j];
            }
        }
    }

    std::vector<int> items_used;
    int current_weight = capacity;

    // Backtrack to determine which items were used
    for (int i = total_items; i > 0 && current_weight > 0; --i)
    {
        // Check if the item was included in the optimal solution
        if (matrix_dp[i][current_weight] != matrix_dp[i - 1][current_weight])
        {
            // If it was included, add it to the list of used items
            items_used.push_back(i - 1);

            // Decrease the current weight by the weight of the included item
            current_weight -= items_available[i - 1].getWeight();
        }
    }

    // Add the used items to the knapsack
    for (int used : items_used)
    {
        knapsack.addItem(items_available[used]);
    }

    return knapsack; // Return the knapsack with the selected items
}
