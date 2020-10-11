#pragma once
#include <iostream>

namespace GAME {
    const int N = 9;
    const int Zero = 0;

    class Sudoku {
    private:
        int grid[N][N];
        bool findZeroInGrid(int &row, int &col);
        bool isValidDigit(const int row, const int col, const int digit);
        bool isDigitPresentedInRow(const int row, const int digit);
        bool isDigitPresentedInCol(const int col, const int digit);
        bool isDigitPresentedIn3X3Part(const int startRow, const int startCol,
                                       const int digit);
    public:
        Sudoku();
        void entryDigits();
        bool solve();
        void print();
  };
}
