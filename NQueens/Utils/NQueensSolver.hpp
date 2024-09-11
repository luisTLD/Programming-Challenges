#ifndef NQUEENSSOLVER_HPP
#define NQUEENSSOLVER_HPP

#include <thread>
#include <chrono>

#include "Board.hpp"

class NQueensSolver
{
private:
    Board board;

public:
    NQueensSolver(Board board) : board(board) {}

    // Function to start solving the N-Queens problem from row 0
    bool solveNQueens()
    {
        return solveNQueensRec(0);
    }

    // Recursive function to place queens row by row, starting from the given row
    bool solveNQueensRec(int actRow)
    {
        bool verify = false;

        if (actRow == board.getSize())
        {
            return true;
        }
        
        for (int i = 0; i < board.getSize(); i++)
        {
            if (board.isSafe(actRow, i))
            {
                board.placeQueen(actRow, i);
                printBoardWithDelay();
                
                if (solveNQueensRec(actRow + 1))
                {
                    verify = true;
                    break;
                }
            }

            if (!verify)
            {
                board.removeQueen(actRow, i);
                printBoardWithDelay();
            }
        }

        return verify;
    }

    // Overloading the << operator to print the board
    friend std::ostream& operator<<(std::ostream& os, const NQueensSolver& solver)
    {
        solver.board.printBoard();
        return os;
    }
    
    // Helper function to print the board and add delay
    void printBoardWithDelay()
    {
        std::cout << *this << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(600));
    }

};


#endif