#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define END 10000

int main()
{
    long _begin_time = clock();
    int _a;

    for (_a = 0; _a != END; ++_a)
    {
        freopen("input", "r", stdin);
    }

    long _end_time = clock();
    printf("\ntime: %ld MS\n", (_end_time - _begin_time) / END);

    exit(EXIT_SUCCESS);
}
