#include <stdio.h>
#include <stdlib.h>
#define INT_MIN 0x80000000
typedef struct queue {
	int capacity, size;
	int front, rear;
	int *array;
} Queue;
void init_queue(Queue *q, int c) {
	q->capacity = c;
	q->size = q->front = 0;
	q->rear = c - 1; // or: q->rear = -1;
	q->array = (int *) malloc(c * sizeof(int));
}
int is_empty(Queue *q) {
	return q->size == 0;
}
int is_full(Queue *q) {
	return q->size == q->capacity;
}
void enqueue(Queue *q, int data) {
	if (is_full(q)) {
		printf("Overflow\n");
		return;
	}
	if (q->rear == q->capacity - 1) q->rear = 0;
	else q->rear ++;
	q->array[q->rear] = data;
	q->size ++;
}
int dequeue(Queue *q) {
	if (is_empty(q)) {
		printf("Underflow\n");
		return INT_MIN;
	}
	int return_data = q->array[q->front];
	if (q->front == q->capacity - 1) q->front = 0;
	else q->front ++;
	q->size --;
	return return_data;
}
int get_front(Queue *q) {
	if (is_empty(q)) {
		printf("Empty\n");
		return INT_MIN;
	}
	return q->array[q->front];
}
int get_rear(Queue *q) {
	if (is_full(q)) {
		printf("Full\n");
		return INT_MIN;
	}
	return q->array[q->rear];
}
int main() {
	/* Add test code */
    return 0;
}
