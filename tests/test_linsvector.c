/*
   linsvector implements a simple fixed-size array of strings in C.
   Copyright (C) 2025 Carlos Rica Espinosa <jasampler@gmail.com>

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, see <https://www.gnu.org/licenses/>.
*/

#include "linsvector.h"
#include <assert.h>

#define LNVEC_MAXARR 5
#define LNVEC_MAXBUF 15

int main(void) {
	struct linsvector lnvec;
	char *lnvec_arr[LNVEC_MAXARR];
	char lnvec_buf[LNVEC_MAXBUF];

	linsvector_init(&lnvec,
			lnvec_arr, LNVEC_MAXARR,
			lnvec_buf, LNVEC_MAXBUF);
	assert(lnvec.buflng == 0);
	assert(lnvec.arrlng == 0);

	assert(linsvector_insert(&lnvec, "aaaa") == 0);
	assert(lnvec.arrlng == 1);
	assert(lnvec.buflng == 5);
	assert(strcmp(lnvec.arr[0], "aaaa") == 0);

	assert(linsvector_insert(&lnvec, "bb") == 0);
	assert(lnvec.arrlng == 2);
	assert(lnvec.buflng == 8);
	assert(strcmp(lnvec.arr[0], "aaaa") == 0);
	assert(strcmp(lnvec.arr[1], "bb") == 0);

	assert(linsvector_insert(&lnvec, "c") == 0);
	assert(lnvec.arrlng == 3);
	assert(lnvec.buflng == 10);
	assert(strcmp(lnvec.arr[0], "aaaa") == 0);
	assert(strcmp(lnvec.arr[1], "bb") == 0);
	assert(strcmp(lnvec.arr[2], "c") == 0);

	assert(linsvector_insert(&lnvec, "") == 0);
	assert(lnvec.arrlng == 4);
	assert(lnvec.buflng == 11);
	assert(strcmp(lnvec.arr[0], "aaaa") == 0);
	assert(strcmp(lnvec.arr[1], "bb") == 0);
	assert(strcmp(lnvec.arr[2], "c") == 0);
	assert(strcmp(lnvec.arr[3], "") == 0);

	assert(linsvector_insert(&lnvec, "dddd") == -2);
	assert(lnvec.arrlng == 4);
	assert(lnvec.buflng == 11);
	assert(strcmp(lnvec.arr[0], "aaaa") == 0);
	assert(strcmp(lnvec.arr[1], "bb") == 0);
	assert(strcmp(lnvec.arr[2], "c") == 0);
	assert(strcmp(lnvec.arr[3], "") == 0);

	assert(linsvector_insert(&lnvec, "e") == 0);
	assert(lnvec.arrlng == 5);
	assert(lnvec.buflng == 13);
	assert(strcmp(lnvec.arr[0], "aaaa") == 0);
	assert(strcmp(lnvec.arr[1], "bb") == 0);
	assert(strcmp(lnvec.arr[2], "c") == 0);
	assert(strcmp(lnvec.arr[3], "") == 0);
	assert(strcmp(lnvec.arr[4], "e") == 0);

	assert(linsvector_insert(&lnvec, "ff") == -1);
	assert(lnvec.arrlng == 5);
	assert(lnvec.buflng == 13);
	assert(strcmp(lnvec.arr[0], "aaaa") == 0);
	assert(strcmp(lnvec.arr[1], "bb") == 0);
	assert(strcmp(lnvec.arr[2], "c") == 0);
	assert(strcmp(lnvec.arr[3], "") == 0);
	assert(strcmp(lnvec.arr[4], "e") == 0);

	assert(linsvector_insert(&lnvec, "g") == -1);
	assert(lnvec.arrlng == 5);
	assert(lnvec.buflng == 13);
	assert(strcmp(lnvec.arr[0], "aaaa") == 0);
	assert(strcmp(lnvec.arr[1], "bb") == 0);
	assert(strcmp(lnvec.arr[2], "c") == 0);
	assert(strcmp(lnvec.arr[3], "") == 0);
	assert(strcmp(lnvec.arr[4], "e") == 0);

	assert(linsvector_insert(&lnvec, "") == -1);
	assert(lnvec.arrlng == 5);
	assert(lnvec.buflng == 13);
	assert(strcmp(lnvec.arr[0], "aaaa") == 0);
	assert(strcmp(lnvec.arr[1], "bb") == 0);
	assert(strcmp(lnvec.arr[2], "c") == 0);
	assert(strcmp(lnvec.arr[3], "") == 0);
	assert(strcmp(lnvec.arr[4], "e") == 0);

	linsvector_reduce(&lnvec, 6);
	assert(lnvec.arrlng == 5);
	assert(lnvec.buflng == 13);
	assert(strcmp(lnvec.arr[0], "aaaa") == 0);
	assert(strcmp(lnvec.arr[1], "bb") == 0);
	assert(strcmp(lnvec.arr[2], "c") == 0);
	assert(strcmp(lnvec.arr[3], "") == 0);
	assert(strcmp(lnvec.arr[4], "e") == 0);

	linsvector_reduce(&lnvec, 5);
	assert(lnvec.arrlng == 5);
	assert(lnvec.buflng == 13);
	assert(strcmp(lnvec.arr[0], "aaaa") == 0);
	assert(strcmp(lnvec.arr[1], "bb") == 0);
	assert(strcmp(lnvec.arr[2], "c") == 0);
	assert(strcmp(lnvec.arr[3], "") == 0);
	assert(strcmp(lnvec.arr[4], "e") == 0);

	linsvector_reduce(&lnvec, 4);
	assert(lnvec.arrlng == 4);
	assert(lnvec.buflng == 11);
	assert(strcmp(lnvec.arr[0], "aaaa") == 0);
	assert(strcmp(lnvec.arr[1], "bb") == 0);
	assert(strcmp(lnvec.arr[2], "c") == 0);
	assert(strcmp(lnvec.arr[3], "") == 0);

	assert(linsvector_insert(&lnvec, "iiiii") == -2);
	assert(lnvec.arrlng == 4);
	assert(lnvec.buflng == 11);
	assert(strcmp(lnvec.arr[0], "aaaa") == 0);
	assert(strcmp(lnvec.arr[1], "bb") == 0);
	assert(strcmp(lnvec.arr[2], "c") == 0);
	assert(strcmp(lnvec.arr[3], "") == 0);

	assert(linsvector_insert(&lnvec, "jjjj") == -2);
	assert(lnvec.arrlng == 4);
	assert(lnvec.buflng == 11);
	assert(strcmp(lnvec.arr[0], "aaaa") == 0);
	assert(strcmp(lnvec.arr[1], "bb") == 0);
	assert(strcmp(lnvec.arr[2], "c") == 0);
	assert(strcmp(lnvec.arr[3], "") == 0);

	assert(linsvector_insert(&lnvec, "kkk") == 0);
	assert(lnvec.arrlng == 5);
	assert(lnvec.buflng == 15);
	assert(strcmp(lnvec.arr[0], "aaaa") == 0);
	assert(strcmp(lnvec.arr[1], "bb") == 0);
	assert(strcmp(lnvec.arr[2], "c") == 0);
	assert(strcmp(lnvec.arr[3], "") == 0);
	assert(strcmp(lnvec.arr[4], "kkk") == 0);

	linsvector_reduce(&lnvec, 2);
	assert(lnvec.arrlng == 2);
	assert(lnvec.buflng == 8);
	assert(strcmp(lnvec.arr[0], "aaaa") == 0);
	assert(strcmp(lnvec.arr[1], "bb") == 0);

	linsvector_reduce(&lnvec, 0);
	assert(lnvec.buflng == 0);
	assert(lnvec.arrlng == 0);

	return 0;
}
