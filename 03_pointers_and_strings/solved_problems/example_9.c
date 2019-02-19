#include <stdio.h>

int main()
{
  /* str is an array of pointers to char. Each pointer has a size of 
   * 4 bytes (in a 32 bits system). Since the array has 6 elements,
   * sizeof(str) = 6 * 4 = 24.
   *
   * sizeof(str[0]) is the size of a char *, which is 4 bytes. */
  char *str[] = {"Frogs", "Do", "Not", "Die", "They", "Croak"};

  printf("%d %d\n", sizeof(str), sizeof(str[0]));

  return 0;
}
