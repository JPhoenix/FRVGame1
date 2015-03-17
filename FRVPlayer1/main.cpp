#include "main.h"

using namespace std;

int main()
{
    connect_to_server();
    read_answer();
    while (K){
        if (N != 1 && K != 1){
        	decent_strategy(N,K);
        } else {
        	simplestrategy(N,K);
        }
        read_answer();
    }
    close_connection();
    return 0;
}
