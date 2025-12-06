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

void linsvector_init(struct linsvector *lv,
		char **arr, size_t arrmax,
		char *buf, size_t bufmax) {
	lv->arr = arr;
	lv->arrmax = arrmax;
	lv->arrlng = 0;
	lv->buf = buf;
	lv->bufmax = bufmax;
	lv->buflng = 0;
}

int linsvector_insert(struct linsvector *lv, const char *lin) {
	size_t lng;
	if (lv->arrlng + 1 > lv->arrmax)
		return -1;
	lng = strlen(lin);
	if (lv->buflng + lng + 1 > lv->bufmax)
		return -2;
	strcpy(lv->buf + lv->buflng, lin);
	lv->arr[lv->arrlng++] = lv->buf + lv->buflng;
	lv->buflng += lng + 1;
	return 0;
}

void linsvector_reduce(struct linsvector *lv, size_t arrlng) {
	if (lv->arrlng > arrlng) {
		lv->arrlng = arrlng;
		lv->buflng = (size_t) (lv->arr[arrlng] - lv->buf);
	}
}
