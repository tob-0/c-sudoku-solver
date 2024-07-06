#include "utils.h"

int str_is_num_only(char *s)
{
  while (*s++)
    if (*s < '0' || *s > '9')
      return 1;
  return 0;
}