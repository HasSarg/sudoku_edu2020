#include "sudoku.h"

int main()
{
    GAME::Sudoku sudoku;
    sudoku.entryDigits();
    if (sudoku.solve()) {
        std::cout << "\nSolution see below: \n";
        sudoku.print();
    } else {
        std::cout << "\nInsoluble.\n";
    }
    return 0;
}
