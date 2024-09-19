#ifndef MAZE_HPP
#define MAZE_HPP

#include <vector>

#include "Point.hpp"

class Maze
{
private:
    std::vector<std::vector<int>> grid;         // 2D grid representing the maze (0 = open path, 1 = wall)
    std::vector<std::vector<bool>> visited;     // Matrix to track visited cells
    Point start;                                // Starting point of the maze
    Point end;                                  // Ending point of the maze
    int rows, cols;                             // Number of rows and columns in the maze

public:
    // Constructor to initialize the maze with a grid, start and end points, and its dimensions
    Maze(const std::vector<std::vector<int>>& input_grid, Point start, Point end, int rows, int cols);

    // Default constructor that initializes an empty maze
    Maze();

    // Checks if the point is within the bounds of the maze and is not a wall
    bool isValid(const Point& point) const;

    // Returns the grid of the maze
    const std::vector<std::vector<int>>& getGrid() const;

    // Returns the number of rows in the maze
    int getRows() const;

    // Returns the number of columns in the maze
    int getCols() const;
    
    // Returns the starting point of the maze
    Point getStart() const;

    // Sets the starting point of the maze
    void setStart(const Point& point);

    // Returns the ending point of the maze
    Point getEnd() const;

    // Sets the ending point of the maze
    void setEnd(const Point& point);

    // Returns whether the cell at the specified point has been visited or not
    bool getVisitedPoint(const Point& point) const;

    // Marks a cell as visited at the specified point
    void setVisitedPoint(const Point& point);

    // Overloads the [] operator to access a grid position using a point
    int& operator[](const Point& point);

    // Prints the maze: '.' for open spaces, '#' for walls, and '+' for paths
    void print() const;
};

#endif
