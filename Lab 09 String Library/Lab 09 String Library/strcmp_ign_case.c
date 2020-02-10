/*
 * strcmp_ign_case.c
 *
 *  Created on: Nov 1, 2019
 *      Author: tui98107
 */

#include "my_string.h"

int strcmp_ign_case(char *s1, char *s2) {
	int diff = 'A'-'a';
    while (*s1 != '\0' && *s2 != '\0') {
        char c1 = *s1;
        char c2 = *s2;
        if (c1 >= 'A' && c1 <= 'Z')
            c1 -= diff;
        if (c2 >= 'A' && c2 <= 'Z')
            c2 -= diff;
        if (c1 != c2)
            return c1-c2;
        s1++;
        s2++;
    }
    return *s1-*s2;
}
