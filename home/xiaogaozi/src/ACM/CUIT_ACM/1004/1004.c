// -1156203886

#include <stdio.h>
#include <math.h>

int main()
{
  int n, m, i, j, flag, num[500];

  do
  {
    num[498] = 0;
    num[499] = 0;
    scanf("%d,%d", &n, &m);
    if (n == 0 && m == 0)
      break;
    for (i = n; i != m + 1; ++i)
    {
      if (i > 1)
      {
        flag = 1;
        for (j = 2; j <= (int) sqrt(i * 1.0); ++j)
          if (i % j == 0)
          {
            flag = 0;
            break;
          }
        if (flag == 1)
          num[num[499]++] = i;
      }
    }
    for (i = 0; i < num[499] - 1; ++i)
      for (j = i + 1; j < num[499]; ++j)
        if (num[j] - num[i] <= 2)
        {
          printf("%d %d\n", num[i], num[j]);
          ++num[498];
        }
    printf("%d\n", num[498]);
  }
  while (1);

  return 0;
}
