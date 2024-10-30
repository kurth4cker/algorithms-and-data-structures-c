// SPDX-License-Identifier: GPL-3.0-or-later
// SPDX-FileCopyrightText: 2024 kurth4cker <kurth4cker@gmail.com>

#include <string.h>
#include <person.h>

static size_t next_id = 0;

void
person_init(person *pn, const char *name)
{
	person_init_with_id(pn, name, next_id++);
}

void
person_init_with_id(person *pn, const char *name, size_t id)
{
	pn->id = id;
	strncpy(pn->name, name, sizeof(pn->name));
}
