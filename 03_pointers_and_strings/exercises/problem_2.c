#include <stdio.h>
#include <stdlib.h>

/*------------------------------------------------------------------------------
 * Scan a string for the occurrence of a given substring.
 *
 * The function should return a pointer to the element in string1 where string2
 * begins
 *
 * If string2 doesn't occur in string1 then xstrstr() should return NULL
 *----------------------------------------------------------------------------*/
char *xstrstr(char *string1, char *string2)
{
  int max;
  int i, j;
  size_t len1, len2;
  char *tmp;
  char **dp;

  for(tmp = string1, len1 = 0; tmp && *tmp; tmp++, len1++);
  for(tmp = string2, len2 = 0; tmp && *tmp; tmp++, len2++);

  /* I am using the dynamic programming approach */
  dp = calloc(sizeof (char *), len1);
  for (i = 0; i<len1; i++) {
    dp[i] = calloc(sizeof(char), len2);
  }

  for (i = 0; i < len1; i++) {
    for (j = 0; j < len2; j++) {
      if (string1[i] == string2[j]) {
        if (i > 0 && j > 0) {
          dp[i][j] = dp[i-1][j-1] + 1;
        }
        else {
          dp[i][j] = 1;
        }
      }
      else {
          dp[i][j] = 0;
      }
    }
  }

 
  tmp = NULL;
  max = 0;
  for (i = 0; i < len1; i++) {
    for (j = 0; j < len2; j++) {
      if (dp[i][j] > max) {
        max = dp[i][j];
        tmp = string1 + i - max + 1;
      }
    }
  }

  for (i = 0; i<len1; i++) {
    free(dp[i]);
  }
  free(dp);

  return tmp;
}

int main()
{

  char *my_string = "This is a random string";
  char input_string[256];
  char *p;
  int   c;
   
  printf("Initial string:\n");
  printf("[%s]\n", my_string);

  scanf("%s", input_string);

  p = xstrstr(my_string, input_string);

  printf("%s\n", p ? p : "<NULL>");

  return 0;
}

