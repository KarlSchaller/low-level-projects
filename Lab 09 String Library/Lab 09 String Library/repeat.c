/*
 * repeat.c
 *
 *  Created on: Nov 1, 2019
 *      Author: tui98107
 */

#include "my_string.h"

char *repeat(char *s, int x, char sep) {
	if (s == NULL)
        return NULL;
    int i = 0;
    while (*(s + i) != '\0')
        i++;
    int j = (i+1)*x;
    char *new = malloc(j*sizeof(char));
    for (int k = 0; k < x-1; k++) {
        for (int l = 0; l < i; l++)
            *(new+i*k+l+k) = *(s+l);
        *(new+i*(k+1)+k) = sep;
    }
    for (int k = 0; k < i; k++)
        *(new+(i+1)*(x-1)+k) = *(s+k);
    *(new+j-1) = '\0';
    return new;
}
