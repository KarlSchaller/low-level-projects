/*
============================================================================
Name        : Karl Schaller
Date        : 09/29/2019
Course      : CIS2107 Comp Sys & Low-Level Program
Homework    : Lab 05 2DArrays & Pointers of Arrays to Functions
Problem     : Design and implement array of function pointers
 ============================================================================
*/

#include <stdio.h>
#include <stdlib.h>

void minimum(size_t pupils, size_t tests, const int grades[][tests]);
void maximum(size_t pupils, size_t tests, const int grades[][tests]);
void average(size_t pupils, size_t tests, const int grades[][tests]);
void printArray(size_t pupils, size_t tests, const int grades[][tests]);

int main(void) {

	// reading numbers of students and exams
	size_t students, exams;
	printf("%s", "\n\tHow many students? ");
	scanf("%lu", &students);
	printf("%s", "\tHow many exams? ");
	scanf("%lu", &exams);
	puts("");

	// reading grades
	int studentGrades[students][exams];
	for (int i = 0; i < students; i++)
		for (int j = 0; j < exams; j++) {
			printf("%s%d%s%d%s", "\tEnter grade for student [", i, "] test [", j, "]: ");
			scanf("%d", &studentGrades[i][j]);
		}
	puts("");

	// menu-driven interface
	void (*processGrades[4])(size_t pupils, size_t tests, const int grades[][tests]) = { printArray, minimum, maximum, average };
	int choice;
	while (1) {
		puts("\nEnter a choice:");
		puts("\t0 Print the array of grades");
		puts("\t1 Find the minimum grade");
		puts("\t2 Find the maximum grade");
		puts("\t3 Print the average on all tests for each student");
		puts("\t4 End Program");
		scanf("%d", &choice);
		puts("");
		if (choice >= 0 && choice <= 3)
			(*processGrades[choice])(students, exams, studentGrades);
		else if (choice == 4)
			exit(0);
		else
			puts("Please enter a valid number.");
	}
}

// Find the minimum grade
void minimum(size_t pupils, size_t tests, const int grades[][tests]) {
	int lowGrade = 100;
	for (size_t i = 0; i < pupils; ++i)
		for (size_t j = 0; j < tests; ++j)
			if (grades[i][j] < lowGrade)
				lowGrade = grades[i][j];
	printf("%s%d%s", "Lowest grade: ", lowGrade, "\n");
}

// Find the maximum grade
void maximum(size_t pupils, size_t tests, const int grades[][tests]) {
	int highGrade = 100;
	for (size_t i = 0; i < pupils; ++i)
		for (size_t j = 0; j < tests; ++j)
			if (grades[i][j] > highGrade)
				highGrade = grades[i][j];
	printf("%s%d%s", "Highest grade: ", highGrade, "\n");
}

// Determine the average grade for a particular student
void average(size_t pupils, size_t tests, const int grades[][tests]) {
	for (size_t i = 0; i < pupils; ++i) {
		int total = 0;
		for (size_t j = 0; j < tests; ++j)
			total += grades[i][j];
		printf("%s%lu%s%.2f%s", "The average grade for student ", i, " is ", (double)total/tests, "\n");
	}
}

// Print the array of grades
void printArray(size_t pupils, size_t tests, const int grades[][tests]) {
	puts("The array is:");
	printf("%s", "\t\t");
	for (size_t j = 0; j < tests; j++)
		printf("%s%lu%s", "\t[", j, "]");
	puts("");
	for (size_t i = 0; i < pupils; ++i) {
		printf("%s%lu%s", "studentGrades[", i, "]\t");
		for (size_t j = 0; j < tests; ++j)
			printf("%d%s", grades[i][j], "\t");
		puts("");
	}
}
