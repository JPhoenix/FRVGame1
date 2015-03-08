#include "decentstrategy.h"

void decent_strategy(int n, int k){

    int remaining = k;
    unsigned char colors[] = {20,20,20,20,20};
    int colorAmount[] = {0,0,0,0,0,0,0,0,0};
    unsigned char c = (unsigned char)n;
    int index = 0;
    while (remaining && c-- != 1){
        repeat(k,c);
        read_answer();
        if (gR == k) return;
        int sum = gR + gN;
        if (sum){
            colors[index]=c;
            colorAmount[c]=sum;
            index++;
            remaining-=sum;
        }
    }
    if (remaining){
        colors[index]=c;
        colorAmount[c]=remaining;
        index++;
    }
    int colorsLeft = index;
    int currentPosition = 0;
    int currentColorIndex = 0;
    while (colorsLeft != 1){
        for (int i = 1; i < colorsLeft; i++){
            while (!colorAmount[currentColorIndex])currentColorIndex++;
            char dummyColor = (currentColorIndex+1)%k;
            for (int j = 0; j < currentPosition; j++) send_color(dummyColor);
            send_color(colors[currentColorIndex]);
        }
    }
}

inline void repeat(int k, char color){
    while (k--) send_color(color);
}
