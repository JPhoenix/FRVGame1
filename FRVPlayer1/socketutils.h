#ifndef SOCKETUTILS_H
#define SOCKETUTILS_H

extern unsigned char gR, gN;

void connect_to_server();
inline void read_answer();
void close_connection();
inline void send_color(char color);

#endif
