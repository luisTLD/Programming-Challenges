#include <iostream>
#include <limits>

#include "utils/Hanoi.hpp"

int main()
{
    int tower_height = 0;
    do 
    {
        std::cout << "Enter the height of the tower: ";
        std::cin >> tower_height;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (std::cin.fail()) 
        {
            std::cerr << "Please enter an integer" << std::endl;
            std::cin.clear();
        }
    } while (tower_height < 1);

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
