#ifndef SOCKETUTILS_H
#define SOCKETUTILS_H

#include<sys/socket.h>
#include<arpa/inet.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

using namespace std;

extern unsigned char gR, gN;
extern int socket_desc;

void connect_to_server();
void close_connection();

inline void read_answer(){
    read(socket_desc,&gR,1);
    read(socket_desc,&gN,1);
}

inline void send_color(unsigned char color){
    write(socket_desc,&color,1);
}

#endif
