// SPDX-License-Identifier: GPL-3.0-or-later
// SPDX-FileCopyrightText: 2024 kurth4cker <kurth4cker@gmail.com>

#include <stdlib.h>

#include <darray.h>

const size_t DEFAULT_CAPACITY = 16;

darray *
darray_new(void)
{
	darray *arr = malloc(sizeof(*arr));
	if (!arr)
		return NULL;
	arr->data = malloc(sizeof(*arr->data) * DEFAULT_CAPACITY);
	if (!arr->data) {
		free(arr);
		return NULL;
	}
	arr->size = 0;
	arr->capacity = DEFAULT_CAPACITY;
	return arr;
}

void
darray_free(darray *arr)
{
	free(arr->data);
	free(arr);
}
