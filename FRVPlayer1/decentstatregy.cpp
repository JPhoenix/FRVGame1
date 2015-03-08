#include "decentstrategy.h"

void decent_strategy(int n, int k){
    int remaining = k;
    unsigned char colors[] = {20,20,20,20,20};
    int colorAmount[] = {0,0,0,0,0,0,0,0,0};
    unsigned char answer[] = {0,0,0,0,0};
    unsigned char c = (unsigned char)n;
    int index = 0;
    while (remaining && c-- != 1){
        repeat(k,c);
        read_answer();
        if (gR == k) return;
        if (gR){
            colors[index]=c;
            colorAmount[c]=gR;
            index++;
            remaining-=gR;
        }
    }
    if (remaining){
        colors[index]=c;
        colorAmount[c]=remaining;
        index++;
    }
    int colorsLeft = index;
    int currentPosition = 0;
    while (colorsLeft != 1){
    	int currentColorIndex = 0;
    	bool found = false;
        for (int i = 1; i < colorsLeft; i++){
            while (!colorAmount[colors[currentColorIndex]])currentColorIndex++;
            unsigned char dummyColor = colors[(currentColorIndex+1)%k];
            for (int j = 0; j < currentPosition; j++) send_color(dummyColor);
            send_color(colors[currentColorIndex]);
            for (int j = currentPosition+1; j < k; j++) send_color(dummyColor);
            read_answer();
            if (gR == k) return;
            if (!gN){
            	answer[currentPosition++]=colors[currentColorIndex];
            	if (! (--colorAmount[colors[currentColorIndex]])){
            		colorsLeft--;
            	}
            	found = true;
            	break;
            } //Could be added a deduction considering gN = 2.
            currentColorIndex++;
        }
        if (! found){
        	while (!colorAmount[colors[currentColorIndex]])currentColorIndex++;
        	answer[currentPosition++]=colors[currentColorIndex];
        	if (! (--colorAmount[colors[currentColorIndex]])){
				colorsLeft--;
			}
        }
    }
    int currentColorIndex = 0;
    while (!colorAmount[colors[currentColorIndex]])currentColorIndex++;
    while (currentPosition<k) answer[currentPosition++]=colors[currentColorIndex];
    write(socket_desc,answer,k);
    read_answer();
}

inline void repeat(int k, char color){
    while (k--) send_color(color);
}
