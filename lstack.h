#pragma once

#include <stddef.h>
#include <stdbool.h>
#include <slist.h>

typedef struct lstack {
	snode *head;
	size_t count;
} lstack;

lstack *lstack_new(void);
void lstack_clear(lstack *);
void lstack_free(lstack *);

bool lstack_push(lstack *, const int *);
bool lstack_pop(lstack *, int *);

#define lstack_count(st)	((st)->count)
#define lstack_empty(st)	((st)->count == 0)
