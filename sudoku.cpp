#include "sudoku.h"

namespace GAME
{

    Sudoku::Sudoku()
    {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                grid[i][j] = 0;
            }
        }
    }

    void Sudoku::entryDigits()
    {
        int digit;
        std::cout << "Please enter numbers for 9x9 matrix in range [0, 9].\n"
                  << "Out of range number will be changed to '0'.\n";
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                std::cin >> digit;
                if (digit < 0 || digit > 9) {
                    digit = 0;;
                }
                grid[i][j] = digit;
            }
        }
    }

    bool Sudoku::solve()
    {
        int row, col;
        if (!findZeroInGrid(row, col)) {
            return true;
        }
        for (int digit = 1; digit <= 9; digit++) {
            if (isValidDigit(row, col, digit)) {
                grid[row][col] = digit;
                if (solve()) {
                    return true;
                }
                grid[row][col] = Zero;
            }
        }
        return false;
    }

    bool Sudoku::findZeroInGrid(int &row, int &col)
    {
        for (row = 0; row < N; ++row) {
            for (col = 0; col < N; ++col) {
                if (grid[row][col] == Zero) {
                    return true;
                }
            }
        }
        return false;
    }

    bool Sudoku::isValidDigit(int row, int col, int digit)
    {
        return !isDigitPresentedInRow(row, digit) &&
               !isDigitPresentedInCol(col, digit) &&
               !isDigitPresentedIn3X3Part(row - row % 3 , col - col % 3, digit);
    }

    bool Sudoku::isDigitPresentedInRow(int row, int digit)
    {
        for (int col = 0; col < N; ++col) {
            if (grid[row][col] == digit) {
                return true;
            }
        }
        return false;
    }

    bool Sudoku::isDigitPresentedInCol(int col, int digit)
    {
        for (int row = 0; row < N; ++row) {
            if (grid[row][col] == digit) {
                return true;
            }
        }
        return false;
    }

    bool Sudoku::isDigitPresentedIn3X3Part(int startRow,
                                           int startCol,
                                           int digit)
    {
        for (int row = 0; row < 3; ++row) {
            for (int col = 0; col < 3; ++col) {
                if (grid[startRow + row][startCol + col] == digit) {
                    return true;
                }
            }
        }
        return false;
    }

    void Sudoku::print()
    {
        for (int row = 0; row < N; ++row) {
            for (int col = 0; col < N; col++) {
                std::cout << grid[row][col] << " ";
            }
            std::cout << std::endl;
        }
    }
}
