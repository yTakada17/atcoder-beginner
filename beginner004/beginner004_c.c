#include<stdio.h>
#define SIZE 6

int
main ()
{

  int ary[] = { 1, 2, 3, 4, 5, 6 };
  int n = 0;
  int i = 0, tmp = 0;
  scanf ("%d", &n);

  for (i = 0; i < n; i++)
    {
      tmp = ary[i % 5 + 1 - 1];
      ary[i % 5 + 1 - 1] = ary[i % 5 + 2 - 1];
      ary[i % 5 + 2 - 1] = tmp;
    }

  for (i = 0; i < SIZE - 1; i++)
    {
      printf ("%d", ary[i]);
    }
  printf ("%d\n", ary[i]);

  return 0;
}
