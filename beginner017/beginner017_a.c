#include<stdio.h>

int
main ()
{
  int s1 = 0, s2 = 0, s3 = 0;
  int e1 = 0, e2 = 0, e3 = 0;

  scanf ("%d %d", &s1, &e1);
  scanf ("%d %d", &s2, &e2);
  scanf ("%d %d", &s3, &e3);

  printf ("%d", s1 * e1 + s2 * e2 + s3 * e3);
  return 0;
}
