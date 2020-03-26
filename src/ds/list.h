#ifndef __DKW_LIST__
#define __DKW_LIST__

#include <inttypes.h>

struct dkw_list *dkw_list_new();
void dkw_list_push(struct dkw_list *l, int v);
int dkw_list_pop(struct dkw_list *l);
int dkw_list_read(struct dkw_list *l, int index);
uintmax_t dkw_list_len(struct dkw_list *l);
void dkw_list_delete(struct dkw_list *l);

#endif // __DKW_LIST__
