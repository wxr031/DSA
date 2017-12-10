#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INT_MIN 0x80000000
typedef struct queue{
	int capacity, size;
	int front, rear;
	int *array;
} Queue;
void init_queue(Queue *q) {
	q->capacity = 1;
	q->size = 0;
	q->front = 0;
	q->rear = -1;
	q->array = (int *)malloc(sizeof(int) * q->capacity);
}
void double_capacity(Queue *q) {
	int capacity_prev = q->capacity;
	q->capacity <<= 1;
	q->array = realloc(q->array, q->capacity);
	if (q->rear < q->front) {
		memcpy(q->array + capacity_prev, q->array, q->rear + 1);
		q->rear += capacity_prev;
	}
}
int is_full(Queue *q) {
	return q->size == q->capacity;
}
int is_empty(Queue *q) {
	return q->size == 0;
}
void enqueue(Queue *q, int data) {
	if (is_full(q))
		double_capacity(q);
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
void delete_queue(Queue *q) {
	free(q->array);
}
int main() {
	/* Add test code */
    return 0;
}
