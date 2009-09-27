// -1156203886

#ifndef SQQUEUE_H
#define SQQUEUE_H

#include <stdlib.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define OVERFLOW -2

typedef int Status;
typedef int QElemType;
typedef struct
{
  QElemType* base;
  int front;
  int rear;
  int maxsize;
}SqQueue;

Status InitQueue_Sq(SqQueue* Q, int maxsize)
{
  Q->base = (QElemType*) malloc((maxsize + 1) * sizeof(QElemType));
  if (!Q->base) exit(OVERFLOW);
  Q->front = Q->rear = 0;
  Q->maxsize = maxsize + 1;
  return OK;
}

Status QueueEmpty_Sq(SqQueue Q)
{
  if (!Q.base) return ERROR;
  if (Q.front == Q.rear) return TRUE;
  return FALSE;
}

Status EnQueue_Sq(SqQueue* Q, QElemType e)
{
  if (!Q->base) return ERROR;
  if ((Q->rear + 1) % Q->maxsize == Q->front) return ERROR;
  Q->base[Q->rear] = e;
  Q->rear = (Q->rear + 1) % Q->maxsize;
  return OK;
}

Status DeQueue_Sq(SqQueue* Q, QElemType* e)
{
  if (!Q->base) return ERROR;
  if (Q->rear == Q->front) return ERROR;
  *e = Q->base[Q->front];
  Q->front = (Q->front + 1) % Q->maxsize;
  return OK;
}

#endif
