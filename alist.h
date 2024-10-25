#pragma once

#include <stddef.h>

typedef struct alist {
	size_t size, capacity;
	int *data;
} alist;

alist *alist_new(void);
void alist_free(alist *);
