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

#ifndef LINSVECTOR_H
#define LINSVECTOR_H

#include <string.h>

/*  _ _ _ _ __ __
 * |*|5|3|*|15|10|
 *  |     |
 *  |     |buf   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
 *  |     '---->|a|a|a|a|0|b|b|0|c|0|_|_|_|_|_|
 *  |arr         ^         ^     ^
 *  v            |         |     |
 * |*|-----------'         |     |
 * |*|---------------------'     |
 * |*|---------------------------'
 * |_|
 * |_|
 */
struct linsvector {
	char **arr;
	size_t arrmax, arrlng;
	char *buf;
	size_t bufmax, buflng;
};

void linsvector_init(struct linsvector *lv,
		char **arr, size_t arrmax,
		char *buf, size_t bufmax);

int linsvector_insert(struct linsvector *lv, const char *lin);

void linsvector_reduce(struct linsvector *lv, size_t arrlng);

#endif
