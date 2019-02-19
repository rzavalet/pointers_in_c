#include <stdio.h>

int main()
{
  char arr[] = "Pickpocketing my peace of mind";
  int i;

  printf("%c\n", *arr);

  /* arr is not an LValue. 
   * arr points to the beginning of the string. According 
   * to Yashavant, the compiler gives arr a "favored" status
   * of a constant, hence it cannot be incremented */
  arr++;
  printf("%c\n", *arr);

  return 0;
}

