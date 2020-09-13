#include "sudoku.h"

GAME::Sudoku::Sudoku()
{
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            grid[i][j] = 0;
        }
    }
}

void GAME::Sudoku::entryDigits()
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

bool GAME::Sudoku::solve()
{
    int row, col;
    if (!findZeroInGrid(row, col))
        return true;
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

bool GAME::Sudoku::findZeroInGrid(int &row, int &col)
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

bool GAME::Sudoku::isValidDigit(const int row, const int col, const int digit)
{
    return !isDigitPresentedInRow(row, digit) &&
           !isDigitPresentedInCol(col, digit) &&
           !isDigitPresentedIn3X3Part(row - row % 3 , col - col % 3, digit);
}

bool GAME::Sudoku::isDigitPresentedInRow(const int row, const int digit)
{
    for (int col = 0; col < N; ++col) {
        if (grid[row][col] == digit) {
            return true;
        }
    }
    return false;
}

bool GAME::Sudoku::isDigitPresentedInCol(const int col, const int digit)
{
    for (int row = 0; row < N; ++row) {
        if (grid[row][col] == digit) {
            return true;
        }
    }
    return false;
}

bool GAME::Sudoku::isDigitPresentedIn3X3Part(const int startRow,
                                             const int startCol,
                                             const int digit)
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

void GAME::Sudoku::print()
{
    for (int row = 0; row < N; ++row) {
        for (int col = 0; col < N; col++) {
            std::cout << grid[row][col] << " ";
        }
        std::cout << std::endl;
    }
}
