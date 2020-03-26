#ifndef __DKW_ARRAY__
#define __DKW_ARRAY__

typedef struct dkw_Array dkw_Array;
dkw_Array * dkw_Array_new();
void dkw_Array_insert(dkw_Array *a, int d);
int dkw_Array_get(dkw_Array *a, int index);
void dkw_Array_delete(dkw_Array *a);

typedef struct dkw_Stack dkw_Stack;
dkw_Stack * dkw_Stack_new();
void dkw_Stack_push(dkw_Stack *s, int d);
int dkw_Stack_pop(dkw_Stack *s);
void dkw_Stack_delete(dkw_Stack *s);

#endif // __DKW_ARRAY__

