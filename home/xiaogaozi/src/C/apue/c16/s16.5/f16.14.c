#include "../../apue.h"
#include <strings.h>
#include <netdb.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAXADDRLEN 256

#define BUFLEN 1024 

extern int connect_retry(int, const struct sockaddr*, socklen_t);

// void print_uptime(int sockfd)
// {
//     int n;
//     char buf[BUFLEN];
// 
//     while ((n = recv(sockfd, buf, BUFLEN, 0)) > 0)
//         write(STDOUT_FILENO, buf, n);
//     if (n < 0)
//         err_sys("recv error");
// }

void execmd(const int sockfd)
{
    char sendline[BUFLEN], recvline[BUFLEN];

    printf("alist> ");
    while (fgets(sendline, BUFLEN, stdin) != NULL)
    {
        write(sockfd, sendline, strlen(sendline));

        while (recv(sockfd, recvline, BUFLEN, 0) > 0)
            fputs(recvline, stdout);

        bzero(sendline, strlen(sendline));
        bzero(recvline, strlen(recvline));
        printf("\nalist> ");
    }
}

int main(int argc, char* argv[])
{
    // struct addrinfo* ailist;
    // struct addrinfo* aip;
    // struct addrinfo hint;
    int sockfd, err;

    if (argc != 2)
        err_quit("usage: ruptime hostname");
    // hint.ai_flags = 0;
    // hint.ai_family = 0;
    // hint.ai_socktype = SOCK_STREAM;
    // hint.ai_protocol = 0;
    // hint.ai_addrlen = 0;
    // hint.ai_canonname = NULL;
    // hint.ai_addr = NULL;
    // hint.ai_next = NULL;
    // if ((err = getaddrinfo(argv[1], "ruptime", &hint, &ailist)) != 0)
    //     err_quit("getaddrinfo error: %s", gai_strerror(err));
    // for (aip = ailist; aip != NULL; aip = aip->ai_next)
    // {

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        err = errno;
    struct sockaddr_in servaddr;
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(6121);
    inet_pton(AF_INET, argv[1], &servaddr.sin_addr);
    connect(sockfd, (struct sockaddr*) &servaddr, sizeof(servaddr));
    // if (connect_retry(sockfd, &servaddr, sizeof(servaddr)) < 0)
    // {
    //     err = errno;
    // }
    // else
    // {
    // print_uptime(sockfd);
    execmd(sockfd);
    exit(0);
    // }

    // }
    fprintf(stderr, "can't connect to %s: %s\n", argv[1], strerror(err));
    exit(0);
}
