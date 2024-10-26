// SPDX-License-Identifier: GPL-3.0-or-later
// SPDX-FileCopyrightText: 2024 kurth4cker <kurth4cker@gmail.com>

#include <stdio.h>

#include <slist.h>

void
print_snode(const snode *node)
{
	if (node)
		printf("%d\n", node->data);
}

void
print_slist(const slist *list)
{
	snode *cur = list->head;

	while (cur) {
		print_snode(cur);
		cur = cur->next;
	}
}

int
main(void)
{
	slist *list = slist_new();
	if (!list) {
		fprintf(stderr, "slist allocation failed\n");
		return 1;
	}

	for (int i = 1; i <= 8; i *= 2) {
		slist_add_head(list, i);
	}

	snode *node = slist_add_head(list, 16);
	node = snode_add_next(node, 64);
	snode_add_next(node->next->next, 128);

	snode *tail = slist_tail(list);
	printf("tail = ");
	print_snode(tail);

	print_slist(list);
}
