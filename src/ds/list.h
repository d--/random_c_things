#ifndef __DKW_LIST__
#define __DKW_LIST__

#include <inttypes.h>

typedef struct dkw_list_node dkw_list_node;
struct dkw_list_node {
	dkw_list_node *prev;
	dkw_list_node *next;
	int v;
};

typedef struct dkw_List dkw_List;
struct dkw_List {
	dkw_list_node *head;
	dkw_list_node *tail;
	uintmax_t size;
};

dkw_List *dkw_List_new();
void dkw_List_push(dkw_List *l, int v);
int dkw_List_pop(dkw_List *l);
int dkw_List_read(dkw_List *l, int index);
uintmax_t dkw_List_len(dkw_List *l);
void dkw_List_delete(dkw_List *l);
void dkw_List_print(dkw_List *l);

#endif // __DKW_LIST__
