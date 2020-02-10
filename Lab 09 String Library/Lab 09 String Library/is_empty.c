/*
 * is_empty.c
 *
 *  Created on: Nov 1, 2019
 *      Author: tui98107
 */

#include "my_string.h"

int is_empty(char *s) {
	if (s == NULL)
        return 1;
    while (*s != '\0') {
        if (!(*s == ' ' || *s == '\t' || *s == '\n' || *s == '\v' || *s == '\f' || *s == '\r'))
            return 0;
        s++;
    }
    return 1;
}
