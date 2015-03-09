#include "decentstrategy.h"

unsigned char colors[5];
int colorAmount[5];
unsigned char guess[5];
unsigned char answer[5];
int remaining;
unsigned char c;
int distinctColors;
int colorsLeft, currentPosition;
int currentColorIndex;
unsigned char currentColor, dummyColor;
int i;

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
			colors[distinctColors] = c;
			colorAmount[distinctColors++] = gR;
			remaining -= gR;
		}
	}
	if (remaining) {
		colors[distinctColors] = c;
		colorAmount[distinctColors++] = remaining;
	}
	colorsLeft = distinctColors;
	currentPosition = 0;
	while (colorsLeft != 1) {
		currentColorIndex = 0;
		for (i = 1; i < colorsLeft; i++) {
			while (!colorAmount[currentColorIndex])	currentColorIndex++;
			currentColor = colors[currentColorIndex];
			dummyColor = colors[currentColorIndex + 1];
			memset(guess, dummyColor, k);
			guess[currentPosition] = currentColor;
			write(socket_desc, guess, k);
			read_answer();
			if (gR == k)
				return;
			if (!gN) {
				answer[currentPosition++] = currentColor;
				if (!(--colorAmount[currentColorIndex])) colorsLeft--;
				goto end;
			} else if (gN == 2) {
				answer[currentPosition++] = dummyColor;
				if (!(--colorAmount[currentColorIndex + 1])) colorsLeft--;
				goto end;
			}
			currentColorIndex++;
		}
		while (!colorAmount[currentColorIndex])	currentColorIndex++;
		answer[currentPosition++] = colors[currentColorIndex];
		if (!(--colorAmount[currentColorIndex])) colorsLeft--;
		end: ;
	}
	currentColorIndex = 0;
	while (!colorAmount[currentColorIndex])	currentColorIndex++;
	while (currentPosition < k)	answer[currentPosition++] = colors[currentColorIndex];
	write(socket_desc, answer, k);
	read_answer();
}
