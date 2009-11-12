/*
 * Exponentiation <http://acm.pku.edu.cn/JudgeOnline/problem?id=1001>
 *
 * Problem: 1001    User: Slashell
 * Memory: 332K     Time: 16MS
 * Language: GCC    Result: Accepted 
 *
 * Problem: 1001    User: Slashell
 * Memory: 216K     Time: 16MS
 * Language: C      Result: Accepted
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  freopen("input", "r", stdin);

  char r[6], *result, *temp_result, *temp_result2, *temp_result3;
  int n, i, j, k, x, y, t, digit, d_digit, d_position, head, tail, peri, alist;
  result = temp_result = temp_result2 = temp_result3 = NULL;

  while (scanf("%s%d", r, &n) != EOF)
  {
    if (!n)
    {
      printf("1\n");
      continue;
    }

    i = digit = d_position = head = tail = 0;
    d_digit = 5;

    while (d_position <= 5 && r[d_position++] != '.')
      ;
    if (d_position > 5)
    {
      d_digit = 0;
      while (digit != d_position && r[digit++] == '0')
        ;
      if (digit == d_position)
        digit = 0;
      else
      {
        head = --digit;
        tail = strlen(r) - 1;
        digit = tail - head + 1;
      }
    }
    else
    {
      --d_position;
      while (digit != d_position && r[digit++] == '0')
        ;
      if (digit == d_position && r[digit - 1] == '0')
      {
        digit = 0;
        head = d_position + 1;
      }
      else
      {
        head = --digit;
        digit = d_position - digit;
      }
      while (d_digit != d_position && r[d_digit--] == '0')
        ;
      if (d_digit == d_position && r[d_digit + 1] == '0')
      {
        d_digit = 0;
        tail = d_position - 1;
      }
      else
      {
        tail = ++d_digit;
        d_digit -= d_position;
      }
      digit += d_digit;
    }

    if (!digit)
    {
      printf("0\n");
      continue;
    }

    result = (char*) realloc(result, sizeof(char) * (digit + 1));
    temp_result = (char*) realloc(temp_result, sizeof(char) * (digit + 1));
    temp_result2 = (char*) realloc(temp_result2, sizeof(char) * (digit + 1));
    while (head - 1 != tail)
      if (tail != d_position)
        temp_result[i++] = r[tail--];
      else
        --tail;
    temp_result[i] = '\0';
    strcpy(result, temp_result);
    strcpy(temp_result2, temp_result);

    for (k = 0; k != n - 1; ++k)
    {
      temp_result2 = (char*) realloc(temp_result2, sizeof(char) * (strlen(result) + 1));
      temp_result3 = (char*) realloc(temp_result3, sizeof(char) * (strlen(result) + 1));
      strcpy(temp_result3, result);
      for (i = 0; i != digit; ++i)
      {
        peri = 0;
        for (j = 0; j != strlen(temp_result3); ++j)
        {
          alist = (temp_result[i] - '0') * (temp_result3[j] - '0') + peri;
          temp_result2[j] = alist % 10 + '0';
          peri = alist / 10;
        }
        temp_result2[j] = '\0';
        if (peri)
        {
          if (strlen(result) <= strlen(temp_result2))
            result = (char*) realloc(result, sizeof(char) * (strlen(temp_result3) + 2));
          temp_result2 = (char*) realloc(temp_result2, sizeof(char) * (strlen(temp_result3) + 2));
          temp_result2[strlen(temp_result3)] = peri + '0';
          temp_result2[strlen(temp_result3) + 1] = '\0';
        }
        peri = 0;
        if (!i)
          strcpy(result, temp_result2);
        else
        {
          for (x = i, y = 0; x != strlen(result) && y != strlen(temp_result2); ++x, ++y)
          {
            alist = (result[x] - '0') + (temp_result2[y] - '0') + peri;
            result[x] = alist % 10 + '0';
            peri = alist / 10;
          }
          if (peri)
          {
            if (y != strlen(temp_result2))
            {
              result = (char*) realloc(result, sizeof(char) * (strlen(result) + strlen(temp_result2) - y + 1));
              for (t = y; t != strlen(temp_result2); ++t)
              {
                alist = temp_result2[t] - '0' + peri;
                result[x++] = alist % 10 + '0';
                peri = alist / 10;
              }
              result[x] = '\0';
              if (peri)
              {
                result = (char*) realloc(result, sizeof(char) * (strlen(result) + 2));
                result[strlen(result) + 1] = '\0';
                result[strlen(result)] = peri + '0';
              }
            }
            else
            {
              result = (char*) realloc(result, sizeof(char) * (strlen(result) + 2));
              result[strlen(result) + 1] = '\0';
              result[strlen(result)] = peri + '0';
            }
          }
          else
          {
            if (y != strlen(temp_result2))
            {
              result = (char*) realloc(result, sizeof(char) * (strlen(result) + strlen(temp_result2) - y + 1));
              for (t = y; t != strlen(temp_result2); ++t)
                result[x++] = temp_result2[t];
              result[x] = '\0';
            }
          }
        }
      }
    }

    for (i = 0; i != strlen(result) / 2; ++i)
    {
      r[0] = result[i];
      result[i] = result[strlen(result) - i - 1];
      result[strlen(result) - i - 1] = r[0];
    }

    if (d_digit <= 0)
    {
      for (i = 0; i != strlen(result) && result[i] == '0'; ++i)
        ;
      for (j = i; j != strlen(result); ++j)
        putchar(result[j]);
      printf("\n");
    }
    else
    {
      d_digit = d_digit * n;
      if (d_digit < strlen(result))
      {
        y = strlen(result) - d_digit;
        for (i = 0; i != y && result[i] == '0'; ++i)
          ;
        for (j = strlen(result) - 1; j != y - 1 && result[j] == '0'; --j)
          ;
        for (x = i; x != j + 1; ++x)
        {
          if (x == y)
            putchar('.');
          putchar(result[x]);
        }
        printf("\n");
      }
      else if (d_digit == strlen(result))
      {
        putchar('.');
        for (i = strlen(result) - 1; i != -1 && result[i] == '0'; --i)
          ;
        for (j = 0; j != i + 1; ++j)
          putchar(result[j]);
        printf("\n");
      }
      else
      {
        putchar('.');
        for (i = 0; i != d_digit - strlen(result); ++i)
          putchar('0');
        for (j = strlen(result) - 1; j != -1 && result[j] == '0'; --j)
          ;
        for (x = 0; x != j + 1; ++x)
          putchar(result[x]);
        printf("\n");
      }
    }

    free(result);
    result = NULL;
    free(temp_result);
    temp_result = NULL;
    free(temp_result2);
    temp_result2 = NULL;
    free(temp_result3);
    temp_result3 = NULL;
  }

  return 0;
}
