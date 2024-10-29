// SPDX-License-Identifier: GPL-3.0-or-later
// SPDX-FileCopyrightText: 2024 kurth4cker <kurth4cker@gmail.com>

#include <stdio.h>
#include <stdlib.h>

#include <lstack.h>

int
main(void)
{
	lstack *st = lstack_new();
	if (!st) {
		fprintf(stderr, "lstack_new failed\n");
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < 1000; i++) {
		lstack_push(st, &i);
	}

	lstack_clear(st);

	for (int i = 0; i < 128; i++) {
		lstack_push(st, &i);
	}

	while (st->count) {
		int val;
		lstack_pop(st, &val);
		printf("%d\n", val);
	}

	lstack_free(st);
}
