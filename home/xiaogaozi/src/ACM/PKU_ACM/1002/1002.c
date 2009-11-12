#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define END 1

typedef struct
{
  int num;
  int time;
}Node;

int compare_node(const void* p1, const void* p2)
{
  Node* pp1 = (Node*) p1;
  Node* pp2 = (Node*) p2;

  if (pp1->num < pp2->num)
    return -1;
  else if (pp1->num == pp2->num)
    return 0;
  else
    return 1;
}

int main()
{
  long _begin_time = clock();
  int _a;

  for (_a = 0; _a != END; ++_a)
  {
    freopen("input", "r", stdin);

    int n;
    scanf("%d", &n);
    getchar();

    int i, j, length_of_a = 0;
    Node a[100000];
    for (i = 0; i != 100000; ++i)
    {
      a[i].time = 0;
    }
    char b[1000], c[8];
    while (n--)
    {
      scanf("%s", b);
      for (i = 0, j = 0; i != strlen(b); ++i)
      {
        if (b[i] >= '0' && b[i] <= '9')
        {
          c[j++] = b[i];
        }
        else
        {
          switch (b[i])
          {
            case 'A':
            case 'B':
            case 'C':
              c[j++] = '2';
            break;
            case 'D':
            case 'E':
            case 'F':
              c[j++] = '3';
            break;
            case 'G':
            case 'H':
            case 'I':
              c[j++] = '4';
            break;
            case 'J':
            case 'K':
            case 'L':
              c[j++] = '5';
            break;
            case 'M':
            case 'N':
            case 'O':
              c[j++] = '6';
            break;
            case 'P':
            case 'R':
            case 'S':
              c[j++] = '7';
            break;
            case 'T':
            case 'U':
            case 'V':
              c[j++] = '8';
            break;
            case 'W':
            case 'X':
            case 'Y':
              c[j++] = '9';
            break;
          }
        }
      }
      c[j] = '\0';
      i = atoi(c);

      if (!length_of_a)
      {
        a[0].num = i;
        ++a[0].time;
        ++length_of_a;
      }
      else
      {
        // Node* res = bsearch(&i, a, length_of_a, sizeof(Node), compare_node);
        // if (res == NULL)
        // {
        //   a[length_of_a].num = i;
        //   ++a[length_of_a].time;
        //   ++length_of_a;
        // }
        // else
        // {
        //   ++res->time;
        // }

        for (j = 0; j != length_of_a; ++j)
        {
          if (a[j].num == i)
          {
            ++a[j].time;
            break;
          }
        }
        if (j == length_of_a)
        {
          a[length_of_a].num = i;
          ++a[length_of_a].time;
          ++length_of_a;
        }
      }
    }

    qsort(a, length_of_a, 8, compare_node);

    j = 0;
    for (i = 0; i != length_of_a; ++i)
    {
      if (a[i].time != 1)
      {
        j = 1;
        printf("%03d-%04d %d\n", a[i].num / 10000, a[i].num % 10000, a[i].time);
      }
    }
    if (!j)
      printf("No duplicates.\n");
  }

  long _end_time = clock();
  printf("\ntime: %ld MS\n", (_end_time - _begin_time) / END);

  return 0;
}
