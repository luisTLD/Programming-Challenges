#include <iostream>
#include <limits>

#include "Utils/NQueensSolver.hpp"
#include "Utils/MyLib/C++/InputUtils.hpp"

int main()
{
    int board_size = 0;
    std::cout << "Enter de size of the board: ";
    board_size = readInt("Please enter an integer");

    std::cout << "Press Enter to move to the next step " << std::endl;
    std::cin.get();

    Board board(board_size);
    NQueensSolver solver(board);

    if(solver.solveNQueens())
    {
        std::cout << solver;
    }
    else
    {
        std::cout << "No solution exists for a board of size: " << board_size << std::endl;
    }

    return 0;
}
