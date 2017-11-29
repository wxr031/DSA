#ifndef INT_STACK_H
#define INT_STACK_H
typedef struct listnode {
	char data;
	struct listnode *next;
} Listnode;
typedef struct stack {
	int top;
	struct listnode *head;
} Stack;
void init(Stack *);
int is_empty(Stack *stack);
void push(Stack *stack, char data);
char pop(Stack *stack);
int get_size(Stack *stack);
#endif
