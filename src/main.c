#include <stdio.h>
#include "ds/list.h"
#include "ds/array.h"

int main(int argc, char *argv[]) {
	dkw_List *l = dkw_List_new();

	dkw_List_push(l, 9);
	dkw_List_push(l, 8);
	dkw_List_push(l, 7);
	dkw_List_pop(l);
	dkw_List_pop(l);
	dkw_List_pop(l);
	dkw_List_push(l, 9);
	dkw_List_push(l, 8);
	dkw_List_push(l, 7);

	dkw_List_delete(l);


	dkw_Stack *s = dkw_Stack_new();

	dkw_Stack_push(s, 1027);
	dkw_Stack_push(s, 2);
	dkw_Stack_push(s, 3);
	dkw_Stack_pop(s);
	dkw_Stack_pop(s);
	int final = dkw_Stack_pop(s);

	dkw_Stack_delete(s);

	printf("%d\n", final);

        return 0;
}

