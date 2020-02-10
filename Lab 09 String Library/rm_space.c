/*
 * rm_space.c
 *
 *  Created on: Nov 1, 2019
 *      Author: tui98107
 */

#include "my_string.h"

void rm_space(char *s) {
	rm_right_space(s);
	rm_left_space(s);
}
