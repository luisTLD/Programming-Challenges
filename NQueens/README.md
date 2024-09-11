# NQueensSolver

## Overview

This project implements the classic N-Queens problem using C++. It is designed to place N queens on an NxN chessboard such that no two queens threaten each other. This project serves as a learning tool for understanding backtracking algorithms and operator overloading in C++.

## Features

- **Backtracking Algorithm**: Utilizes a recursive backtracking approach to solve the N-Queens problem.
- **Operator Overloading**: Demonstrates operator overloading by implementing `std::ostream& operator<<(std::ostream& os, const NQueensSolver& solver)` to print the board.
- **Step-by-Step Visualization**: Prints the board step-by-step with a delay to visualize the process of placing and removing queens.
- **Solution Status**: Indicates whether a solution exists for the given N, and displays the board configuration during the solving process.

## Learning Goals

- **Backtracking**: Implemented to solve the problem efficiently by exploring potential solutions and backtracking when a conflict is detected.
- **Operator Overloading**: Used to enhance the functionality of the `<<` operator for displaying the board state.
- **Visualization**: Provides a visual representation of the algorithm's progress by showing the board at each step of placing or removing queens.

## Future Work

- **Complete Solutions**: Plan to enhance the project to display all possible solutions for the N-Queens problem.
- **Optimizations**: Explore and implement optimizations to improve the efficiency of the backtracking algorithm.
