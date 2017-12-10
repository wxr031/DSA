#ifndef INT_QUEUE_H
#define INT_QUEUE_H

typedef struct listnode {
	int data;
	struct listnode *next;
} Listnode;
typedef struct queue {
	int size;
	Listnode *front, *rear;
} Queue;
void init_queue(Queue *q);
int is_empty(Queue *q);
void enqueue(Queue *q, int data);
int dequeue(Queue *q);

#endif
