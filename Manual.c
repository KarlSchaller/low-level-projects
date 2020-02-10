/*
 * Name:	Karl Schaller
 * Section: 03
 * Date:	10/28/2019
 * Lab:  	CIS2107_Lab07_Manual 
 * Goal: 	To design and implement functions to process characters and strings.
 */


#include <stdio.h>
#include <memory.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//functions
void * upperLower(const char * s);
int convertStrtoInt(const char *s1, const char *s2, const char *s3, const char *s4);
float convertStrtoFloat(const char *s1, const char *s2, const char *s3, const char *s4);
void compareStr(const char *s1, const char *s2);
void comparePartialStr(const char *s1, const char *s2, int n);
void randomize(void);
int tokenizeTelNum(char *num);
void reverse(char *text);
int countSubstr (char * line, char * sub);
int countChar (char * line, char c);
int countWords(char *string);
void countAlpha(char *string);
void startsWithB(char *string[], int size);
void endsWithed(char *string[], int size);

int main() {

    //random generator
    srand(time(NULL));

    //test for upperLower
    const char test[] = "This iS A Test";
    upperLower(test);

    //test for convertStrtoInt
    printf("\nThe sum of 4 strings is: %d", convertStrtoInt("3", "4", "5", "6"));

    //test for convertStrtoFloat
    printf("\n\nThe sum of 4 strings is: %.2f\n\n", convertStrtoFloat("3.5", "4.5", "5.5", "6.5"));

    //test for compareStr
    compareStr("Test1", "Test2");
    puts("");

    //test for comparePartialStr
    comparePartialStr("Test1", "Test2", 4);
    puts("");

    //test for randomize
    randomize();

    //test for tokenize number
    char str[] = "(267) 436-6281";
    puts("");
    tokenizeTelNum(str);

    //test for reverse
    char line[] = "Hello world";
    puts("");
    reverse(line);

    //test for countSubstr
    char *line1 = "helloworldworld";
    char *substring = "world";
    printf("\n\nNumber of Substrings %s inside %s: %d\n", substring, line1, countSubstr(line1, substring));

    //test for countChar
    char w = 'w';
    printf("\nNumber of character %c inside %s: %d\n\n", w, line1, countChar(line1, w));

    //test for countAlpha
    char str1[] = "Hello it's me.";
    countAlpha(str1);

    //test for countWords
    char countstring[] = "hello world!";
    printf("\nNumber of words in string is: %d\n\n", countWords(countstring));

    //test for startsWithB
    char *series[] = {"bored", "hello", "Brother", "manual", "bothered"};
	int size = sizeof(series) / sizeof(series[0]);
    startsWithB(series, size);
    puts("");

    //test for endsWithed
    endsWithed(series, size);

}

// 1.(Displaying Strings in Uppercase and Lowercase) 
void * upperLower (const char * s) {
    int count = 0;
	while (*s != '\0') {
    	printf("%c", toupper(*s));
    	s++;
    	count++;
    }
	s -= count;
	puts("");
	while (*s != '\0') {
		printf("%c", tolower(*s));
	    s++;
	}
	puts("");
}

// 2.(Converting Strings to Integers for Calculations) 
int convertStrtoInt(const char *s1, const char *s2, const char *s3, const char *s4) {
    return atoi(s1) + atoi(s2) + atoi(s3) + atoi(s4);
}

//3.(Converting Strings to Floating Point for Calculations) 
float convertStrtoFloat(const char *s1, const char *s2, const char *s3, const char *s4) {
	return atof(s1) + atof(s2) + atof(s3) + atof(s4);
}

//4.(Comparing Strings) 
void compareStr(const char *s1, const char *s2) {
    if (strcmp(s1, s2) > 0)
    	printf("%s > %s\n", s1, s2);
    else if (strcmp(s1, s2) < 0)
    	printf("%s < %s\n", s1, s2);
    else
    	printf("%s = %s\n", s1, s2);
}

//5.(Comparing Portions of Strings) 
void comparePartialStr(const char *s1, const char *s2, int n) {
	printf("Comparison of the first %d chars: ", n);
	if (strncmp(s1, s2, n) > 0)
    	printf("%s > %s\n", s1, s2);
    else if (strncmp(s1, s2, n) < 0)
    	printf("%s < %s\n", s1, s2);
    else
    	printf("%s = %s\n", s1, s2);
}

//6.(Random Sentences) 
void randomize(void) {
   char *article[] = {"the", "a", "one", "some", "any"};
   char *noun[] = {"boy", "girl", "dog", "town", "car"};
   char *verb[] = {"drove", "jumped", "ran", "walked", "skipped"};
   char *preposition[] = {"to", "from", "over", "under", "on"};
   for (int i = 0; i < 20; i++) {
	   char *word = article[rand() % 5];
	   printf("%c", toupper(*word));
	   while (*(++word) != '\0')
		   printf("%c", *word);
	   word = noun[rand() % 5];
	   printf(" %s ", word);
	   word = verb[rand() % 5];
	   printf("%s ", word);
	   word = preposition[rand() % 5];
	   printf("%s ", word);
	   word = article[rand() % 5];
	   printf("%s ", word);
	   word = noun[rand() % 5];
	   printf("%s.\n", word);
   }
}

//7.(Tokenizing Telephone Numbers) 
int tokenizeTelNum(char *num) {
	char *str = strtok(num, "()");
    int areacode = atoi(str);
    printf("%d ", areacode);

    str = strtok(NULL, " -");
    sprintf(str, "%s%s", str, strtok(NULL, "-"));
    long number = atol(str);
    printf("%ld\n", number);
    return 0;
}

//8.(Displaying a Sentence with Its Words Reversed) 
void reverse(char *text) {
    int length = strlen(text);
    char reverse[length];
	char *token = strtok(text, " ");
    while (token) {
        char new[length];
        sprintf(new, "%s %s", token, reverse);
        strcpy(reverse, new);
    	token = strtok(NULL, " ");
    }
	printf("%s", reverse);
}

//9.(Counting the Occurrences of a Substring) 
int countSubstr (char * line, char * sub) {
	int count = 0;
	while (line = strstr(line, sub)) {
		line++;
		count++;
	}
	return count;
}

//10.(Counting the Occurrences of a Character) 
int countChar (char *line, char c) {
	int count = 0;
	while (line = strchr(line, c)) {
		line++;
		count++;
	}
	return count;
}


//11.(Counting the Letters of the Alphabet in a String) 
void countAlpha(char *string) {
	int totals[26];
	for (char c = 'a'; c <= 'z'; c++) {
		totals[c-'a'] = countChar(string, c) + countChar(string, toupper(c));
		printf("%c,%c | %d\n", toupper(c), c, totals[c-'a']);
	}
}

//12.(Counting the Number of Words in a String) 
int countWords(char *string) {
	strtok(string, " ");
	int count = 1;
	while (strtok(NULL, " "))
		count++;
	return count;
}

//13.(Strings Starting with "b") 
void startsWithB(char *string[], int size) {
	for (int i = 0; i < size; i++)
		if (tolower(*(string[i])) == 'b')
			printf("%s ", string[i]);
	puts("");
}

//14.(Strings Ending with "ed")
void endsWithed(char *string[], int size) {
	for (int i = 0; i < size; i++)
		if (*(string[i]+strlen(string[i]) - 2*sizeof(char)) == 'e' && *(string[i]+strlen(string[i]) - 1*sizeof(char)) == 'd')
			printf("%s ", string[i]);
	puts("");
}