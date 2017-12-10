#ifndef TREENODE_H
#define TREENODE_H
typedef struct treenode {
	int data;
	struct treenode *left, *right, *cousin;
} Treenode;
typedef struct listnode {
	Treenode *data;
	struct listnode *next;
} Listnode;
typedef struct queue {
	Listnode *front, *rear;
	int size;
} Queue;

void init_queue(Queue *q);
int is_empty_queue(Queue *q);
void enqueue(Queue *q, Treenode *data);
void delete_queue(Queue *q);
Treenode *dequeue(Queue *q);
Treenode *top(Queue *q);
#endif
