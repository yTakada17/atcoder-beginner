#include<stdio.h>

int
match (int a, int x1, int x2, int x3)
{
  if (a == x1 || a == x2 || a == x3)
    {
      return 0;
    }
  else
    {
      return 1;
    }
}

int
main ()
{
  int n = 0, ng1 = 0, ng2 = 0, ng3 = 0;
  int i = 0;

  scanf ("%d", &n);
  scanf ("%d", &ng1);
  scanf ("%d", &ng2);
  scanf ("%d", &ng3);

  if (match (n, ng1, ng2, ng3) == 0)
    {
      printf ("NO\n");
      return 0;
    }

  for (i = 0; i < 100; i++)
    {
      n -= 3;

      if (n <= 0)
	{
	  printf ("YES\n");
	  return 0;
	}

      if (match (n, ng1, ng2, ng3) == 0)
	{
	  n++;
	}
      if (match (n, ng1, ng2, ng3) == 0)
	{
	  n++;
	}
      if (match (n, ng1, ng2, ng3) == 0)
	{
	  printf ("NO\n");
	  return 0;
	}
    }
  printf ("NO\n");
  return 0;
}
