#ifndef MAZESOLVER_HPP
#define MAZESOLVER_HPP

#include <queue>
#include <unordered_map>
#include <fstream>

#include "Maze.hpp"
#include "MazeFileHandler.hpp"

class MazeSolver
{
private:
    Maze maze; 

public:
    // Constructor to initialize the MazeSolver with a Maze
    MazeSolver(const Maze& maze) : maze(maze) {}

    // Solve the maze using Breadth-First Search (BFS)
    bool solveMazeBFS()
    {
        // Indicates whether a solution was found
        bool found = false;

        // Map to reconstruct the correct path from end to start
        std::unordered_map<Point, Point> solution_map;

        // Queue to manage points to be explored
        std::queue<Point> to_explore; 
        to_explore.push(this->maze.getStart());

        while (!to_explore.empty())
        {
            Point current = to_explore.front();

            if (current == this->maze.getEnd())
            {
                found = true;
                break;
            }

            // Mark the current position as visited and explore its neighbors
            markVisited(current);
            addToExplore(getValidNeighbors(current), to_explore, solution_map);
            to_explore.pop();
        }

        // Reconstruct the path if a solution was found
        if (found)
        {
            Point current = this->maze.getEnd();
            std::vector<Point> solution_path;

            while (!(current == this->maze.getStart()))
            {
                solution_path.push_back(current);
                current = solution_map[current];
            }
            solution_path.push_back(this->maze.getStart());

            // Mark the path in the maze
            for (const Point& point : solution_path)
            {
                this->maze[point] = 2;
            }
            
            // Print the maze with the solution path
            this->maze.print();
        }

        if (found)
        {
            char choice;
            std::cout << "Do you want to save the solution in a file? (y/n): ";
            std::cin >> choice;
            if (choice == 'y' || choice == 'Y') MazeFileHandler::saveSolutionToFile(this->maze);
        }
        
        return found;
    }

    // Return valid neighbors of a given position (within bounds and not walls)
    std::vector<Point> getValidNeighbors(const Point& position) const
    {
        std::vector<Point> valid_neighbors;
        const std::vector<Point> neighbors = position.getNeighbors();

        for (const Point& neighbor : neighbors)
        {
            if (this->maze.isValid(neighbor) && !isVisited(neighbor))
            {
                valid_neighbors.push_back(neighbor);
            }
        }

        return valid_neighbors;
    }

    // Check if a position has been visited
    bool isVisited(const Point& position) const
    {
        return this->maze.getVisitedPoint(position);
    }

    // Mark a position as visited
    void markVisited(const Point& position) 
    {
        this->maze.setVisitedPoint(position);
    }

    // Add neighbors to the exploration queue and update the solution map
    void addToExplore(const std::vector<Point>& neighbors, std::queue<Point>& to_explore, std::unordered_map<Point, Point>& solution_map)
    {
        for (const Point& neighbor : neighbors)
        {
            to_explore.push(neighbor);
            solution_map[neighbor] = to_explore.front(); // Update the map to reconstruct the path
        }
    }

};

#endif
