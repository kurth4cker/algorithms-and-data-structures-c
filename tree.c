// SPDX-License-Identifier: GPL-3.0-or-later
// SPDX-FileCopyrightText: 2024 kurth4cker <kurth4cker@gmail.com>

#include <stdlib.h>
#include <tree.h>

void
bintnode_free(bintnode *node)
{
	if (node->right)
		bintnode_free(node->right);
	if (node->left)
		bintnode_free(node->left);
	free(node);
}

bintree *
bintree_new(void)
{
	bintree *bt = malloc(sizeof(*bt));
	if (!bt)
		return NULL;

	bt->size = 0;
	bt->root = NULL;

	return bt;
}

void
bintree_free(bintree *bt)
{
	bintnode_free(bt->root);
	free(bt);
}

bool
bintree_insert(bintree *bt, const person *pn)
{
	bintnode *node = bt->root;
	bintnode *parent;
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

	bintnode *new = malloc(sizeof(*new));
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
bintree_find(const bintree *bt, size_t key)
{
	bintnode *node = bt->root;
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
