/*
============================================================================
Name        : Karl Schaller
Date        : 10/6/2019
Course      : CIS2107 Comp Sys & Low-Level Program
Homework    : Lab 06 Race
Problem     : Design and implement functions to process pointers for the race between the tortoise and hare
 ============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void moveTortoise(int *tortoise);
void moveHare(int *hare);
void printRace(int tortoise, int hare);

int main(void) {

	// initialization
	int tortoise = 1;
	int hare = 1;
	int speed = 1;
	srand((unsigned)time(NULL));

	// the race
	sleep(speed);
	puts("\nON YOUR MARK, GET SET");
	sleep(speed);
	puts("BANG\t\t\t!!!!");
	sleep(speed);
	puts("AND THEY'RE OFF\t\t!!!!");
	sleep(speed);
	while (tortoise < 70 && hare < 70) {
		moveTortoise(&tortoise);
		moveHare(&hare);
		printRace(tortoise, hare);
		sleep(speed);
	}

	// the results
	if (tortoise >= 70 && hare >= 70)
		puts("It's a tie.");
	else if (tortoise > hare)
		puts("TORTOISE WINS!!! YAY!!!");
	else
		puts("Hare wins. Yuch.");

	exit(0);
}

// randomly moves according to the rules of the tortoise
void moveTortoise(int *tortoise) {

	int temp = rand() % 10 + 1;

	if (temp <= 5) *tortoise += 3;
	else if (temp <= 7) *tortoise -= 6;
	else *tortoise += 1;

	if (*tortoise < 1)
		*tortoise = 1;
}

// randomly moves according to the rules of the hare
void moveHare(int *hare) {

	int temp = rand() % 10 + 1;

	if (temp <= 2);
	else if (temp <= 4) *hare += 9;
	else if (temp <= 5) *hare -= 12;
	else if (temp <= 8) *hare += 1;
	else *hare -= 2;

	if (*hare < 1)
		*hare = 1;
}

// prints the race line
void printRace(int tortoise, int hare) {
	if (tortoise == hare)
		printf("%*s", tortoise-1, "OUCH!!!\n");
	else if (tortoise < hare)
		printf("%*c%*s", tortoise-1, 'T', hare-tortoise-1, "H\n");
	else
		printf("%*c%*s", hare-1, 'H', tortoise-hare-1, "T\n");
}
