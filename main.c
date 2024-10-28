// SPDX-License-Identifier: GPL-3.0-or-later
// SPDX-FileCopyrightText: 2024 kurth4cker <kurth4cker@gmail.com>

#include <stdio.h>
#include <stdlib.h>

#include <astack.h>

int
main(void)
{
	astack *st = astack_new_with_size(32);
	if (!st) {
		fprintf(stderr, "astack_new failed\n");
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < 1000; i++) {
		astack_push(st, &i);
	}

	astack_clear(st);

	for (int i = 0; i < 128; i++) {
		astack_push(st, &i);
	}

	astack_clear(st);

	for (int i = 0; !astack_full(st); i++) {
		astack_push(st, &i);
	}

	while (st->count) {
		int val;
		astack_pop(st, &val);
		printf("%d\n", val);
	}

	astack_free(st);
}
