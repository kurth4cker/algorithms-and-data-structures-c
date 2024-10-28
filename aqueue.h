#pragma once

#include <stdbool.h>
#include <stddef.h>

typedef struct aqueue {
	size_t head, tail;
	size_t capacity, count;
	int *data;
} aqueue;

aqueue *aqueue_new(size_t);
void aqueue_clear(aqueue *);
void aqueue_free(aqueue *);

bool aqueue_put(aqueue *, const int *);
bool aqueue_get(aqueue *, int *);

#define aqueue_count(qe)		((qe)->count)
#define aqueue_capacity(qe)	((qe)->capacity)
#define aqueue_isempty(qe)	((qe)->count == 0)
#define aqueue_isfull(qe)	((qe)->count == (qe)->capacity)
