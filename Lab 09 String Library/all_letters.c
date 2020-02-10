/*
 * all_letters.c
 *
 *  Created on: Nov 1, 2019
 *      Author: tui98107
 */

#include "my_string.h"

int all_letters(char *s) {
	int upper;
    if (*s >= 'A' && *s <= 'Z')
        upper = 1;
    else if (*s >= 'a' && *s <= 'z')
        upper = 0;
    else
        return 0;
    
    while (*(++s) != '\0') {
        if (*s >= 'A' && *s <= 'Z') {
            if (!upper)
                return 0;
        }
        else if (*s >= 'a' && *s <= 'z') {
            if (upper)
                return 0;
        }
        else
            return 0;
    }
    return 1;
}
