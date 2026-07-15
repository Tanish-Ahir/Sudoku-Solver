#include "Display.h"
#include <iostream>
using namespace std;
 
void Display::showGrid(const SudokuGrid& grid) {
    cout << "++=====================================++";
 
    for (int row = 0; row < 9; row++) {
        int cellIter = 1;
        cout << "\n||";
 
        for (int col = 0; col < 9; col++) {
            int value = grid.grid[row][col];
 
            if (cellIter == 3) {
                cout << " ";
                if (value != 0) cout << value << " ";
                else cout << "  ";
                cout << "||";
                cellIter = 1;
            } else {
                cout << " ";
                if (value != 0) cout << value << "  ";
                else cout << "   ";
                cellIter++;
            }
        }
 
        if (row % 3 != 2) cout << "\n++-----------++-----------++-----------++";
        else cout << "\n++=====================================++";
    }
 
    cout << " ";
}
 
