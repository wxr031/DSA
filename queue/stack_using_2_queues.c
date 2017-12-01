#include <stdio.h>
#include <stdlib.h>
#include "int_queue.h"
typedef struct stack {
	Queue q1, q2;
} Stack;
void init_stack(Stack *s) {
	init_queue(&s->q1);
	init_queue(&s->q2);
}
int is_empty_stack(Stack *s) {
	return is_empty(&s->q1) && is_empty(&s->q2);
}
void push(Stack *s, int data) {
	if (is_empty(&s->q1))
		enqueue(&s->q2, data);
	else enqueue(&s->q1, data);
}
int pop(Stack *s) {
	if (is_empty_stack(s)) {
		printf("Stack Underflow\n");
		return 0x80000000;
	}
	else if (is_empty(&s->q2)) {
		int i, size = s->q1.size;
		for (i = 0; i < size - 1; i ++)
			enqueue(&s->q2, dequeue(&s->q1));
		return dequeue(&s->q1);
	}
	else if (is_empty(&s->q1)){
		int i, size = s->q2.size;
		for (i = 0; i < size - 1; i ++)
			enqueue(&s->q1, dequeue(&s->q2));
		return dequeue(&s->q2);
	}
}
int main() {
	/* Add test code */
	return 0;
}
