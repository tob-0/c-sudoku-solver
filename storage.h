#ifndef STORAGE_H
#define STORAGE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct OttoDbEntry
{
  unsigned long hash;
  char solved[82];
};

struct OttoDb
{
  unsigned long count;
  struct OttoDbEntry *entries;
};

void storage_init();
void storage_free();
void save_result(int *grid, unsigned long hash);
int get_solved_for_hash(unsigned long hash, char *buffer);
#endif