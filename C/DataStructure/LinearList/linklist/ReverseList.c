// -1156203886

#include <stdio.h>
#include "linklist.h"

void ReverseList_L(LinkList L)
{
  if (!L)
    return ERROR;

  LinkList p = L->next;
  LinkList q;
  
  L->next = NULL;
  while (p)
  {
    q = p->next;
    p->next = L->next;
    L->next = p;
    p = q;
  }
}

int main()
{
  LinkList L;

  InitList_L(&L);

  srand(time(0));
  CreateList_L(L);
  printf("L: ");
  PrintList_L(L);
  ReverseList_L(L);
  printf("Reverse L: ");
  PrintList_L(L);

  return 0;
}
