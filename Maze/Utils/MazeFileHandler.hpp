#ifndef MAZEFILEHANDLER_HPP
#define MAZEFILEHANDLER_HPP

#include "MazeSolver.hpp"

class MazeFileHandler
{
public:
    // Function to load maze from a file
    static bool loadMazeFromFile(const std::string& filename, Maze& maze) 
    {
        std::ifstream file(filename);
        if (!file.is_open())
        {
            std::cerr << "Failed to open file: " << filename << std::endl;
            return false;
        }

        int rows, cols;
        file >> rows >> cols;

        std::vector<std::vector<int>> input_grid(rows, std::vector<int>(cols));
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                file >> input_grid[i][j];
            }
        }

        int start_x, start_y, end_x, end_y;
        file >> start_x >> start_y;
        file >> end_x >> end_y;

        Point start(start_x, start_y);
        Point end(end_x, end_y);

        maze = Maze(input_grid, start, end, rows, cols);

        file.close();
        return true;
    }

    // Function to save the solution of the maze to a file
    static void saveSolutionToFile(const Maze& maze) 
    {
        // Get the desired filename from the user
        std::string filename;
        std::cout << "Enter the filename to save the solution: ";
        std::cin >> filename;

        // Save the solved maze to a file
        std::ofstream output_file("Solutions/" + filename + ".txt");
        if (output_file.is_open())
        {
            for (const std::vector<int>& row : maze.getGrid())
            {
                for (int cell : row)
                {
                    if (cell == 0) output_file << " . ";        // Open space
                    else if (cell == 1) output_file << " # ";   // Wall
                    else output_file << " + ";                  // Path
                }
                output_file << std::endl;
            }
            output_file.close();
        }
        else
        {
            std::cerr << "Unable to open file for writing." << std::endl;
        }
    }
};

#endif
