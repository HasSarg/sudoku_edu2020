#pragma once
#include <iostream>

namespace GAME {
    const int N = 9;
    const int Zero = 0;

    class Sudoku {
    private:
        int grid[N][N];
        bool findZeroInGrid(int &row, int &col);
        bool isValidDigit(int row, int col, int digit);
        bool isDigitPresentedInRow(int row, int digit);
        bool isDigitPresentedInCol(int col, int digit);
        bool isDigitPresentedIn3X3Part(int startRow, int startCol,
                                       int digit);
    public:
        Sudoku();
        void entryDigits();
        bool solve();
        void print();
  };
}
