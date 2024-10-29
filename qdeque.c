// SPDX-License-Identifier: GPL-3.0-or-later
// SPDX-FileCopyrightText: 2024 kurth4cker <kurth4cker@gmail.com>

#include <stdlib.h>
#include <string.h>

#include <qdeque.h>

#define MIN(a,b)	((a) < (b) ? (a) : (b))

static const size_t DEFAULT_CAPACITY = 32;

qdeque *
qdeque_new(void)
{
	return qdeque_new_with_capacity(DEFAULT_CAPACITY);
}

qdeque *
qdeque_new_with_capacity(size_t capacity)
{
	qdeque *dq = malloc(sizeof(*dq));
	if (!dq)
		return NULL;

	dq->data = malloc(sizeof(*dq->data) * capacity);
	if (!dq->data) {
		free(dq);
		return NULL;
	}
	dq->capacity = capacity;
	dq->head = dq->tail = 0;
	dq->size = 0;

	return dq;
}

void
qdeque_clear(qdeque *dq)
{
	dq->head = dq->tail = dq->capacity / 2;
	dq->size = 0;
}

void
qdeque_free(qdeque *dq)
{
	free(dq->data);
	free(dq);
}

bool
qdeque_set_capacity(qdeque *dq, size_t capacity)
{
	if (capacity < dq->size)
		return false;

	int *data = malloc(sizeof(*data) * capacity);
	if (!data)
		return false;

	// TODO: is it necessary?
	const size_t sz1 = MIN(dq->capacity - dq->head, dq->size);
	const size_t sz2 = dq->size - sz1;
	memcpy(data, &dq->data[dq->head], sz1 * sizeof(*data));
	memcpy(data + sz1, dq->data, sz2 * sizeof(*data));

	free(dq->data);
	dq->data = data;
	dq->head = 0;
	dq->tail = dq->size;
	dq->capacity = capacity;

	return true;
}

bool
qdeque_add_head(qdeque *dq, const int *val)
{
	if (qdeque_full(dq))
		if (!qdeque_set_capacity(dq, dq->capacity * 2))
			return false;

	if (dq->head == 0)
		dq->head = dq->capacity - 1;
	else
		dq->head--;

	dq->data[dq->head] = *val;
	dq->size++;

	return true;
}

bool
qdeque_add_tail(qdeque *dq, const int *val)
{
	if (qdeque_full(dq))
		if (!qdeque_set_capacity(dq, dq->capacity * 2))
			return false;

	dq->data[dq->tail] = *val;
	dq->tail++; // we do not need to turn into start of data
	dq->size++;

	return true;
}

void
qdeque_get(const qdeque *dq, size_t idx, int *val)
{
	idx = (dq->head + idx) % dq->capacity;
	*val = dq->data[idx];
}
