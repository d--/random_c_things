#include <stdlib.h>
#include <assert.h>
#include "list.h"

struct dkw_list_node {
	struct dkw_list_node *prev;
	struct dkw_list_node *next;
	int v;
};

struct dkw_list {
	struct dkw_list_node *head;
	struct dkw_list_node *tail;
	uintmax_t size;
};

struct dkw_list *dkw_list_new() {
	struct dkw_list *l;
	l = (struct dkw_list*) calloc(1, sizeof(struct dkw_list));
	l->head = NULL;
	l->size = 0;
	l->tail = NULL;
	return l;
}

void dkw_list_push(struct dkw_list *l, int v) {
	struct dkw_list_node *n;
	n = (struct dkw_list_node*) calloc(1, sizeof(struct dkw_list_node));
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

int dkw_list_pop(struct dkw_list *l) {
	assert(l->size > 0);

	struct dkw_list_node *c = l->tail;
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

int dkw_list_read(struct dkw_list *l, int index) {
	assert(index >= 0);
	assert(index < l->size);

	struct dkw_list_node *c = l->head;
	for (int i = 0; i < index; i++) {
		c = c->next;
	}

	return c->v;
}

uintmax_t dkw_list_len(struct dkw_list *l) {
	return l->size;
}

void dkw_list_delete(struct dkw_list *l) {
	struct dkw_list_node *c = l->head;
	for (int i = 0; i < l->size; i++) {
		struct dkw_list_node *n = c->next;
		free(c);
		c = n;
	}
	free(l);
}

