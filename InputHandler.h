#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include "sudokuGrid.h"

class InputHandler{
public : 
    static void readFromConsole(SudokuGrid& grid);
    static void readFromFile(SudokuGrid& grid);
};



#endif