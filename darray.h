#pragma once

#include <stddef.h>

typedef struct darray {
	size_t size, capacity;
	int *data;
} darray;

darray *darray_new(void);
void darray_free(darray *);
