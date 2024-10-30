#pragma once

#include <stdbool.h>
#include <stddef.h>

typedef struct person {
	size_t id;
	char name[32];
} person;

void person_init(person *, const char *);
void person_init_with_id(person *, const char *, size_t);
