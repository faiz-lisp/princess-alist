// -1156203886

#include <stdio.h>

int main()
{
  int jump, i = -1;
  char input[81];

  scanf("%d", &jump);
  getchar();
  do
  {
    ++i;
    input[i] = getchar();
  }
  while (input[i] != '\n');
  input[i] = 0;

  jump %= 26;
  i = 0;
  while (input[i])
  {
    if (input[i] >= 'A' && input[i] <= 'Z')
    {
      input[i] = input[i] - jump;
      if (input[i] < 'A')
        input[i] += 26;
    }
    else if (input[i] >= 'a' && input[i] <= 'z')
    {
      input[i] = input[i] - jump;
      if (input[i] < 'a')
        input[i] += 26;
    }
    else
      ;
    ++i;
  }

  printf("%s\n", input);

  return 0;
}
