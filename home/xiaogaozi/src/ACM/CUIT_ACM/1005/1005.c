// -1156203886

#include <stdio.h>

int main()
{
  int block, line, i, j, t;
  char c, input[50];

  freopen("input", "r", stdin);

  scanf("%d", &block);
  for (i = 0; i != block; ++i)
  {
    scanf("%d\n", &line);
    for (j = 0; j != line; ++j)
    {
      t = 0;
      while ((c = getchar()) != EOF)
      {
        if (c == ' ' || c == '\n')
        {
          while (t--)
            printf("%c", input[t]);
          printf("%c", c);
          if (c == '\n')
            break;
          t = 0;
        }
        else
          input[t++] = c;
      }
    }
    printf("\n");
    getchar();
  }

  fclose(stdin);

  return 0;
}
