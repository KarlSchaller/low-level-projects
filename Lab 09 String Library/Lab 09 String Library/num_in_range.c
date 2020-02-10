/*
 * num_in_range.c
 *
 *  Created on: Nov 1, 2019
 *      Author: tui98107
 */

#include "my_string.h"

int num_in_range(char *s1, char b, char t); {
	int count = 0;
    do {
        if (*s1 >= b && *s1 <= t)
            count++;
    } while (*(++s1) != '\0');
    return count;
}
