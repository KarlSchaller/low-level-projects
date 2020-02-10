/*
 * str_chop_all.c
 *
 *  Created on: Nov 1, 2019
 *      Author: tui98107
 */

#include "my_string.h"

char **str_chop_all(char *s, char c) {
	int tokens = 1;
	for (int i = 0; s[i] != '\0'; i++) {
	    if (s[i] == c)
	        tokens++;
	}
	char **new = malloc((tokens+1)*sizeof(char *));
	for (int token = 0, i = 0; token < tokens; token++, i++) {
	    int len_token = 0;
	    for (; (s[i+len_token] != '\0') && (s[i+len_token] != c); len_token++);
	    new[token] = malloc(len_token+1);
	    for (int j = 0; j < len_token; i++, j++)
	        new[token][j] = s[i];
	    new[token][len_token] = '\0';
	}
	new[tokens] = NULL;
	return new;
}
