#pragma once

#include <stddef.h>
#include <stdlib.h>

struct array {
	size_t size;
	unsigned char data[];
};
typedef struct array array;

array *array_new_with_objsize(size_t size, size_t objsize);
#define array_new(size, type) array_new_with_objsize(size, sizeof(type))
