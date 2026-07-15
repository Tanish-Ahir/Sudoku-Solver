

Readme · MD
Sudoku Solver
A C++ command-line application that reads a 9x9 Sudoku puzzle (via console or file input) and solves it using a recursive backtracking algorithm.

Features
Two ways to input a puzzle: type values manually, or load them from a text file
Formatted console display of the puzzle grid before and after solving
Recursive backtracking solver with row / column / 3x3-box validation
Clean separation of concerns across modules (input, display, solving logic, and orchestration)
Project Structure
Sudoku_Solver/
├── sudokuGrid.h        # Grid data structure (9x9 array)
├── sudokuGrid.cpp
├── InputHandler.h       # Reads puzzle values from console or file
├── InputHandler.cpp
├── Display.h            # Renders the grid to the console
├── Display.cpp
├── Solver.h              # Backtracking algorithm that solves the puzzle
├── Solver.cpp
├── main.cpp              # Entry point — wires everything together
├── Makefile
└── README.md
Each module has a single responsibility:

Module	Responsibility
SudokuGrid	Stores the puzzle's 81 cell values
InputHandler	Populates a SudokuGrid from console or file input
Display	Prints a SudokuGrid to the console in a readable grid format
Solver	Solves a SudokuGrid in place using backtracking
main	Runs the menu and coordinates input → display → solve → display
Building and Running
Using the Makefile
bash
make
./sudoku
Manually with g++
bash
g++ main.cpp sudokuGrid.cpp InputHandler.cpp Display.cpp Solver.cpp -o sudoku
./sudoku
Input Format
Console input: you'll be prompted to enter each of the 81 cell values one at a time (0 for an empty cell).

File input: create a plain text file with 81 space-separated values (row by row, 0 for empty cells), for example:

5 3 0 0 7 0 0 0 0
6 0 0 1 9 5 0 0 0
0 9 8 0 0 0 0 6 0
8 0 0 0 6 0 0 0 3
4 0 0 8 0 3 0 0 1
7 0 0 0 2 0 0 0 6
0 6 0 0 0 0 2 8 0
0 0 0 4 1 9 0 0 5
0 0 0 0 8 0 0 7 9
When prompted, enter the filename (the file must be in the same directory as the executable).

Algorithm
The solver uses recursive backtracking:

Walk through the grid cell by cell (left to right, top to bottom).
If a cell is already filled, move to the next cell.
If a cell is empty, try digits 1–9. For each digit, check that it doesn't already appear in the same row, column, or 3x3 box.
If a digit is valid, place it and recurse into the next cell.
If the recursive call fails (no digit works further down the line), undo the placement (reset to 0) and try the next digit — this is the "backtrack" step.
If every cell from position (0,0) through (8,8) is successfully filled, the puzzle is solved.
Notes
This project was refactored from a single-file implementation into separate modules to reflect a cleaner, more maintainable structure, and the solving algorithm was rewritten independently.

