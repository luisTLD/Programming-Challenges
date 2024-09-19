# Maze Solver with BFS

## Overview

This is a maze solver that allows the user to choose between Breadth-First Search (BFS) and Depth-First Search (DFS) to solve a grid-based maze. BFS is used to find the shortest path, while DFS explores the maze in depth-first order.
- Display the solution path using `+` in the maze grid.

- ## Compilation

To compile the project, use the following command:
- g++ -IInterfaces -o main main.cpp Utils/Point.cpp Utils/Maze.cpp Utils/MazeSolver.cpp Utils/MazeFileHandler.cpp
 
### Explanation

- `-IInterfaces`: Specifies the directory for header files. This is necessary for locating the headers included in the `Utils` source files.
- `-o main`: Sets the name of the output executable.
- `main.cpp Utils/Point.cpp Utils/Maze.cpp Utils/MazeSolver.cpp Utils/MazeFileHandler.cpp`: Lists the source files to compile and link.

# Important Note  

**Note:** The code does not perform input validation or error checking. It assumes that the input files are correctly formatted.

In this exercise, I aim to enhance good practices for code readability and organization. The code in the header files (`Interfaces`) includes detailed comments to explain the functions and their usage. This approach helps maintain clarity and ease of understanding throughout the project.

## Features

- **Maze Loading:** Load a maze from a text file located in the `Mazes` folder.
- **Maze Solving:** Uses BFS to find the shortest path in the maze where `0` represents open paths and `1` represents walls.
- **Solution Saving:** Saves the solved maze to a text file in the `Solutions` folder with the path marked.  
  
- **Breadth-First Search (BFS)**: Finds the shortest path from the start to the end of the maze.
- **Depth-First Search (DFS)**: Explores all possible paths to find a solution, though it may not always find the shortest path.
- **User Choice**: At runtime, the user can select whether to solve the maze using BFS or DFS.

## File Format

**Input File (located in `Mazes` folder):**

The input file must be located in the `Mazes` folder. When specifying the file, only include the name of the file without `../` or `.txt`. The code will automatically handle the file extension and path.

The input file must have the following format:

1. **First Line:** Dimensions of the maze, formatted as `N M`, where `N` is the number of rows and `M` is the number of columns.
2. **Next N Lines:** The maze grid with `0` representing paths and `1` representing walls.
3. **Penultimate Line:** The starting point of the maze in the format `x1 y1`.
4. **Last Line:** The ending point of the maze in the format `x2 y2`.

## Examples

There are 6 example mazes in the `Mazes` folder and their respective solutions in the `Solutions` folder. You can use these examples to test the maze solver.

## Final Thoughts

This was my first project aimed at practicing graph algorithms, specifically BFS. I plan to improve the project further and add Depth-First Search (DFS) functionality as well in the future.

