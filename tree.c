// SPDX-License-Identifier: GPL-3.0-or-later
// SPDX-FileCopyrightText: 2024 kurth4cker <kurth4cker@gmail.com>

#include <stdlib.h>
#include <tree.h>

void
binary_node_free(binary_node *node)
{
	if (node->right)
		binary_node_free(node->right);
	if (node->left)
		binary_node_free(node->left);
	free(node);
}

binary_tree *
binary_tree_new(void)
{
	binary_tree *bt = malloc(sizeof(*bt));
	if (!bt)
		return NULL;

	bt->size = 0;
	bt->root = NULL;

	return bt;
}

void
binary_tree_free(binary_tree *bt)
{
	binary_node_free(bt->root);
	free(bt);
}

bool
binary_tree_insert(binary_tree *bt, const person *pn)
{
	binary_node *node = bt->root;
	binary_node *parent;
	while (node) {
		parent = node;
		if (pn->id < node->person.id)
			node = node->left;
		else if (pn->id > node->person.id)
			node = node->right;
		else {
			node->person = *pn;
			goto success;
		}
	}

	binary_node *new = malloc(sizeof(*new));
	if (!new)
		return false;
	new->left = new->right = NULL;
	new->person = *pn;

	if (!bt->root) {
		bt->root = new;
		goto success;
	}

	if (pn->id < parent->person.id)
		parent->left = new;
	else
		parent->right = new;

success:
	bt->size++;
	return true;
}

person *
binary_tree_find(const binary_tree *bt, size_t key)
{
	binary_node *node = bt->root;
	while (node) {
		if (key < node->person.id)
			node = node->left;
		else if (key > node->person.id)
			node = node->right;
		else
			return &node->person;
	}
	return NULL;
}
