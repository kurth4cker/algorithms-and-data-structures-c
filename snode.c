// SPDX-License-Identifier: GPL-3.0-or-later
// SPDX-FileCopyrightText: 2024 kurth4cker <kurth4cker@gmail.com>

#include <stdlib.h>

#include <snode.h>

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
