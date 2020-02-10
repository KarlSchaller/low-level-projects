/*
 * find.c
 *
 *  Created on: Nov 1, 2019
 *      Author: tui98107
 */

#include "my_string.h"

int find(char *h, char *n) {
	char *orig = h;
    while (*h != '\0') {
        int i = 0;
        while (*(h+i) == *(n+i)) {
            i++;
            if (*(n+i) == '\0')
                return h-orig;
            if (*(h+i) == '\0')
                return -1;
        }
        h++;
    }
    return -1;
}
