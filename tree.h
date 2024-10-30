#pragma once

#include <person.h>

typedef struct bintnode {
	struct bintnode *left, *right;
	person person;
} bintnode;

void bintnode_free(bintnode *);

typedef struct bintree {
	bintnode *root;
	size_t size;
} bintree;

bintree *bintree_new(void);
void bintree_free(bintree *);

bool bintree_insert(bintree *, const person *);

person *bintree_find(const bintree *, size_t id);
