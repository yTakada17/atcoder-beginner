#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
main ()
{
  int i, n, a;
  long int b[100002], c[100002] = { };
  char str[100002];

  scanf ("%d %d", &n, &a);
  scanf ("%s", &str);
  for (i = 1; i <= n; i++)
    scanf ("%ld", &b[i]);

  if (strlen (str) < 6)
    {
      for (i = 0; i < atoi (str); i++)
	a = b[a];
      printf ("%d\n", a);
      return 0;
    }

  long long int pos = a, cnt = 1;
  while (c[pos] == 0)
    {
      c[pos] = cnt++;
      pos = b[pos];
    }

  long long int loop = cnt - c[pos];
  long long int mod = 0;
  for (i = 0; i < strlen (str); i++)
    mod = (mod * 10 + str[i] - '0') % loop;

  for (i = 0; i < mod + loop * 20; i++)
    a = b[a];
  printf ("%d\n", a);
  return 0;
}
