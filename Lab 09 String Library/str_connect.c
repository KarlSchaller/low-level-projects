/*
 * str_connect.c
 *
 *  Created on: Nov 1, 2019
 *      Author: tui98107
 */

#include "my_string.h"

char *str_connect(char **strs, int n, char c) {
	int len_new = 0;
	for (int i = 0; i < n; i++, len_new++) {
	    for (int j = 0; strs[i][j] != '\0'; j++, len_new++);
	}
	len_new--;
	char *new = malloc(len_new+1);
	for (int i = 0, k = 0; i < n; i++, k++) {
	    for (int j = 0; strs[i][j] != '\0'; j++, k++)
	        new[k] = strs[i][j];
	    new[k] = c;
	}
	new[len_new] = '\0';
	return new;
}
