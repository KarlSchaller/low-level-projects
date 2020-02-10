/*
============================================================================
Name        : Karl Schaller
Date        : 09/29/2019
Course      : CIS2107 Comp Sys & Low-Level Program
Homework    : Lab 05 2DArrays & Pointers of Arrays to Functions
Problem     : Design and implement functions to process 2D arrays
 ============================================================================
*/

#include <stdio.h>
#include <stdlib.h>

int max(int rows, int cols, int array[][cols]);
int rowSum(int rows, int cols, int array[][cols], int whichRow);
int columnSum(int rows, int cols, int array[][cols], int whichCol);
int isSquare(int rows, int cols, int array[][cols]);
void displayOutputs(int rows, int cols, int array[][cols]);

int main(void) {

	puts("\nLet's create a 2Dim array!\n");

	// reading array size
	int rows, cols;
	printf("%s", "\tHow many rows? ");
	scanf("%u", &rows);
	printf("%s", "\tHow many columns? ");
	scanf("%u", &cols);
	puts("");

	// reading array elements
	int array[rows][cols];
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++) {
			printf("%s%d%s%d%s", "\tenter [", i, "][", j, "]: ");
			scanf("%d", &array[i][j]);
		}
	puts("");

	// printing max
	printf("%s%d%s", "Max of array = ", max(rows, cols, array), "\n\n");

	// printing row sums
	for (int i = 0; i < rows; i++)
		printf("%s%d%s%d%s", "Sum of row ", i+1, " = ", rowSum(rows, cols, array, i), "\n");
	puts("");

	// printing column sums
	for (int j = 0; j < cols; j++)
		printf("%s%d%s%d%s", "Sum of column ", j+1, " = ", columnSum(rows, cols, array, j), "\n");
	puts("");

	// printing is square?
	printf("%s%s%s", "This is ", isSquare(rows, cols, array)?"":"not ", "a square array.\n\n");

	// printing array
	puts("Here is your 2Dim array:");
	displayOutputs(rows, cols, array);

	exit(0);
}

// returns the maximum value in the 2d array
int max(int rows, int cols, int array[][cols]) {
	int maximum = array[0][0];
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			if (array[i][j] > maximum)
				maximum = array[i][j];
	return maximum;
}

// returns the sum of the elements in row whichRow of the 2d array
int rowSum(int row, int cols, int array[][cols], int whichRow) {
	int sum = 0;
	for (int j = 0; j < cols; j++)
		sum += array[whichRow][j];
	return sum;
}

// returns the sum of the elements in column whichCol of the 2d array
int columnSum(int rows, int cols, int array[][cols], int whichCol) {
	int sum = 0;
	for (int i = 0; i < rows; i++)
		sum += array[i][whichCol];
	return sum;
}

// checks if the array is a square
int isSquare(int rows, int cols, int array[][cols]) {
	return rows==cols;
}

// displays the 2 dim-array elements
void displayOutputs(int rows, int cols, int array[][cols]) {
	for (int i = 0; i < rows; i++) {
		printf("%s", "[");
		for (int j = 0; j < cols-1; j++)
			printf("%d%s", array[i][j], ", ");
		printf("%d%s", array[i][cols-1], "]\n");
	}
	puts("");
}
