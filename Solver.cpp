#include "Solver.h"
 
bool Solver::checkRow(int row, int col, SudokuGrid& grid, int d) {
    for (int j = 0; j < 9; j++) {
        if (grid.grid[row][j] == d) return false;
    }
    return true;
}
 
bool Solver::checkCol(int row, int col, SudokuGrid& grid, int d) {
    for (int i = 0; i < 9; i++) {
        if (grid.grid[i][col] == d) return false;
    }
    return true;
}
 
bool Solver::checkBox(int row, int col, SudokuGrid& grid, int d) {
    int start_i = (row / 3) * 3;
    int start_j = (col / 3) * 3;
 
    for (int i = start_i; i < start_i + 3; i++) {
        for (int j = start_j; j < start_j + 3; j++) {
            if (grid.grid[i][j] == d) return false;
        }
    }
    return true;
}
 
bool Solver::isValid(int row, int col, SudokuGrid& grid, int d) {
    return checkRow(row, col, grid, d)
        && checkCol(row, col, grid, d)
        && checkBox(row, col, grid, d);
}
 
bool Solver::solve(SudokuGrid& grid, int row, int col) {
    if (row == 9) return true;
 
    int nr = (col == 8) ? row + 1 : row;
    int nc = (col == 8) ? 0 : col + 1;
 
    if (grid.grid[row][col] != 0) {
        return solve(grid, nr, nc);
    }
 
    for (int d = 1; d <= 9; d++) {
        if (isValid(row, col, grid, d)) {
            grid.grid[row][col] = d;
            if (solve(grid, nr, nc)) return true;
            grid.grid[row][col] = 0;
        }
    }
 
    return false;
}
 
bool Solver::solveSudoku(SudokuGrid& grid) {
    return solve(grid, 0, 0);
}
 
