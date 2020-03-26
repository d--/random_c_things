#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "ds/list.h"
#include "ds/array.h"

int main(int argc, char *argv[]) {
	int i, x, y, z;
	float time_spent;
	clock_t begin, end;


	// List

	struct dkw_list *l = dkw_list_new();
	for (i = 0; i < 1000000; i++) {
		dkw_list_push(l, (int) random());
	}

	begin = clock();
	for (i = 0; i < 500; i++) {
		dkw_list_read(l, ((int) random()) % 1000000);
	}
	end = clock();
	time_spent = (float)(end - begin) / CLOCKS_PER_SEC;

	dkw_list_delete(l);

	printf("time spent to do 500 random list reads: %f\n", time_spent);


	// Array

	struct dkw_array *a = dkw_array_new();
	for (i = 0; i < 1000000; i++) {
		dkw_array_insert(a, (int) random());
	}

	begin = clock();
	for (i = 0; i < 500; i++) {
		dkw_array_get(a, ((int) random()) % 1000000);
	}
	end = clock();
	time_spent = (float)(end - begin) / CLOCKS_PER_SEC;

	printf("time spent to do 500 random array reads: %f\n", time_spent);

        return 0;
}

