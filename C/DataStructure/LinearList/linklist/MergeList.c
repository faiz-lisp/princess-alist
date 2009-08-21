// -1156203886

#include <stdio.h>
#include "linklist.h"

void MergeList_L(LinkList La, LinkList Lb, LinkList* Lc)
{
  LinkList pa = La->next;
  LinkList pb = Lb->next;
  LinkList pc = La;
  *Lc = pc;

  while (pa && pb)
  {
    if (pa->data <= pb->data)
    {
      pc->next = pa;
      pc = pa;
      pa = pa->next;
    }
    else
    {
      pc->next = pb;
      pc = pb;
      pb = pb->next;
    }
  }

  pc->next = pa ? pa : pb;
  free(Lb);
}

int main()
{
  LinkList La, Lb, Lc;

  InitList_L(&La);
  InitList_L(&Lb);

  srand(time(0));
  CreateList_L(La);
  printf("La: ");
  PrintList_L(La);
  CreateList_L(Lb);
  printf("Lb: ");
  PrintList_L(Lb);

  MergeList_L(La, Lb, &Lc);
  printf("Lc: ");
  PrintList_L(Lc);

  return 0;
}
