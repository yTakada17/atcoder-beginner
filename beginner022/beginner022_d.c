#include<stdio.h>
#include<math.h>
int
main ()
{

  int N;
  int i;
  scanf ("%d", &N);
  int Ax[N], Ay[N], Bx[N], By[N];
  double SAx = 0, SAy = 0, SBx = 0, SBy = 0;
  for (i = 0; i < N; i++)
    {
      int x, y;
      scanf ("%d%d", &x, &y);
      Ax[i] = x;
      Ay[i] = y;
      SAx += x;
      SAy += y;
    }
  for (i = 0; i < N; i++)
    {
      int x, y;
      scanf ("%d%d", &x, &y);
      Bx[i] = x;
      By[i] = y;
      SBx += x;
      SBy += y;
    }
  SAx /= N;
  SAy /= N;
  SBx /= N;
  SBy /= N;
  double GA = 0, GB = 0;
  for (i = 0; i < N; i++)
    {
      GA +=
	sqrt ((SAx - Ax[i]) * (SAx - Ax[i]) + (SAy - Ay[i]) * (SAy - Ay[i]));
      GB +=
	sqrt ((SBx - Bx[i]) * (SBx - Bx[i]) + (SBy - By[i]) * (SBy - By[i]));
    }
  printf ("%lf\n", GB / GA);
  return 0;
}
