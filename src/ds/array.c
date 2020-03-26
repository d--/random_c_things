#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "array.h"


struct dkw_array {
	int size;
	int capacity;
	int *data;
};

struct dkw_array *dkw_array_new() {
	return (struct dkw_array *) calloc(sizeof(struct dkw_array), 1);
}

void dkw_array_insert(struct dkw_array *a, int d) {
	a->size = a->size + 1;

	if (a->capacity == 0) {
		a->data = (int *) calloc(sizeof(int), 2);
		a->data[0] = d;
		a->capacity = 2;
		return;
	}

	if (a->size > a->capacity) {
		int newcap = (int) (a->capacity * 1.5);
		int *newloc = (int *) calloc(sizeof(int), newcap);

		memmove(newloc, a->data, sizeof(int) * a->capacity);

		free(a->data);
		a->capacity = newcap;
		a->data = newloc;
	}

	a->data[a->size - 1] = d;
}

int dkw_array_get(struct dkw_array *a, int index) {
	assert(index >= 0);
	assert(index < a->size);
	return a->data[index];
}

void dkw_array_delete(struct dkw_array *a) {
	free(a->data);
	free(a);
}


struct dkw_stack {
	struct dkw_array *array;
	int size;
};

struct dkw_stack *dkw_stack_new() {
	struct dkw_stack *s;
	s = (struct dkw_stack *) calloc(sizeof(struct dkw_stack), 1);
	s->array = dkw_array_new();
	return s;
}

void dkw_stack_push(struct dkw_stack *s, int d) {
	dkw_array_insert(s->array, d);
	s->size = s->size + 1;
}

int dkw_stack_pop(struct dkw_stack *s) {
	s->size = s->size - 1;
	return dkw_array_get(s->array, s->size);
}

void dkw_stack_delete(struct dkw_stack *s) {
	dkw_array_delete(s->array);
	free(s);
}

