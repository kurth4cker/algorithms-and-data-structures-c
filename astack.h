#pragma once

#include <stddef.h>
#include <stdbool.h>

extern const size_t ASTACK_DEFAULT_SIZE;

typedef struct astack {
	size_t size, count;
	int *sp;
	int *data;
} astack;

astack *astack_new(void);
astack *astack_new_with_size(size_t);
void astack_clear(astack *);
void astack_free(astack *);

bool astack_push(astack *, const int *);
bool astack_pop(astack *, int *);

#define astack_count(st)	((st)->count)
#define astack_size(st)		((st)->size)

#define astack_empty(st)	((st)->count == 0)
#define astack_full(st)		((st)->count == (st)->size)
