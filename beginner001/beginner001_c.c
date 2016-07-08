#include <stdio.h>
#include<string.h>

int
main ()
{
  double dig = 0;
  int dist = 0;
  int W = 0;
  char dir[4] = { };

  scanf ("%lf %d", &dig, &dist);
  dist = ((double) dist / 6 + 0.5);

  if ((112.5 <= dig) && (dig < 337.5))
    strcpy (dir, "NNE");
  else if ((337.5 <= dig) && (dig < 562.5))
    strcpy (dir, "NE");
  else if ((562.5 <= dig) && (dig < 787.5))
    strcpy (dir, "ENE");
  else if ((787.5 <= dig) && (dig < 1012.5))
    strcpy (dir, "E");
  else if ((1012.5 <= dig) && (dig < 1237.5))
    strcpy (dir, "ESE");
  else if ((1237.5 <= dig) && (dig < 1462.5))
    strcpy (dir, "SE");
  else if ((1462.5 <= dig) && (dig < 1687.5))
    strcpy (dir, "SSE");
  else if ((1687.5 <= dig) && (dig < 1912.5))
    strcpy (dir, "S");
  else if ((1912.5 <= dig) && (dig < 2137.5))
    strcpy (dir, "SSW");
  else if ((2137.5 <= dig) && (dig < 2362.5))
    strcpy (dir, "SW");
  else if ((2362.5 <= dig) && (dig < 2587.5))
    strcpy (dir, "WSW");
  else if ((2587.5 <= dig) && (dig < 2812.5))
    strcpy (dir, "W");
  else if ((2812.5 <= dig) && (dig < 3037.5))
    strcpy (dir, "WNW");
  else if ((3037.5 <= dig) && (dig < 3262.5))
    strcpy (dir, "NW");
  else if ((3262.5 <= dig) && (dig < 3487.5))
    strcpy (dir, "NNW");
  else
    strcpy (dir, "N");


  if ((dist >= 0) && (dist <= 2))
    {
      sprintf (dir, "%s", "C");
      W = 0;
    }
  else if ((dist >= 3) && (dist <= 15))
    W = 1;
  else if ((dist >= 16) && (dist <= 33))
    W = 2;
  else if ((dist >= 34) && (dist <= 54))
    W = 3;
  else if ((dist >= 55) && (dist <= 79))
    W = 4;
  else if ((dist >= 80) && (dist <= 107))
    W = 5;
  else if ((dist >= 108) && (dist <= 138))
    W = 6;
  else if ((dist >= 139) && (dist <= 171))
    W = 7;
  else if ((dist >= 172) && (dist <= 207))
    W = 8;
  else if ((dist >= 208) && (dist <= 244))
    W = 9;
  else if ((dist >= 245) && (dist <= 284))
    W = 10;
  else if ((dist >= 285) && (dist <= 326))
    W = 11;
  else if (dist >= 327)
    W = 12;

  printf ("%s %d\n", dir, W);

  return 0;
}
