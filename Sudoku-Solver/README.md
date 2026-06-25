# Sudoku Solver

## Overview
Solves any 9x9 Sudoku puzzle using Backtracking algorithm

## Features
- Two input methods: Manual or File input
- Validates rows, columns, and 3x3 boxes
- Tracks recursive backtracking count
- Clean grid display

## How to Run
g++ sudoku.cpp -o sudoku
./sudoku

## Input File Format (puzzle.txt)
Use 0 for empty cells
Values separated by spaces

## Algorithm
- Backtracking — tries 1-9 in each empty cell
- Time Complexity: O(9^m) where m = empty cells

## Test Cases
4 sample Sudoku puzzles included with solutions
for verification and testing purposes

## Acknowledgements
Modified and enhanced for educational purposes