#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <limits.h>
typedef struct listnode {
	int data;
	struct listnode *next;
} Listnode;
typedef struct queue {
	Listnode *front, *rear;
	int size;
} Queue;
void init_queue(Queue *q) {
	q->front = q->rear = NULL;
	q->size = 0;
}
int is_empty(Queue *q) {
	return q->size == 0;
}
int get_size(Queue *q) {
	return q->size;
}
void enqueue(Queue *q, int data) {
	Listnode *new = (Listnode *)malloc(sizeof(Listnode));
	assert(new);
	new->data = data;
	new->next = NULL;
	q->size ++;
	if (!q->front) {
		q->front = q->rear = new;
		return;
	}
	q->rear->next = new;
	q->rear = new;
}
int dequeue(Queue *q) {
	if (is_empty(q)) {
		printf("Underflow\n");
		return INT_MIN;
	}
	Listnode *temp = q->front;
	int ret_data = temp->data;
	q->front = q->front->next;
	if (!q->front)
		q->rear = NULL;
	free(temp);
	q->size --;
	return ret_data;
}
typedef struct stack {
	Listnode *top;
} Stack;
void init_stack(Stack *s) {
	s->top = NULL;
}
int is_empty_stack(Stack *s) {
	return !s->top;
}
void push(Stack *s, int data) {
	Listnode *new = (Listnode *)malloc(sizeof(Listnode));
	new->data = data;
	new->next = s->top;
	s->top = new;
}
int pop(Stack *s) {
	if (is_empty_stack(s)) {
		printf("Underflow\n");
		return INT_MIN;
	}
	Listnode *temp = s->top;
	int ret_data = s->top->data;
	s->top = s->top->next;
	free(temp);
	return ret_data;
}
void reverse_queue(Queue *q1, Queue *q2) {
	Stack s;
	init_stack(&s);
	while (!is_empty(q1))
		push(&s, dequeue(q1));
	while (!is_empty_stack(&s))
		enqueue(q2, pop(&s));
}
void print_queue(Queue *q) {
	while (!is_empty(q))
		printf("%d\n", dequeue(q));
}
int main() {
	Queue q1, q2;
	init_queue(&q1);
	init_queue(&q2);
	int temp, cmd;
	while (scanf("%d%d", &temp, &cmd) == 2) {
		if (cmd == 0)
			enqueue(&q1, temp);
		else
			dequeue(&q1);
	}
	reverse_queue(&q1, &q2);
	print_queue(&q2);
	return 0;
}
