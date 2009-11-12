// -1156203886

#include <stdio.h>
#include <stdlib.h>

int main()
{
  int count, i = 0;
  char data[1001];

  scanf("%d", &count);
  char* priority = (char*) malloc((count + 1) * sizeof(char));
  int* time = (int*) malloc(count * sizeof(int));
  for (; i != count; ++i)
    time[i] = 0;
  scanf("%s", priority);
  scanf("%s", data);

  i = 0;
  while (data[i])
  {
    count = 0;
    while (priority[count])
    {
      if (priority[count] == data[i])
      {
        ++time[count];
        break;
      }
      ++count;
    }
    ++i;
  }

  count = 0;
  while (priority[count])
  {
    for (i = 0; i != time[count]; ++i)
      printf("%c", priority[count]);
    ++count;
  }
  printf("\n");

  free(priority);
  priority = 0;
  free(time);
  time = 0;

  return 0;
}
