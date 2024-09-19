#ifndef MAZE_HPP
#define MAZE_HPP

#include <iostream>
#include <vector>
#include "Point.hpp" 

class Maze
{
private:
    std::vector<std::vector<int>> grid;         // 2D grid representing the maze
    std::vector<std::vector<bool>> visited;     // Matrix to track visited cells
    Point start;                                // Starting point
    Point end;                                  // Ending point
    int rows, cols;                             // Number of rows and columns in the maze

public:
    // Constructor to initialize the maze with a grid, start and end points, and its dimensions
    Maze(const std::vector<std::vector<int>>& input_grid, Point start, Point end, int rows, int cols)
        : grid(input_grid), start(start), end(end), rows(rows), cols(cols),
        visited(rows, std::vector<bool>(cols, false)) {}  // Initialize 'visited' matrix to false for all cells

    Maze() : rows(0), cols(0), start(0, 0), end(0, 0), 
            grid(std::vector<std::vector<int>>()), 
            visited(std::vector<std::vector<bool>>()) {}

    // Check if the point is within the bounds of the maze and not a wall
    bool isValid(const Point& point) const
    {
        return (point.x >= 0 && point.x < this->rows &&
                point.y >= 0 && point.y < this->cols &&
                grid[point.x][point.y] == 0);
    }

    // Getters and setters
    const std::vector<std::vector<int>>& getGrid() const { return grid; }

    int getRows() const { return this->rows; }
    int getCols() const { return this->cols; }
    
    Point getStart() const { return this->start; }
    void setStart(const Point& point) { this->start = point; }

    Point getEnd() const { return this->end; }
    void setEnd(const Point& point) { this->end = point; }

    // Return if the position was visited or not
    bool getVisitedPoint(const Point& point) const
    {
        return this->visited[point.x][point.y];
    }

    // Set a visited position
    void setVisitedPoint(const Point& point) 
    {
        this->visited[point.x][point.y] = true;
    }

    // Overload the [] operator to access a grid position using a Point
    int& operator[](const Point& point)
    {
        return this->grid[point.x][point.y];
    }

    // Print the maze grid, using '.' for open spaces, '#' for walls, and '+' for paths
    void print() const
    {
        for (const std::vector<int>& row : grid)
        {
            for (int cell : row)
            {
                if (cell == 0) std::cout << " . ";        // Open space
                else if (cell == 1) std::cout << " # ";   // Wall
                else std::cout << " + ";                  // Path
            }
            std::cout << std::endl;
        }
    }
};

#endif
