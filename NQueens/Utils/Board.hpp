#ifndef BOARD_HPP
#define BOARD_HPP

#include <iostream>
#include <vector>

class Board
{
private:
    int size;
    std::vector<std::vector<int>> grid;

public:
    Board(int size) : size(size), grid(size, std::vector<int>(size, 0)) {}

    // Get Size
    int getSize()
    {
        return this->size;
    }

    // Check if a position is safe for placing a queen
    bool isSafe(int row, int col) const
    {
        bool verify = true;

        for (int i = 0; verify && i < row; i++)
        {
            if (this->grid[i][col] != 0) verify = false;
            if (col - (row - i) >= 0 && this->grid[i][col - (row - i)] != 0) verify = false;
            if (col + (row - i) < this->size && this->grid[i][col + (row - i)] != 0) verify = false;
        }

        return verify;
    }

    // Place a queen on the board
    void placeQueen(int row, int col)
    {
        this->grid[row][col] = 1;
    }

    // Remove a queen from the board
    void removeQueen(int row, int col)
    {
        if (this->grid[row][col] == 1) this->grid[row][col] = 0;
    }

    // Print the current state of the board
    void printBoard() const
    {
        for (int i = 0; i < this->size; i++)
        {
            for (int j = 0; j < this->size; j++)
            {
                std::cout << this->grid[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    // Reset the board to the initial state
    void resetBoard()
    {
        for (int i = 0; i < this->size; i++)
        {
            for (int j = 0; j < this->size; j++)
            {
               this->grid[i][j] = 0;
            }
        }
    }

};


#endif