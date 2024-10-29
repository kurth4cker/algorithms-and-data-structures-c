#pragma once

#include <stddef.h>
#include <stdlib.h>

typedef struct farray {
	size_t size;
	int data[];
} farray;

farray *farray_new(size_t);
#define farray_clear(arr)		((arr)->size = 0)
#define farray_free(arr)		(free(arr))

#define farray_get(arr, idx)		((arr)->data[idx])
#define farray_set(arr, idx, val)	((arr)->data[idx] = (val))
#define farray_size(arr)		((arr)->size)
