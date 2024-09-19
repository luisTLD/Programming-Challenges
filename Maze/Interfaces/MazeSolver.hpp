#ifndef MAZESOLVER_HPP
#define MAZESOLVER_HPP

#include <queue>
#include <unordered_map>
#include <fstream>

#include "Point.hpp"
#include "Maze.hpp"
#include "MazeFileHandler.hpp"

class MazeSolver
{
private:
    Maze maze; // Maze object to be solved

public:
    // Constructor to initialize the MazeSolver with a Maze
    MazeSolver(const Maze& maze);

    // Solves the maze using Breadth-First Search (BFS)
    bool solveMazeBFS();

    // Returns valid neighbors of a given position (within bounds and not walls)
    std::vector<Point> getValidNeighbors(const Point& position) const;

    // Checks if a position has been visited
    bool isVisited(const Point& position) const;

    // Marks a position as visited
    void markVisited(const Point& position);

    // Adds neighbors to the exploration queue and updates the solution map
    void addToExplore(const std::vector<Point>& neighbors, std::queue<Point>& to_explore, std::unordered_map<Point, Point>& solution_map);
};

#endif
