#include "main.h"

int myStrlen(char *str)
{
  int len;
  
  for (len = 0 ; *(str + len) != '\0' ; len++);
  
  return len;
}