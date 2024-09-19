#include "../Interfaces/MazeSolver.hpp"

// Constructor to initialize the MazeSolver with a Maze
MazeSolver::MazeSolver(const Maze& maze) : maze(maze) {}

// Solves the maze using Depth-First Search (DFS) algorithm.
bool MazeSolver::solveMazeDFS()
{
    // Get the starting point of the maze.
    Point start = this->maze.getStart();

    // Begin the recursive DFS search from the starting point.
    bool found = solveMazeDFSRec(start);
    
    // If a solution is found, print the maze and prompt the user to save it.
    if (found)
    {
        this->maze.print();
        char choice;
        std::cout << "Do you want to save the solution in a file? (y/n): ";
        std::cin >> choice;

        if (choice == 'y' || choice == 'Y') MazeFileHandler::saveSolutionToFile(this->maze);
    }

    return found;
}

// Recursive function for DFS that explores all valid neighboring points of the current position.
bool MazeSolver::solveMazeDFSRec(Point& current)
{
    bool found = false;

    if (current == this->maze.getEnd()) 
    {
        return true;
    }

    // Get all valid neighboring points to explore from the current position.
    std::vector<Point> to_explore = getValidNeighbors(current);

    for (Point& test : to_explore)
    {
        markVisited(test);
        this->maze[test] = 2; 

        if (solveMazeDFSRec(test))
        {
            found = true;
            break; 
        }

        this->maze[test] = 0;
    }

    return found;
}

// Solves the maze using Breadth-First Search (BFS)
bool MazeSolver::solveMazeBFS()
{
    bool found = false; // Indicates whether a solution was found

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

    // Option to save the solution
    if (found)
    {
        char choice;
        std::cout << "Do you want to save the solution in a file? (y/n): ";
        std::cin >> choice;
        if (choice == 'y' || choice == 'Y') MazeFileHandler::saveSolutionToFile(this->maze);
    }
    
    return found;
}

// Returns valid neighbors of a given position (within bounds and not walls)
std::vector<Point> MazeSolver::getValidNeighbors(const Point& position) const
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

// Checks if a position has been visited
bool MazeSolver::isVisited(const Point& position) const
{
    return this->maze.getVisitedPoint(position);
}

// Marks a position as visited
void MazeSolver::markVisited(const Point& position) 
{
    this->maze.setVisitedPoint(position);
}

// Adds neighbors to the exploration queue and updates the solution map
void MazeSolver::addToExplore(const std::vector<Point>& neighbors, std::queue<Point>& to_explore, std::unordered_map<Point, Point>& solution_map)
{
    for (const Point& neighbor : neighbors)
    {
        to_explore.push(neighbor);
        solution_map[neighbor] = to_explore.front(); // Updates the map to reconstruct the path
    }
}
