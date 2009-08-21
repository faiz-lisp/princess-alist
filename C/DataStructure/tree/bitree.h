// -1156203886

#ifndef BITREE_H
#define BITREE_H

typedef int Status;
typedef char TElemType;
typedef struct BiTNode
{
  TElemType data;
  struct BiTNode* lchild;
  struct BiTNode* rchild;
}BiTNode, *BiTree;

#include <stdio.h>
#include <stdlib.h>
#include "sqstack.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define OVERFLOW -2

int count = 0;  // the number of nodes

/*
 * create a binary tree with preorder input
 */
Status CreateBiTree(BiTree* T)
{
  char c;

  printf("input: ");
  scanf("%c", &c);
  getchar();

  if (c == ' ')
    *T = NULL;
  else
  {
    if (!(*T = (BiTree) malloc(sizeof(BiTNode))))
      exit(OVERFLOW);

    (*T)->data = c;
    CreateBiTree(&(*T)->lchild);
    CreateBiTree(&(*T)->rchild);
  }

  return OK;
}

/*
 * print element
 */
Status PrintElement(TElemType e)
{
  printf("%c ", e);
  return OK;
}

/*
 * judge whether 'd' is in the tree
 */
Status IsExist(BiTree T, TElemType d, BiTree* pos)
{
  static int flag;

  if (T)
  {
    if (T->data == d)
    {
      flag = 1;
      *pos = T;
      return TRUE;
    }
    IsExist(T->lchild, d, pos);
    IsExist(T->rchild, d, pos);
  }

  if (flag == 1)
    return TRUE;
  else
    return FALSE;
}

/*
 * in some function operate element with preorder
 * recurssion algorithm
 */
Status PreOrderTraverse(BiTree T, Status (*Visit)(TElemType e))
{
  if (T)
  {
    if (Visit(T->data))
      if (PreOrderTraverse(T->lchild, Visit))
        if (PreOrderTraverse(T->rchild, Visit))
          return OK;
    return ERROR;
  }
  else
    return OK;
}

/*
 * in some function operate element with preorder
 * unrecurssion algorithm
 */
Status PreOrderTraverseUnre(BiTree T, Status (*Visit)(TElemType e))
{
  SqStack S;

  InitStack(&S);
  Push(&S, T);

  SElemType p;
  while (!StackEmpty(S))
  {
    while ((p = GetTop(S)))
    {
      if (!Visit(p->data))
        return ERROR;
      Push(&S, p->lchild);
    }
    Pop(&S, &p);
    if (!StackEmpty(S))
    {
      Pop(&S, &p);
      Push(&S, p->rchild);
    }
  }

  return OK;
}

/*
 * in some function operate element with inorder
 * recurssion algorithm
 */
Status InOrderTraverse(BiTree T, Status (*Visit)(TElemType e))
{
  if (T)
  {
    if (InOrderTraverse(T->lchild, Visit))
      if (Visit(T->data))
        if (InOrderTraverse(T->rchild, Visit))
          return OK;
    return ERROR;
  }
  else
    return OK;
}

/*
 * in some function operate element with inorder
 * unrecurssion algorithm
 */
Status InOrderTraverseUnre(BiTree T, Status (*Visit)(TElemType e))
{
  SqStack S;

  InitStack(&S);
  Push(&S, T);

  SElemType p;
  while (!StackEmpty(S))
  {
    while ((p = GetTop(S)))
      Push(&S, p->lchild);
    Pop(&S, &p);
    if (!StackEmpty(S))
    {
      Pop(&S, &p);
      if (!Visit(p->data))
        return ERROR;
      Push(&S, p->rchild);
    }
  }

  return OK;
}

/*
 * in some function operate element with postorder
 * recurssion algorithm
 */
Status PostOrderTraverse(BiTree T, Status (*Visit)(TElemType e))
{
  if (T)
  {
    if (PostOrderTraverse(T->lchild, Visit))
      if (PostOrderTraverse(T->rchild, Visit))
        if (Visit(T->data))
          return OK;
    return ERROR;
  }
  else
    return OK;
}

/*
 * count number of nodes
 */
int CountNode(BiTree T)
{
  int x = 0, y = 0;

  if (T)
  {
    x = CountNode(T->lchild);
    y = CountNode(T->rchild);
    return x + y + 1;
  }
  return 0;
}

/*
 * count number of nodes in every level and depth of tree
 */
Status CountLevelNode(BiTree T, int* num)
{
  static int k = 0;
  ++k;

  if (T)
  {
    ++num[k];
    if (k > num[0])
      num[0] = k;

    if (CountLevelNode(T->lchild, num))
      if (CountLevelNode(T->rchild, num))
      {
        --k;
        return OK;
      }
    return ERROR;
  }
  else
  {
    --k;
    return OK;
  }
}

/*
 * if 'data' equal to 'e', then count number of nodes.
 */
Status IsEqual(BiTree T, TElemType data, TElemType e, int* c)
{
  if (data == e)
    *c = CountNode(T) - 1;
  else
    *c = 0;

  return OK;
}

/*
 * count the number of subtree's nodes,
 * value of this subtree's root equle to the parameter 'e'.
 */
Status CountSubtreeNode(BiTree T, TElemType e, int* i)
{
  int c = 0;
  SqStack S;

  InitStack(&S);
  Push(&S, T);

  SElemType p;
  while (!StackEmpty(S))
  {
    while ((p = GetTop(S)))
    {
      if (!IsEqual(p, p->data, e, &c))
        return ERROR;
      *i += c;
      Push(&S, p->lchild);
    }
    Pop(&S, &p);
    if (!StackEmpty(S))
    {
      Pop(&S, &p);
      Push(&S, p->rchild);
    }
  }

  return OK;
}

/*
 * insert an element 'e' as the rchild of 'd'
 */
Status InsertRChild(BiTree T, TElemType e, TElemType d)
{
  if (!T)
    return ERROR;

  BiTree pos;
  if (!IsExist(T, d, &pos))
    return ERROR;

  if (!pos->rchild)
  {
    if (!(pos->rchild = (BiTree) malloc(sizeof(BiTNode))))
      exit(OVERFLOW);
    pos->rchild->data = e;
    pos->rchild->lchild = NULL;
    pos->rchild->rchild = NULL;
  }
  else
    pos->rchild->data = e;

  return OK;
}

#endif
