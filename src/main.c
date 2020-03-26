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

	dkw_List *l = dkw_List_new();
	for (i = 0; i < 1000000; i++) {
		dkw_List_push(l, (int) random());
	}

	begin = clock();
	for (i = 0; i < 500; i++) {
		dkw_List_read(l, ((int) random()) % 1000000);
	}
	end = clock();
	time_spent = (float)(end - begin) / CLOCKS_PER_SEC;

	dkw_List_delete(l);

	printf("time spent to do 500 random list reads: %f\n", time_spent);


	// Array

	dkw_Array *a = dkw_Array_new();
	for (i = 0; i < 1000000; i++) {
		dkw_Array_insert(a, (int) random());
	}

	begin = clock();
	for (i = 0; i < 500; i++) {
		dkw_Array_get(a, ((int) random()) % 1000000);
	}
	end = clock();
	time_spent = (float)(end - begin) / CLOCKS_PER_SEC;

	printf("time spent to do 500 random array reads: %f\n", time_spent);

        return 0;
}

