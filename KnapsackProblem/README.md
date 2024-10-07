# Knapsack Problem Solver

This repository contains a C++ implementation to solve the Knapsack problem, including both Bounded and Unbounded versions where items can be repeated. The program allows you to input item weights and values through a text file, making it easy to test different scenarios.

## Input Format

The input file must be placed in the **Values** folder. The first line should specify the maximum weight that the knapsack can carry. Each subsequent line should detail the weights and values of the items in the following format:

5  
2 2  
1 1  
2 2

In this example:
- The first line (`5`) indicates the maximum weight capacity of the knapsack.
- Each following line contains two integers: the first integer represents the weight of the item, and the second integer represents its value.

Ensure that your input file is located in the **Values** folder, and when prompted by the program, only input the filename (without the `.txt` extension), as the program will automatically append the `.txt` extension for you.


## Output

The program can also save the solution to a text file, including:
- The items used
- The quantity of each item
- The total number of items included
- The total weight achieved
- The maximum value attained

## Code Structure

I'm currently practicing techniques to keep the code clean by utilizing interfaces and separating function declarations. This approach is experimental, and I may decide to change the structure in the future based on the results of my testing.

Feel free to explore the code, test it with different inputs, and provide feedback!
