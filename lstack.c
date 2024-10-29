// SPDX-License-Identifier: GPL-3.0-or-later
// SPDX-FileCopyrightText: 2024 kurth4cker <kurth4cker@gmail.com>

#include <stdbool.h>
#include <stdlib.h>

#include <lstack.h>

lstack *
lstack_new(void)
{
	lstack *st = malloc(sizeof(*st));
	if (!st)
		return NULL;

	st->head = NULL;
	st->count = 0;

	return st;
}

void
lstack_clear(lstack *st)
{
	snode *node = st->head;
	while (node) {
		snode *next = node->next;
		free(node);
		node = next;
	}
	st->head = NULL;
	st->count = 0;
}

void
lstack_free(lstack *st)
{
	lstack_clear(st);
	free(st);
}

bool
lstack_push(lstack *st, const int *val)
{
	snode *node = malloc(sizeof(*node));
	if (!node)
		return false;

	node->data = *val;
	node->next = st->head;
	st->head = node;
	st->count++;

	return true;
}

bool
lstack_pop(lstack *st, int *val)
{
	if (lstack_empty(st))
		return false;

	snode *node = st->head;
	*val = node->data;
	st->count--;

	st->head = node->next;
	free(node);

	return true;
}
