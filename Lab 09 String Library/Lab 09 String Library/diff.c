/*
 * diff.c
 *
 *  Created on: Nov 1, 2019
 *      Author: tui98107
 */

#include "my_string.h"

int diff(char *s1, char *s2) {
	int count = 0;
    while (*s1 != '\0') {
        if (*s2 == '\0') {
            while (*s1 != '\0') {
                count++;
                s1++;
            }
            break;
        }
        if (*s1 != *s2)
            count++;
        s1++;
        s2++;
    }
    while (*s2 != '\0') {
        count++;
        s2++;
    }
    return count;
}
