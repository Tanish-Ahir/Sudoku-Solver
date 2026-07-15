#include "sudokuGrid.h"

SudokuGrid::SudokuGrid(){
    for(int i = 0;i<9;i++){
        for(int j = 0;j<9;j++){
            grid[i][j] = 0;
        }
    }
}