#include <stdio.h>
#include <limits.h>
#include "int_stack.h"
/* Queue */
typedef struct queue {
	Stack s1, s2;
} Queue;
void init_queue(Queue *q) {
	init(&q->s1);
	init(&q->s2);
}
int is_empty_queue(Queue *q) {
	return is_empty(&q->s1) && is_empty(&q->s2);
}
void enqueue(Queue *q, int data) {
	push(&q->s1, data);
}
int dequeue(Queue *q) {
	if (is_empty_queue(q)) {
		printf("Stack Underflow\n");
		return 0x80000000;
	}
	if (is_empty(&q->s2)) {
		while (!is_empty(&q->s1))
			push(&q->s2, pop(&q->s1));
	}
	return pop(&q->s2);
}
int main() {
	/* Add test code */
	Queue q;
	init_queue(&q);
	enqueue(&q, 1);
	enqueue(&q, 2);
	enqueue(&q, 3);
	enqueue(&q, 4);
	printf("%d\n", dequeue(&q));
	printf("%d\n", dequeue(&q));
	enqueue(&q, 5);
	printf("%d\n", dequeue(&q));
	printf("%d\n", dequeue(&q));
	printf("%d\n", dequeue(&q));
	return 0;
}
