/*
 * ptr_to.c
 *
 *  Created on: Nov 1, 2019
 *      Author: tui98107
 */

#include "my_string.h"

char *ptr_to(char *h, char *n) {
	while (*h != '\0') {
        int i = 0;
        while (*(h+i) == *(n+i)) {
            i++;
            if (*(n+i) == '\0')
                return h;
            if (*(h+i) == '\0')
                return NULL;
        }
        h++;
    }
    return NULL;
}
