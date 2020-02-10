/*
 * rm_left_space.c
 *
 *  Created on: Nov 1, 2019
 *      Author: tui98107
 */

#include "my_string.h"

void rm_left_space(char *s) {
	int i = 0;
    while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n' || s[i] == '\v' || s[i] == '\f' || s[i] == '\r')
        i++;
    int j = 0;
    for (; s[i+j] != '\0'; j++)
        s[j] = s[i+j];
    s[j] = '\0';
}
