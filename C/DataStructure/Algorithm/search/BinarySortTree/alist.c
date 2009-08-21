// -1156203886

#include <stdio.h>
#include "bst.h"

int main()
{
  BiTree T = NULL;

  freopen("input", "r", stdin);

  CreateBST(&T);
  InOrderTraverse(T, PrintElement);
  printf("\n");

  TElemType e;
  scanf("%d", &e);
  DeleteBST(&T, e);
  printf("after del %d: ", e);
  InOrderTraverse(T, PrintElement);
  printf("\n");

  return 0;
}
