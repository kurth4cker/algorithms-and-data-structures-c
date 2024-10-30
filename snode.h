#pragma once

#include <stddef.h>

typedef struct snode {
	struct snode *next;
	int data;
} snode;

snode *snode_add_next(snode *, int);
snode *snode_del_next(snode *);
