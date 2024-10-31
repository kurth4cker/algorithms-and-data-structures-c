#pragma once

#include <stdbool.h>
#include <stddef.h>
#include <person.h>

typedef struct priority_queue {
	size_t size, capacity;
	person *data;
} priority_queue;

priority_queue *priority_queue_new(void);
priority_queue *priority_queue_new_with_capacity(size_t);
void priority_queue_free(priority_queue *);

bool priority_queue_put(priority_queue *, const person *);
bool priority_queue_get(priority_queue *, person *);

#define priority_queue_full(pri)	((pri)->size == (pri)->capacity)
#define priority_queue_size(pri)	((pri)->size - 1)
#define priority_queue_capacity(pri)	((pri)->capacity - 1)
