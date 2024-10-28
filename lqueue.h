#pragma once

#include <stdbool.h>
#include <stddef.h>

#include <slist.h>

typedef struct lqueue {
	snode *head, *tail;
	size_t count;
} lqueue;

lqueue *lqueue_new(void);
void lqueue_clear(lqueue *);
void lqueue_free(lqueue *);

bool lqueue_put(lqueue *, const int *);
bool lqueue_get(lqueue *, int *);

#define lqueue_count(qe)	((qe)->count)
#define lqueue_isempty(qe)	((qe)->count == 0)
