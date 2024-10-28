// SPDX-License-Identifier: GPL-3.0-or-later
// SPDX-FileCopyrightText: 2024 kurth4cker <kurth4cker@gmail.com>

#include <stdlib.h>

#include <aqueue.h>

aqueue *
aqueue_new(size_t capacity)
{
	aqueue *qe = malloc(sizeof(*qe));
	if (!qe)
		return NULL;

	qe->data = malloc(sizeof(*qe->data) * capacity);
	if (!qe->data) {
		free(qe);
		return NULL;
	}
	qe->capacity = capacity;
	qe->head = qe->tail = qe->count = 0;

	return qe;
}

void
aqueue_clear(aqueue *qe)
{
	qe->head = qe->tail = 0;
	qe->count = 0;
}

void
aqueue_free(aqueue *qe)
{
	free(qe->data);
	free(qe);
}

bool
aqueue_put(aqueue *qe, const int *val)
{
	if (aqueue_isfull(qe))
		return false;

	qe->data[qe->tail] = *val;
	qe->tail = (qe->tail + 1) % qe->capacity;
	qe->count++;

	return true;
}

bool
aqueue_get(aqueue *qe, int *val)
{
	if (aqueue_isempty(qe))
		return false;

	*val = qe->data[qe->head];
	qe->head = (qe->head + 1) % qe->capacity;
	qe->count--;

	return true;
}
