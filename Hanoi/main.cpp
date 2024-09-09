#include <iostream>
#include <limits>

#include "Utils/Hanoi.hpp"
#include "Utils/MyLib/C++/InputUtils.hpp"

int main()
{
    int tower_height = 0;
    std::cout << "Enter the height of the tower: ";
    tower_height = readInt("Please enter an integer");

    try
    {
        Hanoi hanoi(tower_height);
        std::cout << "\nInitial state of the towers: " << std::endl;
        hanoi.showTowers();

        std::cout << "Press Enter to move to the next step " << std::endl;
        std::cin.get();
        hanoi.solveHanoi();

        std::cout << "Final state of the towers:" << std::endl;
        hanoi.showTowers();
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
