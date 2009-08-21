// -1156203886

#include <stdio.h>
#include "bitree.h"

int main()
{
  BiTree T;

  printf("preorder input\n");
  CreateBiTree(&T);

  printf("\nTraverse\npreorder(recurssion): ");
  PreOrderTraverse(T, PrintElement);
  printf("\n");
  printf("preorder(unrecurssion): ");
  PreOrderTraverseUnre(T, PrintElement);
  printf("\n");
  printf("inorder(recurssion): ");
  InOrderTraverse(T, PrintElement);
  printf("\n");
  printf("inorder(unrecurssion): ");
  InOrderTraverseUnre(T, PrintElement);
  printf("\n");
  printf("postorder(recurssion): ");
  PostOrderTraverse(T, PrintElement);
  printf("\n\n");

  printf("%d nodes\n", CountNode(T));
  int num[100], i;
  char* str;
  for (i = 0; i != 100; ++i)
    num[i] = 0;
  CountLevelNode(T, num);
  printf("Depth: %d\n", num[0]);
  for (i = 1; i != num[0] + 1; ++i)
  {
    if (num[i] == 1)
      str = "node";
    else
      str = "nodes";
    printf("Level %d: %d %s\n", i, num[i], str);
  }

  char c;
  i = 0;
  printf("\ninput a char: ");
  scanf("%c", &c);
  getchar();
  CountSubtreeNode(T, c, &i);
  printf("subtree: %d nodes\n", i);

  char e;
  printf("\ninput #1 as #2's rchild: ");
  scanf("%c %c", &e, &c);
  InsertRChild(T, e, c);
  printf("preorder: ");
  PreOrderTraverse(T, PrintElement);
  printf("\n");

  return 0;
}
