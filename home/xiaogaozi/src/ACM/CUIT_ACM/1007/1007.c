// -1156203886

#include <stdio.h>

int main()
{
  int n;

  freopen("input", "r", stdin);
  freopen("output", "w", stdout);
  while (1)
  {
    scanf("%d", &n);
    if (!n)
      break;
    if (n % 4 == 2)
      printf("yes\n");
    else
      printf("no\n");
  }

  return 0;
}
