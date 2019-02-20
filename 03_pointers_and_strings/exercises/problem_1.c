#include <stdio.h>

/*------------------------------------------------------------------------------
 * Scan a string from beginning to end in search of a character. 
 *
 * If the character is found it should return a pointer to the first occurrence
 * of the given character in the string. 
 *
 * If the given character is not found in the string, the function should return 
 * NULL
 *----------------------------------------------------------------------------*/
char *xstrchr(char *string, char ch)
{
  char *p;

  for (p = string; *p && *p != ch; p++); 

  return *p ? p : NULL;
}

int main()
{

  char *my_string = "This is a random string";
  char *p;
  int   c;
   
  c = getchar();

  p = xstrchr(my_string, c);

  printf("%s\n", p ? p : "<NULL>");

  return 0;
}
