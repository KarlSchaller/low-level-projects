/*
============================================================================
Name        : Karl Schaller
Date        : 09/22/2019
Course      : CIS2107 Comp Sys & Low-Level Program
Homework    : Lab 04 1D Arrays
Problem     : Design and implement functions to process 1D arrays
 ============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RND_MIN 0
#define RND_MAX 100
#define SIZE 40

void printArray(int array[], int size);
void fillArray(int array[], int size);
int findWithRange(int array[], int low, int high);
void reverseArray(int array[], int size);
void reverseIndices(int array[], int low, int high);
int findSequence(int array[], int size, int num1, int num2);

int main(void) {

	srand((unsigned)time(NULL));

	int array[SIZE] = {0};

	// printing array of zeros
	puts("\nOriginal array: ");
	printArray(array, SIZE);

	// printing array after fillArray()
	puts("\nArray after filling:");
	fillArray(array, SIZE);
	printArray(array, SIZE);

	// printing max in range 10 to 19 with findWithRange()
	printf("%s%d%s", "\nMax in range 10 to 19: ", findWithRange(array, 10, 19), "\n");

	// printing array after reverseArray()
	puts("\nArray after reversing:");
	reverseArray(array, SIZE);
	printArray(array, SIZE);

	// printing array after reversing from 10 to 19 with reverseIndices()
	puts("\nArray after reversing indices 10 to 19:");
	reverseIndices(array, 10, 19);
	printArray(array, SIZE);

	// asking for user input and running findSequence()
	puts("\nSequence search:");
	printf("%s", "Enter two numbers: ");
	int num1, num2;
	scanf("%d %d", &num1, &num2);
	int index = findSequence(array, SIZE, num1, num2);
	if (index == -1)
		puts("sequence not found");
	else
		printf("%s%d%s", "sequence found at index ", index, "\n\n");

	exit(0);
}

// prints a 1D array with 10 elements per row
void printArray(int array[], int size) {
	for (size_t i = 0; i < size; i++) {
		printf("%d%s", array[i], "\t");
		if (((i+1) % 10) == 0)
			puts("");
	}
}

// 1. fills a 1D array with random integers from 1 to 100
void fillArray(int array[], int size) {
	for (size_t i = 0; i < size; i++)
			array[i] = rand() % (RND_MAX+1) + RND_MIN;
}

// 2. located largest element in range of array
int findWithRange(int array[], int low, int high) {
	int max = array[low];
	low++;
	for (; low <= high; low++)
		if (array[low] > max)
			max = array[low];
	return max;
}

// 3. reverses the order of the array elements
void reverseArray(int array[], int size) {
	int temp;
	for (size_t i = 0; i < size/2; i++) {
		temp = array[i];
		array[i] = array[size-i-1];
		array[size-i-1] = temp;
	}
}

// 4. reverses the order of the array elements in a range between two indices. does nothing if high < low
void reverseIndices(int array[], int low, int high) {
	int temp;
	while (low < high) {
		temp = array[low];
		array[low] = array[high];
		array[high] = temp;
		low++;
		high--;
	}
}

// 5. looks for a sequence of two numbers among the array. returns index of first element or -1 if sequence not found
int findSequence(int array[], int size, int num1, int num2) {
	for (size_t i = 0; i < size-1; i++)
		if ((array[i] == num1) && (array[i+1] == num2))
				return i;
	return -1;
}
