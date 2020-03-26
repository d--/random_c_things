#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct dkw_list_node dkw_list_node;
struct dkw_list_node {
	dkw_list_node *prev;
	dkw_list_node *next;
	int v;
};

struct dkw_List {
	dkw_list_node *head;
	dkw_list_node *tail;
	uintmax_t size;
};

dkw_List *dkw_List_new() {
	dkw_List *l = (dkw_List*) calloc(1, sizeof(dkw_List));
	l->head = NULL;
	l->size = 0;
	l->tail = NULL;
	return l;
}

void dkw_List_push(dkw_List *l, int v) {
	dkw_list_node *n;
	n = (dkw_list_node*) calloc(1, sizeof(dkw_list_node));
	n->prev = l->tail;
	n->v = v;
	n->next = NULL;

	if (l->size == 0) {
		l->head = n;
	} else {
		l->tail->next = n;
	}
	l->tail = n;
	l->size++;
}

int dkw_List_pop(dkw_List *l) {
	assert(l->size > 0);

	dkw_list_node *c = l->tail;
	int v = c->v;
	l->tail = c->prev;
	l->size--;
	free(c);

	if (l->size > 0) {
		l->tail->next = NULL;
	} else {
		l->head = NULL;
	}

	return v;
}

int dkw_List_read(dkw_List *l, int index) {
	assert(index >= 0);
	assert(index < l->size);

	dkw_list_node *c = l->head;
	for (int i = 0; i < index; i++) {
		c = c->next;
	}

	return c->v;
}

uintmax_t dkw_List_len(dkw_List *l) {
	return l->size;
}

void dkw_List_delete(dkw_List *l) {
	dkw_list_node *c = l->head;
	for (int i = 0; i < l->size; i++) {
		dkw_list_node *n = c->next;
		free(c);
		c = n;
	}
	free(l);
}

