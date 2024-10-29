// SPDX-License-Identifier: GPL-3.0-or-later
// SPDX-FileCopyrightText: 2024 kurth4cker <kurth4cker@gmail.com>

#include <stdio.h>
#include <stdlib.h>

#include <qdeque.h>

void
print_qdeque(const qdeque *dq)
{
	printf("capacity = %zu, size = %zu\n", dq->capacity, dq->size);
	printf("head = %zu, tail = %zu\n", dq->head, dq->tail);
	for (size_t i = 0; i < qdeque_size(dq); i++) {
		int val;
		qdeque_get(dq, i, &val);
		printf("deque[%zu] = %d\n", i, val);
	}
}

int
main(void)
{
	qdeque *dq = qdeque_new_with_capacity(2);
	if (!dq) {
		fprintf(stderr, "deque_new failed\n");
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < 8; i++)
		qdeque_add_tail(dq, &i);

	for (int i = 10; i < 90; i += 10)
		qdeque_add_head(dq, &i);

	qdeque_add_tail(dq, &(int){ 32 });

	print_qdeque(dq);

	qdeque_free(dq);
}
