#include <iostream>
#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>

using namespace std;

int main()
{
    struct sockaddr_in address;

    int socket_desc = socket(AF_INET, SOCK_STREAM, 0);

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr("127.0.0.1");
    address.sin_port = htons(8000);

    int result = connect(sockfd, (struct sockaddr *)&address, sizeof(address));

    if(result == -1)
    {
        perror("Fallo en la conexión\n");
        return 0;
    }
    else
    {
        printf("Se pudo conectar al servidor\n");
    }

    return 0;
}
