#include "../Interfaces/Point.hpp"

// Overloads the == operator to compare two points for equality
bool Point::operator==(const Point& point) const
{
    return (this->x == point.x && this->y == point.y);
}

// Returns a vector containing the four neighboring points (up, down, left, right)
std::vector<Point> Point::getNeighbors() const
{
    std::vector<Point> neighbors = {Point(x + 1, y), Point(x - 1, y), Point(x, y + 1), Point(x, y - 1)};
    return neighbors;
}

// Hash function combining the hash values of x and y using XOR
size_t std::hash<Point>::operator()(const Point& point) const
{
    return hash<int>()(point.x) ^ hash<int>()(point.y);
}
