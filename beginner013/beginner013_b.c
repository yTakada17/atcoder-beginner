#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int
main ()
{
  int a, b;
  int ans1, ans2;

  scanf ("%d", &a);
  scanf ("%d", &b);
  ans1 = abs(a - b);
  ans2 = 10 - ans1;
  if (ans1 < ans2)
    {
      printf ("%d\n", ans1);
    }
  else
    {
      printf ("%d", ans2);
    }
  return 0;
}
