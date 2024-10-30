// SPDX-License-Identifier: GPL-3.0-or-later
// SPDX-FileCopyrightText: 2024 kurth4cker <kurth4cker@gmail.com>

#include <stdio.h>
#include <stdlib.h>

#include <sl_hashtable.h>

void
print_sl_hashtable(const sl_hashtable *ht)
{
	printf("size = %zu, tablesize = %zu\n", ht->size, ht->tablesize);
	for (int i = 0;; i++) {
		const int *val = sl_hashtable_find(ht, i);
		if (!val)
			break;
		printf("hashtable[%d] = %d at %p\n", i, *val, (void *)val);
	}
}

int
main(void)
{
	sl_hashtable *ht = sl_hashtable_new_with_tablesize(8);
	if (!ht) {
		fprintf(stderr, "sl_hashtable_new failed\n");
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < 32; i++) {
		sl_hashtable_insert(ht, &i);
	}

	print_sl_hashtable(ht);
}
