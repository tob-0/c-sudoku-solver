#include "sudoku.h"
#include "storage.h"
#include "hash.h"

int solve_for(int grid[SIZE * SIZE], int row, int col, int num)
{
  int s_row = row * SIZE;
  int d_row;
  for (int x = 0; x < SIZE; x++)
  {
    d_row = x * SIZE;
    if (grid[s_row + x] == num)
      return 0;
    if (grid[d_row + col] == num)
      return 0;
  }
  int start_row = row - row % CELL_SIZE;
  int start_col = col - col % CELL_SIZE;
  for (int i = 0; i < CELL_SIZE; i++)
    for (int j = 0; j < CELL_SIZE; j++)
    {
      d_row = (start_row + i) * SIZE;
      if (grid[d_row + (start_col + j)] == num)
        return 0;
    }
  return 1;
}

int sudoku(int grid[SIZE * SIZE], int row, int col)
{
  if (row == SIZE - 1 && col == SIZE)
    return 1;
  if (col == SIZE)
  {
    row++;
    col = 0;
  }
  if (grid[row * SIZE + col] > 0)
    return sudoku(grid, row, col + 1);
  for (int x = 0; x <= SIZE; x++)
  {
    if (solve_for(grid, row, col, x))
    {
      grid[row * SIZE + col] = x;
      if (sudoku(grid, row, col + 1))
        return 1;
    }
    grid[row * SIZE + col] = 0;
  }
  return 0;
}

int solve_from_direct_input(char *s_input)
{
  int grid_buffer[SIZE * SIZE];
  int solution_found = 0;
  unsigned long hash = hash_djb2((unsigned char *)s_input);
  // char *from_db = malloc(82 * sizeof(char));
  // if (get_solved_for_hash(hash, from_db))
  // {
  //   parse_grid_numbers_from_string(from_db, grid_buffer);
  //   solution_found = 2;
  // }
  if (solution_found == 0)
  {
    printf("Grid is not in DB, calculating.\n");
    parse_grid_numbers_from_string(s_input, grid_buffer);
    solution_found = sudoku(grid_buffer, 0, 0);
  }
  if (solution_found == 1)
  {
    save_result(grid_buffer, hash);
    print_grid(grid_buffer);
  }
  else if (solution_found == 2)
  {
    print_grid(grid_buffer);
  }
  else
    printf("No solution found for this grid !\n");
  return solution_found;
}

// Utility functions

void print_grid_as_string(int grid[])
{
  for (int y = 0; y < SIZE; y++)
  {
    for (int x = 0; x < SIZE; x++)
    {
      printf("%d", grid[y * SIZE + x]);
    }
  }
}

void parse_grid_numbers_from_string(char *s, int buffer[SIZE * SIZE])
{
  for (int i = 0; i < SIZE * SIZE; i++)
    buffer[i] = *s++ - 0x30;
}

void print_grid(int grid[])
{
  printf("+ - - - + - - - + - - - +\n");
  for (int y = 0; y < SIZE; y++)
  {
    for (int x = 0; x < SIZE; x++)
    {
      if (x == 0)
        printf("| ");
      printf("%d ", grid[y * SIZE + x]);
      if (x % 3 == 2 && x < SIZE)
        printf("| ");
    }
    printf("\n");
    if (y % 3 == 2)
      printf("+ - - - + - - - + - - - +\n");
  }
}