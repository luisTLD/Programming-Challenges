# Maze Solver with BFS

## Overview

This project is a maze solver that uses the Breadth-First Search (BFS) algorithm to find the shortest path from the start point to the end point in a maze represented by a grid. The program can read a maze from a text file or be entered line by line via the console. After solving the maze, it saves the solved maze to a new text file.

**Note:** The code does not perform input validation or error checking. It assumes that the input files are correctly formatted.

# Important Note

This code **does not handle any input validation**. Any invalid numbers or out-of-range values will result in an incorrect and disproportionate solution. It is crucial that the input files or console inputs are correctly formatted and within the valid range.

## Features

- **Maze Loading:** Load a maze from a text file located in the `Mazes` folder.
- **Maze Solving:** Uses BFS to find the shortest path in the maze where `0` represents open paths and `1` represents walls.
- **Solution Saving:** Saves the solved maze to a text file in the `Solutions` folder with the path marked.

## File Format

**Input File (located in `Mazes` folder):**

The input file must have the following format:

1. **First Line:** Dimensions of the maze, formatted as `N M`, where `N` is the number of rows and `M` is the number of columns.
2. **Next N Lines:** The maze grid with `0` representing paths and `1` representing walls.
3. **Penultimate Line:** The starting point of the maze in the format `x1 y1`.
4. **Last Line:** The ending point of the maze in the format `x2 y2`.

## Examples

There are 6 example mazes in the `Mazes` folder and their respective solutions in the `Solutions` folder. You can use these examples to test the maze solver.

## Final Thoughts

This was my first project aimed at practicing graph algorithms, specifically BFS. I plan to improve the project further and add Depth-First Search (DFS) functionality as well in the future.

