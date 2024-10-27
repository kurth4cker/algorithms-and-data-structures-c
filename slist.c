// SPDX-License-Identifier: GPL-3.0-or-later
// SPDX-FileCopyrightText: 2024 kurth4cker <kurth4cker@gmail.com>

#include <stdlib.h>

#include <slist.h>

slist *
slist_new(void)
{
	slist *list = malloc(sizeof(*list));
	if (!list)
		return NULL;

	list->head = NULL;
	return list;
}

void
slist_clear(slist *list)
{
	while (list->head) {
		snode *next = list->head->next;
		free(list->head);
		list->head = next;
	}
}

void
slist_free(slist *list)
{
	slist_clear(list);
	free(list);
}

snode *
slist_add_head(slist *list, int val)
{
	snode *node = malloc(sizeof(*node));
	if (!node)
		return NULL;
	node->data = val;
	node->next = list->head;
	list->head = node;
	return node;
}

snode *
slist_del_head(slist *list)
{
	if (list->head) {
		snode *next = list->head->next;
		free(list->head);
		list->head = next;
	}

	return list->head;
}

snode *
slist_get(const slist *list, size_t idx)
{
	snode *cur = list->head;
	while (idx--) {
		cur = cur->next;
	}
	return cur;
}

snode *
slist_tail(const slist *list)
{
	snode *cur = list->head;
	while (cur->next)
		cur = cur->next;

	return cur;
}

snode *
snode_add_next(snode *node, int val)
{
	snode *new = malloc(sizeof(*new));
	if (!new)
		return NULL;

	new->data = val;
	new->next = node->next;
	node->next = new;

	return new;
}

snode *
snode_del_next(snode *node)
{
	if (node->next) {
		snode *delnode = node->next;
		node->next = delnode->next;
		free(delnode);
	}

	return node->next;
}
