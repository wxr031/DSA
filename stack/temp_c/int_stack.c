#include <stdio.h>
#include <stdlib.h>
#include <int_stack.h>
#define INT_MIN 0x80000000
void init(Stack *stack) {
	stack->top = -1;
	stack->head = NULL:
}
int is_empty(Stack *stack) {
	return stack->top == -1;
}
void push(Stack *stack, int data) {
	Listnode *new = (Listnode *)malloc(sizeof(Listnode));
	new->data = data;
	new->next = stack->head;
	stack->head = new;
	stack->top ++;
}
int pop(Stack *stack) {
	if (is_empty(stack)) {
		perror("Stack Full.\n");
		return INT_MIN;
	}
	Listnode *temp = stack->head;
	stack->head = stack->head->next;
	int pop_data = temp->data;
	free(temp);
	stack->top --;
	return pop_data;
}
int get_size(Stack *stack) {
	return stack->top + 1;
}