/*
 * capitalize.c
 *
 *  Created on: Nov 1, 2019
 *      Author: tui98107
 */

#include "my_string.h"

void capitalize(char *s) {
	int diff = 'A' - 'a';
    if (*s >= 'a' && *s <= 'z')
        *s += diff;
    s++;
    while (*s != '\0') {
        if ((*(s-1) == ' ' || *(s-1) == '\t' || *(s-1) == '\n' || *(s-1) == '\v' || *(s-1) == '\f' || *(s-1) == '\r') && *s >= 'a' && *s <= 'z')
            *s += diff;
        else if (*s >= 'A' && *s <= 'Z')
            *s -= diff;
        s++;
    }
}
