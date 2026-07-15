#ifndef SOLVER_H
#define SOLVER_H
 
#include "sudokuGrid.h"
 

class Solver {
public:
    static bool solveSudoku(SudokuGrid& grid);
 
private:
    static bool checkRow(int row, int col, SudokuGrid& grid, int d);
    static bool checkCol(int row, int col, SudokuGrid& grid, int d);
    static bool checkBox(int row, int col, SudokuGrid& grid, int d);
    static bool isValid(int row, int col, SudokuGrid& grid, int d);
    static bool solve(SudokuGrid& grid, int row, int col);
};
 
#endif