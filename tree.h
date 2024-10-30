#pragma once

#include <person.h>

typedef struct binary_node {
	struct binary_node *left, *right;
	person person;
} binary_node;

void binary_node_free(binary_node *);

typedef struct binary_tree {
	binary_node *root;
	size_t size;
} binary_tree;

binary_tree *binary_tree_new(void);
void binary_tree_free(binary_tree *);

bool binary_tree_insert(binary_tree *, const person *);
person *binary_tree_find(const binary_tree *, size_t id);
