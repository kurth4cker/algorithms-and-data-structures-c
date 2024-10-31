// SPDX-License-Identifier: GPL-3.0-or-later
// SPDX-FileCopyrightText: 2024 kurth4cker <kurth4cker@gmail.com>

#include <stdio.h>
#include <stdlib.h>

#include <priority-queue.h>

#define ARRSIZE(arr)	(sizeof(arr) / sizeof(*arr))

static void
print_person(const person *pn)
{
	printf("| %zu, %s\n", pn->id, pn->name);
}

int
main(void)
{
	priority_queue *pri = priority_queue_new();
	if (!pri) {
		fprintf(stderr, "priority_queue_new failed\n");
		exit(EXIT_FAILURE);
	}

	person people[] = {
		{0, "Ali Serçe"},
		{4, "kurth4cker"},
		{3, "kthzk"},
		{17, "kthr"},
		{10, "emacs"},
		{1, "vim"},
	};

	size_t people_size = ARRSIZE(people);
	for (size_t i = 0; i < people_size; i++) {
		if (!priority_queue_put(pri, &people[i])) {
			fprintf(stderr, "priority_queue_put failed\n");
			goto err;
		}
	}

	for (size_t i = 0; i < ARRSIZE(people); i++) {
		print_person(people + i);
	}

	priority_queue_free(pri);
	exit(EXIT_SUCCESS);
err:
	priority_queue_free(pri);
	exit(EXIT_FAILURE);
}
