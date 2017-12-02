#include <stdio.h>
#include <stdlib.h>
#include "int_queue.h"
void init_queue(Queue *q) {
	q->size = 0;
	q->front = q->rear = NULL;
}
int is_empty(Queue *q) {
	return q->front == NULL; // return q->size == 0;
}
void enqueue(Queue *q, int data) {
	Listnode *new = (Listnode *)malloc(sizeof(Listnode));
	if (!new) {
		perror("Memory Error\n"); // fprintf(stderr, "Memory Error\n");
		exit(EXIT_FAILURE);
	}
	new->data = data;
	new->next = NULL;
	q->size ++;
	if (q->front == NULL) {
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
	q->size --;
	free(temp);
	return ret_data;
}
