// -1156203886

#include <stdio.h>
#include <stdlib.h>

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define TRUE 1
#define FALSE 0

typedef int SElemType;
typedef int Status;
typedef struct
{
  SElemType* base;
  SElemType* top;
  int stacksize;
}SqStack;

Status InitStack(SqStack* S)
{
  S->base = (SElemType*) malloc(sizeof(SElemType) * STACK_INIT_SIZE);
  if (!S->base) exit(OVERFLOW);
  S->top = S->base;
  S->stacksize = STACK_INIT_SIZE;
  return OK;
}

Status Push(SqStack* S, SElemType e)
{
  if (S->top - S->base >= S->stacksize)
  {
    S->base = (SElemType*) realloc(S->base, (S->stacksize + STACKINCREMENT) * sizeof(SElemType));
    if (!S->base) exit(OVERFLOW);
    S->top = S->base + S->stacksize;
    S->stacksize += STACKINCREMENT;
  }

  *S->top++ = e;
  return OK;
}

Status Pop(SqStack* S, SElemType* e)
{
  if (S->base == S->top)
    return ERROR;
  *e = *--S->top;
  return OK;
}

Status StackEmpty(SqStack S)
{
  if (S.base == S.top)
    return TRUE;
  return FALSE;
}

int main()
{
  SqStack s;
  int count, num, i;

  scanf("%d", &count);
  InitStack(&s);
  for (i = 0; i != count; ++i)
  {
    scanf("%d", &num);
    while (num)
    {
      Push(&s, num % 7);
      num /= 7;
    }
    while (!StackEmpty(s))
    {
      Pop(&s, &num);
      printf("%d", num);
    }
    printf("\n");
  }

  return 0;
}
