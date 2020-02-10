/*
 * rm_right_space.c
 *
 *  Created on: Nov 1, 2019
 *      Author: tui98107
 */

#include "my_string.h"

void rm_right_space(char *s) {
	int i = 0;
    while (s[i] != '\0')
        i++;
    while (s[i-1] == ' ' || s[i-1] == '\t' || s[i-1] == '\n' || s[i-1] == '\v' || s[i-1] == '\f' || s[i-1] == '\r')
        i--;
    s[i] = '\0';
}
