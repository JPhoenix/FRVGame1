#include "simplestrategy.h"

unsigned char one_color[5];

void simplestrategy(int n, int k) {
	if (k == 1){
		while (n--){
			write(socket_desc,&n,1);
			read_answer();
			if (gR == k) {
				return;
			}
		}
	}
	if (n == 1){
		write(socket_desc,one_color,k);
		read_answer();
	}

}

