#ifndef SUDOKU_H
#define SUDOKU_H
#define CELL_SIZE 3
#define SIZE (CELL_SIZE * CELL_SIZE)

#include <stdio.h>

/// @brief Search function to check if a number is allowed at a specific spot in the grid.
/// @param grid Grid to search in.
/// @param row Row of the position to check.
/// @param col Column of the position to check.
/// @param num Number to check at the specified position.
/// @return 1 if the number could be placed, 0 otherwise.
int solve_for(int grid[SIZE * SIZE], int row, int col, int num);

/// @brief Main sudoku solving recursive function.
/// @param grid Grid to solve, as an array of integer.
/// @param row Row of the grid from where to start solving the sudoku.
/// @param col Column of the grid from where to start solving the sudoku.
/// @return 1 if the grid could be solved, 0 otherwise.
int sudoku(int grid[SIZE * SIZE], int row, int col);

/// @brief Try to solve the provided sudoku, represented as a string of numbers without separators between the numbers
/// @param s_input The string representation of the grid.
/// @return 1 if the grid could be solved, 0 otherwise.
int solve_from_direct_input(char *s_input);

/// @brief Pretty print the specified grid to the terminal.
/// @param grid Grid to print.
void print_grid(int grid[]);

/// @brief Print the specified grid as a string of numbers, without separators between the numbers.
/// @param grid Grid to print.
void print_grid_as_string(int grid[]);

/// @brief Parse a string (char *) to an integer array.
/// @param s The string representation of the grid.
/// @param buffer The buffer to put the parsed numbers in.
void parse_grid_numbers_from_string(char *s, int buffer[SIZE * SIZE]);

#endif