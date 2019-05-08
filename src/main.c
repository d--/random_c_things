#include <stdio.h>
#include "ds/list.h"

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
        return 0;
}

