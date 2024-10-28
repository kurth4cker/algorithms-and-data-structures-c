// SPDX-License-Identifier: GPL-3.0-or-later
// SPDX-FileCopyrightText: 2024 kurth4cker <kurth4cker@gmail.com>

#include <stdlib.h>

#include <lqueue.h>

lqueue *
lqueue_new(void)
{
	lqueue *qe = malloc(sizeof(*qe));
	if (!qe)
		return NULL;

	qe->head = qe->tail = NULL;
	qe->count = 0;

	return qe;
}

void
lqueue_clear(lqueue *qe)
{
	snode *node = qe->head;

	while (node) {
		snode *next = node->next;
		free(node);
		node = next;
	}

	qe->head = qe->tail = NULL;
	qe->count = 0;
}

void
lqueue_free(lqueue *qe)
{
	lqueue_clear(qe);
	free(qe);
}

bool
lqueue_put(lqueue *qe, const int *val)
{
	snode *node = malloc(sizeof(*node));
	if (!node)
		return false;

	node->data = *val;
	if (qe->tail)
		qe->tail->next = node;
	else
		qe->head = node;
	qe->tail = node;

	qe->count++;
	return true;
}

bool
lqueue_get(lqueue *qe, int *val)
{
	if (lqueue_isempty(qe))
		return false;

	snode *node = qe->head;
	qe->head = node->next;
	if (!qe->head)
		qe->tail = NULL;

	*val = node->data;
	free(node);
	qe->count--;

	return true;
}
