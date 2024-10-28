// SPDX-License-Identifier: GPL-3.0-or-later
// SPDX-FileCopyrightText: 2024 kurth4cker <kurth4cker@gmail.com>

#include <stdbool.h>
#include <stdlib.h>

#include <astack.h>

static const size_t DEFAULT_SIZE = 1024;

astack *
astack_new(void)
{
	return astack_new_with_size(DEFAULT_SIZE);
}

astack *
astack_new_with_size(size_t size)
{
	astack *st = malloc(sizeof(*st));
	if (!st)
		return NULL;

	st->data = malloc(sizeof(*st->data) * size);
	if (!st->data) {
		free(st);
		return NULL;
	}

	st->size = size;
	st->count = 0;
	st->sp = st->data + size;

	return st;
}

void
astack_clear(astack *st)
{
	st->sp = st->data + st->size;
	st->count = 0;
}

void
astack_free(astack *st)
{
	free(st->data);
	free(st);
}

bool
astack_push(astack *st, const int *val)
{
	if (astack_full(st))
		return false;

	st->sp--;
	st->count++;
	*st->sp = *val;

	return true;
}

bool
astack_pop(astack *st, int *val)
{
	if (astack_empty(st))
		return false;

	*val = *st->sp;
	st->sp++;
	st->count--;

	return true;
}
