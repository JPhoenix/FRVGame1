#include "socketutils.h"

char unsigned gR, gN;

int socket_desc;
struct sockaddr_in address;



void connect_to_server(){
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr("127.0.0.1");
    address.sin_port = htons(8000);

    connect(socket_desc, (struct sockaddr *)&address, sizeof(address));

    char id = 0x3B;
    write(socket_desc,&id,1);

}

void close_connection(){
    close(socket_desc);
}
