// SPDX-License-Identifier: GPL-3.0-or-later
// SPDX-FileCopyrightText: 2024 kurth4cker <kurth4cker@gmail.com>

#include <stdlib.h>
#include <sl_hashtable.h>

static const size_t DEFAULT_TABLESIZE = 4096;

static size_t
gethash(int key, size_t tablesize)
{
	return (size_t)(abs(key) % tablesize);
}

sl_hashtable *
sl_hashtable_new(void)
{
	return sl_hashtable_new_with_tablesize(DEFAULT_TABLESIZE);
}

sl_hashtable *
sl_hashtable_new_with_tablesize(size_t tablesize)
{
	sl_hashtable *ht = malloc(sizeof(*ht) + sizeof(*ht->data) * tablesize);
	if (!ht)
		return NULL;

	ht->tablesize = tablesize;
	ht->size = 0;

	while (tablesize--) {
		ht->data[tablesize] = NULL;
	}

	return ht;
}

bool
sl_hashtable_insert(sl_hashtable *ht, const int *val)
{
	const size_t hash = gethash(*val, ht->tablesize);
	snode *node;

	for (node = ht->data[hash]; node; node = node->next) {
		if (node->data == *val)
			return true;
	}
	if (!node) {
		node = malloc(sizeof(*node));
		if (!node)
			return false;
	}

	node->data = *val;
	node->next = ht->data[hash];
	ht->data[hash] = node;
	ht->size++;

	return true;
}

int *
sl_hashtable_find(const sl_hashtable *ht, int key)
{
	const size_t hash = gethash(key, ht->tablesize);

	for (snode *head = ht->data[hash]; head; head = head->next) {
		if (key == head->data)
			return &head->data;
	}
	return NULL;
}
