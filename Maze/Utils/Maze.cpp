#include "../Interfaces/Maze.hpp"

#include <iostream>

Maze::Maze(const std::vector<std::vector<int>>& input_grid, Point start, Point end, int rows, int cols)
    : grid(input_grid), start(start), end(end), rows(rows), cols(cols),
    visited(rows, std::vector<bool>(cols, false)) {}

Maze::Maze() : rows(0), cols(0), start(0, 0), end(0, 0),
        grid(std::vector<std::vector<int>>()), 
        visited(std::vector<std::vector<bool>>()) {}

bool Maze::isValid(const Point& point) const
{
    return (point.x >= 0 && point.x < this->rows &&
            point.y >= 0 && point.y < this->cols &&
            grid[point.x][point.y] == 0);
}

const std::vector<std::vector<int>>& Maze::getGrid() const { return grid; }

int Maze::getRows() const { return this->rows; }
int Maze::getCols() const { return this->cols; }

Point Maze::getStart() const { return this->start; }
void Maze::setStart(const Point& point) { this->start = point; }

Point Maze::getEnd() const { return this->end; }
void Maze::setEnd(const Point& point) { this->end = point; }

bool Maze::getVisitedPoint(const Point& point) const
{
    return this->visited[point.x][point.y];
}

void Maze::setVisitedPoint(const Point& point)
{
    this->visited[point.x][point.y] = true;
}

int& Maze::operator[](const Point& point)
{
    return this->grid[point.x][point.y];
}

void Maze::print() const
{
    for (const std::vector<int>& row : grid)
    {
        for (int cell : row)
        {
            if (cell == 0) std::cout << " . ";
            else if (cell == 1) std::cout << " # ";
            else std::cout << " + ";
        }
        std::cout << std::endl;
    }
}
