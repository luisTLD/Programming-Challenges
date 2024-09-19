#ifndef POINT_H
#define POINT_H

#include <vector>
#include <functional>

class Point
{
public:
    int x;
    int y;

    // Constructors: one with parameters and one default constructor
    Point(int x, int y) : x(x), y(y) {}
    Point() : x(0), y(0) {}

    // Overloading the == operator to compare two points
    bool operator==(const Point& point) const
    {
        return (this->x == point.x && this->y == point.y);
    }

    // Return a vector containing the four neighboring points (up, down, left, right)
    std::vector<Point> getNeighbors() const
    {
        std::vector<Point> neighbors = {Point(x + 1, y), Point(x - 1, y), Point(x, y + 1), Point(x, y - 1)};
        return neighbors;
    }
    
};

// Custom hash function for Point to enable its use in unordered data structures (like unordered_map)
namespace std
{
    template <>
    struct hash<Point>
    {
        // Hash function combining the hash values of x and y using XOR
        size_t operator()(const Point& point) const
        {
            return hash<int>()(point.x) ^ hash<int>()(point.y);
        }
    };
}

#endif
