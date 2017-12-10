#include <stdio.h>
typedef struct queue {
	int capacity, size;
	int front, rear;
	int *array;
} Queue;
void init_queue(Queue *q, int c) {
	q->capacity = c;
	q->size = q->front = 0;
	q->rear = c - 1;
	q->array = (int *)malloc(sizeof(int) * c);
}
int is_empty() {
	return q->size == 0;
}
void enqueue
int main() {
	
}
