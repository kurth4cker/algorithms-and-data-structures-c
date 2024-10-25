// SPDX-License-Identifier: GPL-3.0-or-later
// SPDX-FileCopyrightText: 2024 kurth4cker <kurth4cker@gmail.com>

#include <stdlib.h>

#include <alist.h>

const size_t DEFAULT_CAPACITY = 16;

alist *
alist_new()
{
	alist *arr = malloc(sizeof(*arr));
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
alist_free(alist *arr)
{
	free(arr->data);
	free(arr);
}
