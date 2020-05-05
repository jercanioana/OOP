#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <string.h>

int main() {
    int c;
    struct sockaddr_in server;
    uint16_t cnt;
    u_char a[100];

    c = socket(AF_INET, SOCK_STREAM, 0);
    if (c < 0) {
        printf("Eroare la crearea socketului client\n");
        return 1;
    }

    memset(&server, 0, sizeof(server));
    server.sin_port = htons(1239);
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr("172.30.115.37");

    if (connect(c, (struct sockaddr *) &server, sizeof(server)) < 0) {
        printf("Eroare la conectarea la server\n");
        return 1;
    }

    printf("a = ");
    fgets(a, sizeof(a), stdin);
    send(c, &a, sizeof(a), 0);

    recv(c, &cnt, sizeof(cnt), 0);
    cnt = ntohs(cnt);
    printf("Suma este %hu\n", cnt);
    close(c);
}