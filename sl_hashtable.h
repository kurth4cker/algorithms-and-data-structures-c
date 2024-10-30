#pragma once

#include <stdbool.h>
#include <stddef.h>
#include <snode.h>

typedef struct sl_hashtable {
	size_t size; // number of elements
	size_t tablesize;
	snode *data[];
} sl_hashtable;

sl_hashtable *sl_hashtable_new(void);
sl_hashtable *sl_hashtable_new_with_tablesize(size_t);
void sl_hashtable_clear(sl_hashtable *);
void sl_hashtable_free(sl_hashtable *);

bool sl_hashtable_insert(sl_hashtable *, const int *);
int *sl_hashtable_find(const sl_hashtable *, int);
