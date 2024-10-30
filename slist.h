#pragma once

#include <stddef.h>
#include <snode.h>

typedef struct slist {
	snode *head;
} slist;

slist *slist_new(void);
void slist_clear(slist *);
void slist_free(slist *);

snode *slist_add_head(slist *, int);
snode *slist_del_head(slist *);

snode *slist_get(const slist *, size_t);
snode *slist_tail(const slist *);
