#include "InputHandler.h"
#include<iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
void InputHandler::readFromConsole(SudokuGrid& grid){
    cout << endl << "enter the spcific values when prompted" << endl;
    cout << "enter 0 if cell is empty" << endl << endl;

    for(int row = 0; row < 9; row++){
        for(int col = 0; col < 9; col++){
            int value;
            cout << "enter the value of grid[" << row + 1 << "][" << col + 1 << "]\n\n";
            cin >> value;

            while(!(value >= 0 && value<9)){                 
                    cout << "\n seems you have entered wrong value of grid["<<row+1<<"]["<<col+1<<"]\n";
                    cout << "enter the correct value\n";
                    cin >> value;               
            }

            grid.grid[row][col] = value;
        }
    }

    cout << endl << endl;



}

void InputHandler::readFromFile(SudokuGrid& grid){
    char filename[30];
    cout << "\nEnter the name of the file that contains the Sudoku Puzzle.\n";
    cout << "\t   --> ";
    cin >> filename;
 
    ifstream input_file;
    input_file.open(filename, ios::in);
 
    if (!input_file.is_open()) {
        cout << "\nCould not open file '" << filename << "'. Check the path and try again.\n";
        exit(EXIT_FAILURE);
    }
 
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            int value;
            input_file >> value;
 
            if (!(value >= 0 && value <= 9)) {
                cout << "\nValue " << ((row * 9) + col + 1) << " in " << filename;
                cout << " seems to be wrong! Correct the value and try again!\n";
                exit(EXIT_FAILURE);
            }
 
            grid.grid[row][col] = value;
 
            if (input_file.eof()) break;
        }
    }
 
    input_file.close();
    cout << endl;
}