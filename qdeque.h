#pragma once

#include <stdbool.h>
#include <stddef.h>

typedef struct qdeque {
	size_t head, tail;
	size_t capacity, size;
	int *data;
} qdeque;

qdeque *qdeque_new(void);
qdeque *qdeque_new_with_capacity(size_t);
void qdeque_clear(qdeque *);
void qdeque_free(qdeque *);

bool qdeque_set_capacity(qdeque *, size_t);

bool qdeque_add_head(qdeque *, const int *);
bool qdeque_add_tail(qdeque *, const int *);

void qdeque_get(const qdeque *, size_t, int *);

#define qdeque_size(dq)		((dq)->size)
#define qdeque_capacity(dq)	((dq)->capacity)
#define qdeque_empty(dq)	((dq)->size == 0)
#define qdeque_full(dq)		((dq)->size == (dq)->capacity)
