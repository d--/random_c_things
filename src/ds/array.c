#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array.h"


struct dkw_Array {
	int size;
	int capacity;
	int *data;
};

dkw_Array *dkw_Array_new() {
	return (dkw_Array *) calloc(sizeof(dkw_Array), 1);
}

void dkw_Array_insert(dkw_Array *a, int d) {
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

int dkw_Array_get(dkw_Array *a, int index) {
	assert(index >= 0);
	assert(index < a->size);
	return a->data[index];
}

void dkw_Array_delete(dkw_Array *a) {
	free(a->data);
	free(a);
}


struct dkw_Stack {
	dkw_Array *array;
	int size;
};

dkw_Stack * dkw_Stack_new() {
	dkw_Stack *s = (dkw_Stack *) calloc(sizeof(dkw_Stack), 1);
	s->array = dkw_Array_new();
	return s;
}

void dkw_Stack_push(dkw_Stack *s, int d) {
	dkw_Array_insert(s->array, d);
	s->size = s->size + 1;
}

int dkw_Stack_pop(dkw_Stack *s) {
	s->size = s->size - 1;
	return dkw_Array_get(s->array, s->size);
}

void dkw_Stack_delete(dkw_Stack *s) {
	dkw_Array_delete(s->array);
	free(s);
}

