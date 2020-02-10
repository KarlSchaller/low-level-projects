/*
 * dedup.c
 *
 *  Created on: Nov 1, 2019
 *      Author: tui98107
 */

#include "my_string.h"

char *dedup(char *s) {
	int i = 0;
    while (*(s+i) != '\0')
        i++;
    char *new = malloc((i+1)*sizeof(char));
    i = 0;
    while (*s != '\0') {
        char c[2] = {*s, '\0'};
        if (find(new, c) == -1) {
            *(new+i) = *s;
            i++;
        }
        s++;
    }
    *(new+i) = '\0';
    new = realloc(new, (i+1)*sizeof(char));
    return new;
}
