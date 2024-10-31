// SPDX-License-Identifier: GPL-3.0-or-later
// SPDX-FileCopyrightText: 2024 kurth4cker <kurth4cker@gmail.com>

#include <stdlib.h>

#include <priority-queue.h>

static const size_t DEFAULT_CAPACITY = 32;

priority_queue *
priority_queue_new(void)
{
	return priority_queue_new_with_capacity(DEFAULT_CAPACITY);
}

priority_queue *
priority_queue_new_with_capacity(size_t capacity)
{
	priority_queue *pri = malloc(sizeof(*pri));
	if (!pri)
		return NULL;

	pri->data = malloc(sizeof(*pri->data) * capacity);
	if (!pri->data) {
		free(pri);
		return NULL;
	}

	pri->size = 0;
	pri->capacity = capacity;

	return pri;
}

void
priority_queue_free(priority_queue *pri)
{
	free(pri->data);
	free(pri);
}

bool
priority_queue_put(priority_queue *pri, const person *pn)
{
	if (priority_queue_full(pri)) {
		void *data = realloc(pri->data, pri->capacity * 2);
		if (!data)
			return false;
		pri->data = data;
		pri->capacity *= 2;
	}

	pri->size++;
	size_t idx = pri->size;
	if (idx != 1)
		while (pn->id > pri->data[idx / 2].id && idx > 1) {
			pri->data[idx] = pri->data[idx / 2];
			idx /= 2;
		}
	pri->data[idx] = *pn;

	return true;
}

bool
priority_queue_get(priority_queue *pri, person *pn)
{
	// TODO
	return true;
}
