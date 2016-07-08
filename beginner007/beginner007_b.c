#include <stdio.h>
#include <string.h>
int
main ()
{
  int i;
  char a[10];
  int len;
  scanf ("%s", a);
  len = strlen (a);

  if (len == 1)
    {
      if (a[0] == 'a')
	printf ("-1\n");
      else
	printf ("a\n");
    }
  if (len > 1)
    printf ("a\n");
  return 0;
}
