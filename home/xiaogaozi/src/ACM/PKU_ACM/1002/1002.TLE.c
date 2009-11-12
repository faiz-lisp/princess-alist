/*
 * 487-3279 <http://acm.pku.edu.cn/JudgeOnline/problem?id=1002>
 *
 * Problem: 1002		User: Slashell
 * Memory: N/A		  Time: N/A
 * Language: GCC		Result: Time Limit Exceeded 
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define OVERFLOW -2

typedef int ElemType;
typedef int Status;
typedef struct LNode
{
  ElemType data;
  struct LNode* next;
  int time;
}LNode, *LinkList;

/*
 * Initialize a null linklist.
 */
Status InitList_L(LinkList* L)
{
  *L = (LinkList) malloc(sizeof(LNode));
  if (!*L)
    exit(OVERFLOW);
  (*L)->next = NULL;
  return OK;
}

/*
 * Insert a node at number i.
 */
Status ListInsert_L(LinkList L, int i, ElemType e)
{
  LinkList p = L;
  int j = 0;

  while (p && j < i - 1)
  {
    p = p->next;
    ++j;
  }

  if (!p || j > i - 1)
    return ERROR;
  LinkList s = (LinkList) malloc(sizeof(LNode));
  if (!s) exit(OVERFLOW);
  s->data = e;
  s->time = 1;
  s->next = p->next;
  p->next = s;
  return OK;
}

int ListLength_L(LinkList L)
{
  if (!L)
    return ERROR;

  L = L->next;
  int i = 0;
  while (L)
  {
    ++i;
    L = L->next;
  }

  return i;
}

Status ListEmpty_L(LinkList L)
{
  if (!L)
    return ERROR;

  if (!L->next)
    return TRUE;

  return FALSE;
}

int main()
{
  freopen("input", "r", stdin);

  int n;
  scanf("%d", &n);
  getchar();

  char s[100], d[7];
  int num, i, j;
  LinkList l[10], g;
  for (i = 0; i != 10; ++i)
    InitList_L(&l[i]);

  while (n--)
  {
    scanf("%s", s);
    for (i = 0, j = 0; i != strlen(s); ++i)
    {
      if (s[i] >= '0' && s[i] <= '9')
      {
        d[j++] = s[i];
      }
      else
      {
        switch (s[i])
        {
          case 'A' :
          case 'B' :
          case 'C' :
            d[j++] = '2';
            break;
          case 'D' :
          case 'E' :
          case 'F' :
            d[j++] = '3';
            break;
          case 'G' :
          case 'H' :
          case 'I' :
            d[j++] = '4';
            break;
          case 'J' :
          case 'K' :
          case 'L' :
            d[j++] = '5';
            break;
          case 'M' :
          case 'N' :
          case 'O' :
            d[j++] = '6';
            break;
          case 'P' :
          case 'R' :
          case 'S' :
            d[j++] = '7';
            break;
          case 'T' :
          case 'U' :
          case 'V' :
            d[j++] = '8';
            break;
          case 'W' :
          case 'X' :
          case 'Y' :
            d[j++] = '9';
            break;
        }
      }
    }
    for (num = 0, j = 0; j != 7; ++j)
      num = num * 10 + (d[j] - '0');

    i = d[0] - '0';
    if (ListEmpty_L(l[i]) == TRUE)
      ListInsert_L(l[i], 1, num);
    else
    {
      g = l[i]->next;
      j = 1;
      while (g)
      {
        if (num == g->data)
        {
          ++g->time;
          break;
        }
        else if (num < g->data)
        {
          ListInsert_L(l[i], j, num);
          break;
        }
        else
        {
          ++j;
          g = g->next;
        }
      }
      if (!g)
        ListInsert_L(l[i], ListLength_L(l[i]) + 1, num);
    }
  }

  j = 0;
  for (i = 0; i != 10; ++i)
    if (ListEmpty_L(l[i]) == FALSE)
    {
      g = l[i]->next;
      while (g)
      {
        if (g->time != 1)
        {
          j = 1;

          n = g->data;
          if (!i)
          {
            d[j - 1] = '0';
            for (j = 6; j >= 1; --j)
            {
              d[j] = n % 10 + '0';
              n /= 10;
            }
          }
          else
            for (j = 6; j >= 0; --j)
            {
              d[j] = n % 10 + '0';
              n /= 10;
            }
          for (j = 0; j != 7; ++j)
          {
            if (j == 3)
              putchar('-');
            putchar(d[j]);
          }
          printf(" %d\n", g->time);
        }
        g = g->next;
      }
    }
  if (!j)
    printf("No duplicates.\n");

  return 0;
}
