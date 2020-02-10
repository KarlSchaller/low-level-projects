/*
 * shorten.c
 *
 *  Created on: Nov 1, 2019
 *      Author: tui98107
 */

#include "my_string.h"

void shorten(char *s, int new_len) {
	int len = 0;
    while (*(s+len) != '\0')
        len++;
    if (new_len < len)
        *(s+new_len) = '\0';
}
