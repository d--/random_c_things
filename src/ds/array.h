#ifndef __DKW_ARRAY__
#define __DKW_ARRAY__

struct dkw_array *dkw_array_new();
void dkw_array_insert(struct dkw_array *a, int d);
int dkw_array_get(struct dkw_array *a, int index);
void dkw_array_delete(struct dkw_array *a);

struct dkw_stack *dkw_stack_new();
void dkw_stack_push(struct dkw_stack *s, int d);
int dkw_stack_pop(struct dkw_stack *s);
void dkw_stack_delete(struct dkw_stack *s);

#endif // __DKW_ARRAY__

