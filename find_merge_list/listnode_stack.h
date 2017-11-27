#ifndef INT_STACK_H
#define INT_STACK_H
typedef struct listnode {
	struct listnode *data;
	struct listnode *next;
} Listnode;
typedef struct stack {
	int top;
	struct listnode *head;
} Stack;
void init(Stack *);
int is_empty(Stack *);
void push(Stack *, Listnode *);
Listnode *pop(Stack *);
int get_size(Stack *);
#endif
