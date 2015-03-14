#include "main.h"

using namespace std;

int algorithm[10][6];

int main()
{
    crearSoluciones();
    prepare_algorithms();
    connect_to_server();
    int option;
    read_answer();
    while (K){
        option = algorithm[N][K];
        if (option == COOL){
            //cool algorithm
        } else if (option == DECENT) {
        	decent_strategy(N,K);
        } else {
            simplestrategy(N,K);
        }
        read_answer();
    }

    close_connection();

    return 0;
}

void prepare_algorithms(){
    for (int n = 1; n <= 9; n++){
        for (int k = 1; k <= 5; k++){
            if (n == 1 || k == 1 || (k <= 3 && n <= 2) || (k == 2 && n == 3)){
                algorithm[n][k]=SIMPLE;
            } else if (k <= 3 || (k==4 && n <= 8) || (k == 5 && n <= 6)){
                algorithm[n][k]=DECENT;
            } else {
                algorithm[n][k]=COOL;
            }
        }
    }
}
