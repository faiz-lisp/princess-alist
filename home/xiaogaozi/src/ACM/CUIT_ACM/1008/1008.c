// -1156203886

#include <stdio.h>

int main()
{
  int m, n, i, j;
  float sum;
  
  scanf("%d", &m);
  for (i = 0; i != m; ++i)
  {
    sum = 0;
    scanf("%d", &n);
    for (j = 1; j != n + 1; ++j)
    {
      if (j % 2)
        sum += 1.0 / j;
      else
        sum -= 1.0 / j;
    }
    printf("%.1f\n", sum);
  }

  return 0;
}
