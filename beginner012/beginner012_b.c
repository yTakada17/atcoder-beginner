#include<stdio.h>

int
main ()
{
  int n = 0;
  scanf ("%d", &n);
  printf ("%02d:%02d:%02d\n", n / 3600, n / 60 % 60, n % 60);

  return 0;
}
