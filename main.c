// SPDX-License-Identifier: GPL-3.0-or-later
// SPDX-FileCopyrightText: 2024 kurth4cker <kurth4cker@gmail.com>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include <tree.h>

static void
print_person(const person *pn)
{
	printf("| %zu, %s\n", pn->id, pn->name);
}

static void
print_binary_node(const binary_node *node)
{
	if (node->left)
		print_binary_node(node->left);
	print_person(&node->person);
	if (node->right)
		print_binary_node(node->right);
}

static void
print_binary_node_with_depth(const binary_node *node, size_t depth)
{
	for (size_t i = 0; i < depth; i++)
		printf("-");
	printf(">");
	print_person(&node->person);
	if (node->left)
		print_binary_node_with_depth(node->left, depth + 1);
	if (node->right)
		print_binary_node_with_depth(node->right, depth + 1);
}

void
print_binary_tree(const binary_tree *bt)
{
	printf("size = %zu, root = %p\n", bt->size, (void *)bt->root);
	print_binary_node_with_depth(bt->root, 0);
	print_binary_node(bt->root);
}

int
main(void)
{
	srand(time(NULL));
	binary_tree *bt = binary_tree_new();
	if (!bt) {
		fprintf(stderr, "binary_tree_new failed\n");
		exit(EXIT_FAILURE);
	}

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
	for (size_t i = 0; i < sizeof(names) / sizeof(*names); i++) {
		size_t id = (size_t)abs(rand()) % 256;
		person pn = {
			.id = id,
		};
		strncpy(pn.name, names[i], sizeof(pn.name) / sizeof(*pn.name));
		binary_tree_insert(bt, &pn);
	}

	print_binary_tree(bt);
	binary_tree_free(bt);
}
