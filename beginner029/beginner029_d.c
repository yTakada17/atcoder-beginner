#include<stdio.h>

int
main (void)
{
  int N, i, j, c;
  int ten[20] = { };
  int t[20] = { };
  long long sum;
  int table[20] = { };
  scanf ("%d", &N);
  table[1] = 1;
  ten[1] = 1;
  for (i = 2; i <= 9; i++)
    ten[i] = 10 * ten[i - 1];
  for (i = 2; i <= 9; i++)
    table[i] = ten[i] + 10 * table[i - 1];

  i = 1;
  sum = 0;
  c = N;
  while (c > 0)
    {
      t[i] = c % 10;
      /* printf("t[i]:%d\n",t[i]); */
      if (i >= 2)
	sum += (t[i]) * table[i - 1];
      if (t[i] > 1)
	sum += ten[i];
      if (t[i] == 1)
	sum += (N % ten[i]) + 1;

      /* printf("%ld\n",sum); */
      i++;
      c = c / 10;
    }
  printf ("%ld\n", sum);
  return 0;
}
