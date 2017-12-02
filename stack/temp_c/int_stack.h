#ifndef INT_STACK_H
#define INT_STACK_H
typedef struct listnode {
	int data;
	struct listnode *next;
} Listnode;
typedef struct stack {
	int top;
	struct listnode *head;
} Stack;
void init(Stack *stack);
int is_empty(Stack *stack);
void push(Stack *stack, int data);
int pop(Stack *stack);
int get_size(Stack *stack);
#endif
