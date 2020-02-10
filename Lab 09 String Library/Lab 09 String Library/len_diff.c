/*
 * len_diff.c
 *
 *  Created on: Nov 1, 2019
 *      Author: tui98107
 */

#include "my_string.h"

int len_diff(char *s1, char *s2) {
	int len1 = 1, len2 = 1;
    while (*(++s1) != '\0')
        len1++;
    while (*(++s2) != '\0')
        len2++;
    return len1 - len2;
}
