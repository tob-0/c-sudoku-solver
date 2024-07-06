#include "storage.h"
#include "hash.h"

static FILE *fptr;
static const char db_file_path[] = "./solver.otto-db";
static struct OttoDb core;

void storage_init()
{
  if ((fptr = fopen(db_file_path, "rb")) == NULL)
  {
    // Create file if it does not exist
    printf("creating db file");
    fptr = fopen(db_file_path, "wb+");
  }

  fread(&(core.count), 8, 1, fptr);
  if (core.count > 0)
  {
    struct OttoDbEntry entry;
    core.entries = malloc(sizeof(struct OttoDbEntry) * core.count);
    for (unsigned long i = 0; i < core.count; i++)
    {
      fread(&(entry.hash), sizeof(unsigned long), 1, fptr);
      fread(&(entry.solved), sizeof(char) * 81, 1, fptr);
      entry.solved[81] = 0;
      core.entries[i] = entry;
    }
  }
  fclose(fptr);
}

void storage_free()
{
  free(core.entries);
}

void string_from_int_grid(int grid[81], char *buffer)
{
  for (int i = 0; i < 81; i++)
    *buffer++ = grid[i] + 0x30;
  *buffer++ = 0;
}

void save_result(int *grid, unsigned long hash)
{

  core.count++;

  fptr = fopen(db_file_path, "wb");
  fseek(fptr, 0, SEEK_SET);
  fwrite(&(core.count), sizeof(unsigned long), 1, fptr);
  fclose(fptr);

  fptr = fopen(db_file_path, "ab+");
  char *solved_grid_string = malloc(sizeof(char) * 82);
  string_from_int_grid(grid, solved_grid_string);

  struct OttoDbEntry new_entry;
  new_entry.hash = hash;
  strcpy(new_entry.solved, solved_grid_string);

  fwrite(&(new_entry.hash), sizeof(unsigned long), 1, fptr);
  fwrite(&(new_entry.solved), 81 * sizeof(char), 1, fptr);

  if ((core.entries = realloc(core.entries, sizeof(struct OttoDbEntry) * core.count)) == NULL)
  {
    exit(EXIT_FAILURE);
  }
  core.entries[core.count - 1] = new_entry;
  free(solved_grid_string);
  fclose(fptr);
}

int get_solved_for_hash(unsigned long hash, char *buffer)
{
  for (size_t i = 0; i < core.count; i++)
  {
    if (core.entries[i].hash == hash)
    {
      strcpy(buffer, core.entries[i].solved);
      return 1;
    }
  }
  return 0;
}