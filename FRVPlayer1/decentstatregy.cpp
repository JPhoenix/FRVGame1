#include "decentstrategy.h"

struct Color {
	unsigned char value;
	int amount;
};

Color colors[5];
int colorAmount[5];
unsigned char guess[5];
unsigned char answer[5];
int remaining;
unsigned char c;
int distinctColors;
int colorsLeft, currentPosition;
Color* currentColorIndex;
unsigned char currentColor, dummyColor;
int i;
Color tmpColor;

bool compare_color (const Color &a, const Color &b){
	return a.amount > b.amount;
}

void decent_strategy(int n, int k) {
	remaining = k;
	c = (unsigned char) n;
	distinctColors = 0;
	while (remaining && c-- != 1) {
		memset(guess, c, k);
		write(socket_desc, guess, k);
		read_answer();
		if (gR == k)
			return;
		if (gR) {
			tmpColor.value = c;
			tmpColor.amount = gR;
			colors[distinctColors++] = tmpColor;
			remaining -= gR;
		}
	}
	if (remaining) {
		tmpColor.value = 0;
		tmpColor.amount = remaining;
		colors[distinctColors++] = tmpColor;
	}
	colorsLeft = distinctColors-1;
	currentPosition = 0;

	while (colorsLeft) {
		currentColorIndex = colors;
		for (i = 0; i < colorsLeft; i+=2) {
			sort(colors,colors+distinctColors,compare_color);
			currentColor = currentColorIndex->value;
			dummyColor = (currentColorIndex+1)->value;
			memset(guess, dummyColor, k);
			guess[currentPosition] = currentColor;
			write(socket_desc, guess, k);
			read_answer();
			if (gR == k)
				return;
			if (!gN) {
				answer[currentPosition++] = currentColor;
				if (!(--(currentColorIndex->amount))) colorsLeft--;
				goto end;
			} else if (gN == 2) {
				answer[currentPosition++] = dummyColor;
				if (!(--((currentColorIndex+1)->amount))) colorsLeft--;
				goto end;
			}
			currentColorIndex+=2;
		}
		answer[currentPosition++] = (colors+colorsLeft)->value;
		if (!(--((colors+colorsLeft)->amount))) colorsLeft--;
		end: ;
	}
	sort(colors,colors+distinctColors,compare_color);
	memset(answer+currentPosition,colors->value,k-currentPosition);
	write(socket_desc, answer, k);
	read_answer();
}
