/*
 * str_zip.c
 *
 *  Created on: Nov 1, 2019
 *      Author: tui98107
 */

#include "my_string.h"

char *str_zip(char *s1, char *s2) {
	//	INCOMPLETE
	int len1 = 0, len2 = 0;
    while (*s1 != '\0') {
        len1++;
        s1++;
    }
    while (*s2 != '\0') {
        len2++;
        s2++;
    }
    char new[len1+len2+1] = {'\0'};
    s1 -= len1;
    s2 -= len2;
    int i = 0;
    while (*s1 != '\0') {
        new[i++] = *s1;
        s1++;
        if (*s2 == '\0') {
            while (*s1 != '\0') {
                new[i++] = *s1;
                s1++;
            }
            break;
        }
        new[i++] = *s2;
        s2++;
    }
    while (*s2 != '\0') {
        new[i++] = *s2;
        s2++;
    }
    return new;
}
