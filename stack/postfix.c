#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
typedef struct listnode {
	int data;
	struct listnode *next;
} Listnode;
typedef struct stack {
	int top;
	struct listnode *head;
} Stack;
void init(Stack *stack) {
	stack->top = -1;
	stack->head = NULL;
}
int is_empty(Stack *stack) {
	return stack->top == -1;
}
void push(Stack *stack, int n) {
	Listnode *new = (Listnode *)malloc(sizeof(Listnode));
	new->data = n;
	new->next = stack->head;
	stack->head = new;
	stack->top ++;
}
int pop(Stack *stack) {
	if (is_empty(stack)) {
		printf("Stack Full.\n");
		return INT_MIN;
	}
	int elm = stack->head->data;
	Listnode *temp = stack->head;
	stack->head = stack->head->next;
	free(temp);
	stack->top --;
	return elm;
}
int main() {
	Stack stack;
	init(&stack);
	push(&stack, 1);
	push(&stack, 2);
	push(&stack, 3);
	push(&stack, 4);
	push(&stack, 5);
	push(&stack, 6);
	push(&stack, 7);
	printf("%d\n", pop(&stack));
	printf("%d\n", pop(&stack));
	printf("%d\n", pop(&stack));
	printf("%d\n", pop(&stack));
	printf("%d\n", pop(&stack));
	printf("%d\n", pop(&stack));
	printf("%d\n", pop(&stack));
	printf("%d\n", pop(&stack));
	printf("%d\n", pop(&stack));
	printf("%d\n", pop(&stack));
	printf("%d\n", pop(&stack));
	printf("%d\n", is_empty(&stack));
	return 0;

}
