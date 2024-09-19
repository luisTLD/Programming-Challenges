#ifndef MAZEFILEHANDLER_HPP
#define MAZEFILEHANDLER_HPP

#include <fstream>
#include <iostream>
#include <string>

#include "MazeSolver.hpp"

class MazeFileHandler
{
public:
    // Loads the maze from a file
    static bool loadMazeFromFile(const std::string& filename, Maze& maze);

    // Saves the solution of the maze to a file
    static void saveSolutionToFile(const Maze& maze);
};

#endif
