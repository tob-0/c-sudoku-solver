#include "sudoku.h"
#include "utils.h"
#include "storage.h"

int default_mode(int argc, char *argv[])
{
  unsigned char mode = 0;
  if (argc == 1)
  {
    printf("No argument provided, using the hardcoded demo grid.\n");
    int grid[] = {2, 5, 0, 0, 3, 0, 9, 0, 1, 0, 1, 0, 0, 0, 4, 0, 0, 0, 4, 0, 7, 0, 0, 0, 2, 0, 8, 0, 0, 5, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 8, 1, 0, 0, 0, 4, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 3, 6, 0, 0, 7, 2, 0, 7, 0, 0, 0, 0, 0, 0, 3, 9, 0, 3, 0, 0, 0, 6, 0, 4};
    int solution_found = sudoku(grid, 0, 0);
    if (solution_found)
      print_grid(grid);
    else
      printf("No solution found for this grid !\n");
    return solution_found;
  }

  if (str_is_num_only(argv[1]))
    mode = 1;

  switch (mode)
  {
  case 0:
    printf("Not implemented\n");
    break;
  case 1:
    return solve_from_direct_input(argv[1]);
  default:
    printf("Error during mode selection\n");
    return -1;
  }
  return -1;
}

int main(int argc, char *argv[])
{
  // storage_init();
  if (argc == 2 && argv[1])
  {
    solve_from_direct_input(argv[1]);
  }
  // storage_free();

  return 0;
}