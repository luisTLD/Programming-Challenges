#include "Interfaces/AllInterfaces.hpp"

// g++ -IInterfaces -o main main.cpp Utils/Point.cpp Utils/Maze.cpp Utils/MazeSolver.cpp Utils/MazeFileHandler.cpp

int main()
{
    int rows, cols;
    char choice;

    std::cout << "Do you want to load the maze from a file? (y/n): ";
    std::cin >> choice;

    Maze maze; 

    if (choice == 'y' || choice == 'Y')
    {
        std::string filename;
        std::cout << "Enter the filename: ";
        std::cin >> filename;

        if (!MazeFileHandler::loadMazeFromFile("Mazes/" + filename + ".txt", maze))
        {
            std::cerr << "Error loading maze from file." << std::endl;
            return 1;
        }
    }
    else
    {
        // Input for the maze dimensions
        std::cout << "Enter the number of rows in the maze: ";
        std::cin >> rows;
        std::cout << "Enter the number of columns in the maze: ";
        std::cin >> cols;

        // Create the input matrix
        std::vector<std::vector<int>> input_grid(rows, std::vector<int>(cols));

        // Filling the matrix row by row
        std::cout << "Fill in the maze row by row (0 for free path, 1 for wall):\n";
        for (int i = 0; i < rows; ++i)
        {
            std::cout << "Enter values for row " << i + 1 << ": ";
            for (int j = 0; j < cols; ++j)
            {
                std::cin >> input_grid[i][j];
            }
        }

        // Input for the start and end points
        int start_x, start_y, end_x, end_y;
        std::cout << "Enter the start coordinates (x y): ";
        std::cin >> start_x >> start_y;
        std::cout << "Enter the end coordinates (x y): ";
        std::cin >> end_x >> end_y;

        // Create start and end points
        Point start(start_x, start_y);
        Point end(end_x, end_y);

        // Create an instance of Maze with the filled matrix, start and end points
        maze = Maze(input_grid, start, end, rows, cols);
    }

    // Print the maze
    std::cout << "\nMaze:\n";
    maze.print();
    std::cout << std::endl;

    // Create a MazeSolver instance and solve the maze
    MazeSolver solver(maze);

    // Ask the user to choose between DFS or BFS for solving the maze.
    char method_choice;
    std::cout << "Choose a method to solve the maze (D for DFS, B for BFS): ";
    std::cin >> method_choice;
    
    // Solve the maze based on the user's choice.
    if (method_choice == 'D' || method_choice == 'd')
    {
        if (!solver.solveMazeDFS())
        {
            std::cout << "Unable to solve the maze using DFS" << std::endl;
        }
    }
    else if (method_choice == 'B' || method_choice == 'b')
    {
        if (!solver.solveMazeBFS())
        {
            std::cout << "Unable to solve the maze using BFS" << std::endl;
        }
    }
    else
    {
        std::cout << "Invalid choice. Please choose either D (DFS) or B (BFS)." << std::endl;
    }

    return 0;
}