// -1156203886

#include <stdio.h>
#include <string.h>

int main()
{
  int line, i, j, t;
  char data[81], tmp[20][40];

  while (1)
  {
    scanf("%d", &line);
    getchar();
    if (!line)
      break;
    scanf("%s", data);
    t = -1;
    for (i = line - 1; i != -1; --i)
    {
      for (j = 0; j != (i + 1) * 2 - 1; ++j)
      {
        t = (t + 1) % strlen(data);
        *(*(tmp + i) + j) = data[t];
      }
      *(*(tmp + i) + j) = 0;
    }
    for (i = 0; i != line; ++i)
    {
      for (j = i; j != line - 1; ++j)
        printf(" ");
      printf("%s\n", *(tmp + i));
    }
  }

  return 0;
}
