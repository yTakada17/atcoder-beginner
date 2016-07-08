#include <stdio.h>
#include <stdlib.h>
int
main (void)
{
  char a[100];
  int i;
  fgets (a, 100, stdin);
  i = atoi (a);
  if (i == 100)
    printf ("Perfect\n");
  else if (i > 89)
    printf ("Great\n");
  else if (i > 59)
    printf ("Good\n");
  else
    printf ("Bad\n");
  return 0;
}
