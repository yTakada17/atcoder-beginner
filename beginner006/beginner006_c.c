#include <stdio.h>

int
main (void)
{
  int number, sum;
  scanf ("%d %d", &number, &sum);

  int adult, old, baby;
  if (sum % 2)
    {
      old = 1;
    }
  else
    {
      old = 0;
    }
  baby = (sum - 2 * (number - old) - old * 3) / 2;
  adult = number - old - baby;

  if (adult >= 0 && baby >= 0 && 2 * adult + 3 * old + 4 * baby == sum)
    {
      printf ("%d %d %d\n", adult, old, baby);
    }
  else
    {
      printf ("-1 -1 -1\n");
    }
  return 0;
}
