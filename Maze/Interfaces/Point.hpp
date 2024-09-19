#ifndef POINT_H
#define POINT_H

#include <vector>
#include <functional>

class Point
{
public:
    int x; // X-coordinate of the point
    int y; // Y-coordinate of the point

    // Constructor with parameters to initialize the point
    Point(int x, int y) : x(x), y(y) {}

    // Default constructor initializing the point to (0, 0)
    Point() : x(0), y(0) {}

    // Overloads the == operator to compare two points for equality
    bool operator==(const Point& point) const;

    // Returns a vector containing the four neighboring points (up, down, left, right)
    std::vector<Point> getNeighbors() const;
};

// Custom hash function for Point to enable its use in unordered data structures (like unordered_map)
namespace std
{
    template <>
    struct hash<Point>
    {
        // Hash function combining the hash values of x and y using XOR
        size_t operator()(const Point& point) const;
    };
}

#endif
