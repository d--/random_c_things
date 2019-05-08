#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

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
	if (l->size == 0) {
		assert("error" == "list is empty");
	}

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
	if (index > l->size - 1) {
		assert("error" == "list index of out range");
	}

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

void dkw_List_print(dkw_List *l) {
	if (l->head == NULL) {
		printf("l->head: NULL\n");
	} else {
		printf("l->head: %x\n", l->head);
	}
	if (l->tail == NULL) {
		printf("l->tail: NULL\n");
	} else {
		printf("l->tail: %x\n", l->tail);
	}
	printf("l->size: %d\n\n", l->size);

	dkw_list_node *c = l->head;
	for (int i = 0; i < l->size; i++) {
		printf("  %d ->addr: %x\n", i, c);
		if (c->prev == NULL) {
			printf("  %d ->prev: NULL\n", i);
		} else {
			printf("  %d ->prev: %x\n", i, c->prev);
		}
		if (c->next == NULL) {
			printf("  %d ->next: NULL\n", i);
		} else {
			printf("  %d ->next: %x\n", i, c->next);
		}
		printf("  %d ->v: %d\n\n", i, c->v);
		c = c->next;
	}
}

