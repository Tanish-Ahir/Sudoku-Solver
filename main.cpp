#include <iostream>
#include <limits>  
#include "sudokuGrid.h"
#include "InputHandler.h"
#include "Display.h"
#include "Solver.h"
using namespace std;

int main() {
    cout << "\n======================\n";
    cout << "    Sudoku Solver\n";
    cout << "======================\n\n";

    cout << "Welcome! How would you like to input the puzzle?\n";
    cout << "\t1. Enter values manually\n";
    cout << "\t2. Read from a file (81 space-separated values, 0 = blank)\n";
    cout << "\t   --> ";

    int option;
    cin >> option;
    while (cin.fail() || (option != 1 && option != 2)) {
        cin.clear();                                              // fail state clear karo
        cin.ignore(numeric_limits<streamsize>::max(), '\n');       // buffer se galat input fek do
        cout << "\nInvalid option. Try again.\n\t   --> ";
        cin >> option;
    }

    while (option != 1 && option != 2) {
        cout << "\nInvalid option. Try again.\n\t   --> ";
        cin >> option;
    }

    SudokuGrid grid;

    if (option == 1) {
        InputHandler::readFromConsole(grid);
    } else {
        InputHandler::readFromFile(grid);
    }

    cout << "\nYour puzzle:\n";
    Display::showGrid(grid);

    cout << "\n\nSolving...\n";
    bool solved = Solver::solveSudoku(grid);

    cout << "\n\nResult:\n";
    Display::showGrid(grid);

    if (solved) {
        cout << "\n\nSolved successfully!\n\n";
    } else {
        cout << "\n\nNo solution exists for this puzzle.\n\n";
    }

    return 0;
}