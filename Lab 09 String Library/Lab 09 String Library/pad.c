/*
 * pad.c
 *
 *  Created on: Nov 1, 2019
 *      Author: tui98107
 */

#include "my_string.h"

char *pad(char *s, int d) {
	if (s == NULL)
        return NULL;
    int i = 0;
    while (*(s + i) != '\0')
        i++;
    int j = i+(d-i%d)+1;
    char *new = malloc(j*sizeof(char));
    for (int k = 0; k < i; k++)
        *(new+k) = *(s+k);
    for (int k = i; k < j-1; k++)
        *(new+k) = ' ';
    *(new+j-1) = '\0';
    return new;
}
