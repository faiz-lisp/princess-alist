// -1156203886

#include <stdio.h>
#include "sqstack.h"

#define TRUE 1
#define FALSE 0
#define OPSIZE 7

typedef float OperandType;

char OP[OPSIZE] = {'+', '-', '*', '/', '(', ')', '#'};
int map[7][7] = {{1, 1, -1, -1, -1, 1, 1},
                 {1, 1, -1, -1, -1, 1, 1},
                 {1, 1, 1, 1, -1, 1, 1},
                 {1, 1, 1, 1, -1, 1, 1},
                 {-1, -1, -1, -1, -1, 0, -2},
                 {1, 1, 1, 1, -2, 1, 1},
                 {-1, -1, -1, -1, -1, -2, 0}};

// judge whether the parameter 'c' is a operator in array OP
// return TRUE means YES
// return FALSE means NO
Status In(char c, char* op)
{
  int i;
  for (i = 0; i != OPSIZE; ++i)
    if (*(op + i) == c)
      return TRUE;
  return FALSE;
}

// convert character to integer with special meaning
int Converter(char c)
{
  if (!In(c, OP))
    return c - '0';
  else
    switch (c)
    {
      case '+' : return 0;
      case '-' : return 1;
      case '*' : return 2;
      case '/' : return 3;
      case '(' : return 4;
      case ')' : return 5;
      case '#' : return 6;
    }
  return 612;
}

int Precede(int optr, int c)
{
  return map[optr][c];
}

OperandType Operate(OperandType a, int t, OperandType b)
{
  switch (t)
  {
    case 0 : return a + b;
    case 1 : return a - b;
    case 2 : return a * b;
    case 3 : return a / b;
  }
  return 612;
}

OperandType EvaluateExpression()
{
  SqStack OPTR, OPND;
  InitStack(&OPTR);
  Push(&OPTR, 6);
  InitStack(&OPND);
  char c;
  float x, a, b, theta;
  c = getchar();

  while (c != '#' || (int) GetTop(OPTR) != 6)
  {
    if (!In(c, OP))
    {
      Push(&OPND, Converter(c));
      c = getchar();
    }
    else
      switch (Precede(GetTop(OPTR), Converter(c)))
      {
        case -1 : // -1 == '<'
          Push(&OPTR, Converter(c));
          c = getchar();
          break;
        case 0 : // 0 == '='
          Pop(&OPTR, &x);
          c = getchar();
          break;
        case 1 : // 1 == '>'
          Pop(&OPTR, &theta);
          Pop(&OPND, &b);
          Pop(&OPND, &a);
          Push(&OPND, Operate(a, theta, b));
          break;
      }
  }
  
  return GetTop(OPND);
}

int main()
{
  printf("input an expression, end with '#': ");
  printf("the result is: %.2f\n", EvaluateExpression());

  return 0;
}
