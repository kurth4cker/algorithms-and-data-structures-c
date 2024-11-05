// SPDX-License-Identifier: GPL-3.0-or-later
// SPDX-FileCopyrightText: 2024 kurth4cker <kurth4cker@gmail.com>

#include <stdlib.h>

#include <array.h>

array *
array_new_with_objsize(size_t size, size_t objsize)
{
	const size_t datasize = size * objsize;
	array *arr = malloc(sizeof(*arr) + datasize);
	if (!arr) {
		return NULL;
	}
	arr->size = size;
	return arr;
}
