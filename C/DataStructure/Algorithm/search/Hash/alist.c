// -1156203886

#include <stdio.h>
#include "hashtable.h"

int main()
{
  HashTable H;
  KeyType key;

  freopen("input", "r", stdin);
  freopen("output", "w", stdout);

  InitHash(&H);
  scanf("%d", &key);
  while (key != 65535)
  {
    CreateHash(&H, key);
    scanf("%d", &key);
  }
  int i;
  for (i = 0; i != H.sizeindex; ++i)
    printf("%d ", H.elem[i].key);
  printf("\n");

  KeyType searchkey;
  scanf("%d", &searchkey);
  printf("%d\n", SearchHash(H, searchkey));

  return 0;
}
