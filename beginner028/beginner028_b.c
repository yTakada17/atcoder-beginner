#include <stdio.h>
#include <string.h>

int
main (void)
{
  char str[101];
  scanf ("%s", str);

  int i;
  int sum[6] = { 0 };
  for (i = 0; str[i] != '\0'; i++)
    {
      int k = str[i] - 'A';
      sum[k]++;
    }

  printf ("%d", sum[0]);
  for (i = 1; i < 5; i++)
    {
      printf (" %d", sum[i]);
    }
  printf (" %d\n", sum[5]);

  return 0;
}
