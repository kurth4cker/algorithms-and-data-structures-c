// SPDX-License-Identifier: GPL-3.0-or-later
// SPDX-FileCopyrightText: 2024 kurth4cker <kurth4cker@gmail.com>

#include <stdlib.h>

#include <array.h>

farray *
farray_new(size_t size)
{
	farray *arr = malloc(sizeof(*arr) + sizeof(*arr->data) * size);
	if (!arr)
		return NULL;
	arr->size = size;
	return arr;
}
