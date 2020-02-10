/*
 * replace.c
 *
 *  Created on: Nov 1, 2019
 *      Author: tui98107
 */

#include "my_string.h"

char *replace(char *s, char *pat, char *rep) {
	int len_s = 0, len_pat = 0, len_rep = 0, count = 0;
	for (; pat[len_pat] != '\0'; len_pat++);
	for (; rep[len_rep] != '\0'; len_rep++);
	for (; s[len_s] != '\0'; len_s++) {
	    if (s[len_s] == *pat) {
	        int i = 0;
	        for (; (s[len_s+i] != '\0') && (i < len_pat) && (s[len_s+i] == pat[i]); i++);
	        if (i == len_pat)
	            count++;
	    }
	}
	int len_new = len_s-(len_pat-len_rep)*count;
	char *new = malloc(len_new+1);
	for (int i = 0, j = 0; i < len_s; i++, j++) {
	    int k = 0;
	    for (; (s[i+k] != '\0') && (k < len_pat) && (s[i+k] == pat[k]); k++);
	    if (k == len_pat) {
	        for (k = 0; k < len_rep; k++)
	            new[j+k] = rep[k];
	        i += len_pat-1;
	        j += len_rep-1;
	    }
	    else
	        new[j] = s[i];
	}
	new[len_new] = '\0';
	return new;
}
