// -1156203886

#ifndef BST_H
#define BST_H

#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define OVERFLOW -2

typedef int Status;
typedef int TElemType;
typedef struct BiTNode
{
  TElemType data;
  struct BiTNode* lchild;
  struct BiTNode* rchild;
}BiTNode, *BiTree;

Status SearchBST(BiTree T, TElemType e, BiTree f, BiTree* p)
{
  if (!T)
  {
    *p = f;
    return FALSE;
  }
  else if (e == T->data)
  {
    *p = T;
    return TRUE;
  }
  else if (e < T->data)
    return SearchBST(T->lchild, e, T, p);
  else
    return SearchBST(T->rchild, e, T, p);
}

Status InsertBST(BiTree* T, TElemType e)
{
  BiTree p, s;
  if (!SearchBST(*T, e, NULL, &p))
  {
    s = (BiTree) malloc(sizeof(BiTNode));
    s->data = e;
    s->lchild = s->rchild = NULL;
    if (!p)
      *T = s;
    else if (e < p->data)
      p->lchild = s;
    else
      p->rchild = s;
  }
  return TRUE;
}

Status CreateBST(BiTree* T)
{
  TElemType e;
  while (1)
  {
    scanf("%d", &e);
    if (e == 65535)
      break;
    InsertBST(T, e);
  }
  return OK;
}

Status PrintElement(TElemType e)
{
  printf("%d ", e);
  return OK;
}

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

Status Delete(BiTree* p)
{
  BiTree q = (BiTree) malloc(sizeof(BiTNode));
  BiTree s = (BiTree) malloc(sizeof(BiTNode));
  // BiTree q, s;
  if (!((*p)->rchild))
  {
    q = *p;
    *p = (*p)->lchild;
    free(q);
  }
  else if (!((*p)->lchild))
  {
    q = *p;
    *p = (*p)->rchild;
    free(q);
  }
  else
  {
    q = *p;
    s = (*p)->lchild;
    while (s->rchild)
    {
      q = s;
      s = s->rchild;
    }
    (*p)->data = s->data;
    if (q != *p)
      q->rchild = s->lchild;
    else
      q->lchild = s->lchild;
    free(s);
  }
  return TRUE;
}

Status DeleteBST(BiTree* T, TElemType e)
{
  if (!T)
    return FALSE;
  else
  {
    if (e == (*T)->data)
      return Delete(T);
    else if (e < (*T)->data)
      return DeleteBST(&((*T)->lchild), e);
    else
      return DeleteBST(&((*T)->rchild), e);
  }
}

#endif
