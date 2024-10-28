// SPDX-License-Identifier: GPL-3.0-or-later
// SPDX-FileCopyrightText: 2024 kurth4cker <kurth4cker@gmail.com>

#include <stdio.h>
#include <stdlib.h>

#include <lqueue.h>

int
main(void)
{
	lqueue *qe = lqueue_new();
	if (!qe) {
		fprintf(stderr, "lqueue_new failed\n");
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < 5; i++) {
		lqueue_put(qe, &i);
	}

	while (!lqueue_isempty(qe)) {
		int val;
		lqueue_get(qe, &val);
		printf("%d\n", val);
	}

	lqueue_free(qe);
}
