struct _CHStack;
typedef struct _CHStack CHStack;

CHStack *chstack_new(const unsigned int maxElems);
void chstack_free(CHStack *stack);
void *chstack_peek(CHStack *stack);
void *chstack_pop(CHStack *stack);
void chstack_push(CHStack *stack, void *p);
int chstack_size(CHStack *stack);
