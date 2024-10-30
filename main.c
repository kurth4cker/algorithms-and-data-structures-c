// SPDX-License-Identifier: GPL-3.0-or-later
// SPDX-FileCopyrightText: 2024 kurth4cker <kurth4cker@gmail.com>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <tree.h>

static void
print_person(const person *pn)
{
	printf("| %zu, %s\n", pn->id, pn->name);
}

static void
print_bintnode(const bintnode *node)
{
	if (node->left)
		print_bintnode(node->left);
	print_person(&node->person);
	if (node->right)
		print_bintnode(node->right);
}

static void
print_bintnode_with_depth(const bintnode *node, size_t depth)
{
	for (size_t i = 0; i < depth; i++)
		printf("-");
	printf(">");
	print_person(&node->person);
	if (node->left)
		print_bintnode_with_depth(node->left, depth + 1);
	if (node->right)
		print_bintnode_with_depth(node->right, depth + 1);
}

void
print_bintree(const bintree *bt)
{
	printf("size = %zu, root = %p\n", bt->size, (void *)bt->root);
	print_bintnode_with_depth(bt->root, 0);
	print_bintnode(bt->root);
}

int
main(void)
{
	srand(time(NULL));
	bintree *bt = bintree_new();
	if (!bt) {
		fprintf(stderr, "bintree_new failed\n");
		exit(EXIT_FAILURE);
	}

	person people[8];
	const char *names[8] = {
		"ali",
		"ayşe",
		"asena",
		"özge",
		"batu",
		"tamu",
		"erlik",
		"ülgen",
	};
	for (size_t i = 0; i < sizeof(people) / sizeof(*people); i++) {
		size_t id = (size_t)abs(rand()) % 256;
		person_init_with_id(people + i, names[i], id);
		bintree_insert(bt, people + i);
	}

	print_bintree(bt);
	bintree_free(bt);
}
