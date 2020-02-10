/*
 * rm_empties.c
 *
 *  Created on: Nov 1, 2019
 *      Author: tui98107
 */

#include "my_string.h"

void rm_empties(char **words) {
	while (*words != NULL) {
	    if (**words == '\0') {
	        for (int j = 0; words[j] != NULL; j++)
	            words[j] = words[j+1];
	    }
	    else
	        words++;
	}
}
