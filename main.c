// SPDX-License-Identifier: GPL-3.0-or-later
// SPDX-FileCopyrightText: 2024 kurth4cker <kurth4cker@gmail.com>

#include <stdio.h>
#include <stdlib.h>

#include <farray.h>

static int
pow_int(int base, int exp)
{
	int val = 1;
	while (exp--) {
		val *= base;
	}
	return val;
}

void
print_farray(const farray *arr)
{
	printf("size = %zu\n", farray_size(arr));
	for (size_t i = 0; i < farray_size(arr); i++) {
		printf("arr[%zu] = %d\n", i, farray_get(arr, i));
	}
}

int
main(void)
{
	farray *arr = farray_new(16);
	if (!arr) {
		fprintf(stderr, "farray_new failed\n");
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < farray_size(arr); i++) {
		farray_set(arr, i, pow_int(2, i));
	}

	print_farray(arr);
	farray_free(arr);
}
