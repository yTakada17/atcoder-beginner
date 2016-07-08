#include<stdio.h>
#include<string.h>
#include<stdlib.h>


#define mass(x, y)   mass[(x) + (y) * (50)]
#define steps(x, y)  steps[(x) + (y) * (50)]
#define WALL    -1


void
search_around (int x, int y, int step, int steps[])
{

  if (step < steps (x, y) || step == 0)
    {
      steps (x, y) = step;
      search_around (x - 1, y, step + 1, steps);
      search_around (x + 1, y, step + 1, steps);
      search_around (x, y - 1, step + 1, steps);
      search_around (x, y + 1, step + 1, steps);
    }
}


int
main (void)
{
  int i, j, r, c, sx, sy, gx, gy, min;
  int steps[50 * 50];
  char mass[2501], dummy;

  scanf ("%d %d", &r, &c);
  scanf ("%d %d", &sx, &sy);
  scanf ("%d %d", &gx, &gy);

  for (i = 0; i < r; i++)
    {
      scanf ("%c", &dummy);
      for (j = 0; j < c; j++)
	{
	  scanf ("%c", &mass (i, j));
	}
    }

  for (i = 0; i < 50 * 50; i++)
    {
      steps[i] = 2560;
    }

  steps (sx - 1, sy - 1) = 0;
  for (i = 0; i < r; i++)
    {
      for (j = 0; j < c; j++)
	{
	  if (strncmp (&mass (i, j), "#", 1) == 0)
	    {
	      steps (i, j) = WALL;
	    }
	}
    }

  search_around (sx - 1, sy - 1, 0, steps);
  min = steps (gx - 1, gy - 1);

  printf ("%d\n", min);

  return 0;
}
