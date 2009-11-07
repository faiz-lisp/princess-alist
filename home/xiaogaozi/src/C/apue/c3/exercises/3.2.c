#include "../../apue.h"
#include <fcntl.h>

int mydup2(int oldfd, int newfd)
{
    if (oldfd == newfd)
        return newfd;

    close(newfd);
    long open_max = sysconf(_SC_OPEN_MAX) - 3;
    int* fd = (int*) malloc(sizeof(int) * open_max);
    int i, j;
    printf("open_max: %ld\n", open_max);
    for (i = 0; i != open_max; ++i)
    {
        fd[i] = dup(oldfd);
        if (fd[i] == -1)
            err_sys("dup error");
        if (fd[i] == newfd)
        {
            for (j = 0; j != i; ++j)
                close(fd[j]);
            free(fd);
            return newfd;
        }
    }

    return -1;
}

int main()
{
    int fd1, fd2;

    fd1 = open("/dev/ttyS0", O_RDONLY);
    if (fd1 == -1)
        err_sys("open error");
    printf("fd1: %d\n", fd1);

    int newfd = 2000;
    fd2 = mydup2(fd1, newfd);
    if (fd2 == -1)
        err_sys("mydup2 error");
    else
        printf("mydup2 success, fd1 is %d, fd2 is %d\n", fd1, fd2);

    if (fd1 == fd2)
        close(fd1);
    else
    {
        close(fd1);
        close(fd2);
    }

    exit(EXIT_SUCCESS);
}

