#include <stdio.h>
#include <stdlib.h>
typedef struct treenode {
	int data;
	struct treenode *left, *right;
} Treenode;
typedef struct listnode {
	Treenode *data;
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
int is_empty_queue(Queue *q) {
	return q->size == 0;
}
void enqueue(Queue *q, Treenode *data) {
	Listnode *new_node = (Listnode *)malloc(sizeof(Listnode));
	new_node->data = data;
	new_node->next = NULL;
	q->size ++;
	if (!q->front) {
		q->front = q->rear = new_node;
		return;
	}
	q->rear->next = new_node;
	q->rear = new_node;
}
void delete_queue(Queue *q) {
	if (!q->front) return;
	Listnode *temp = NULL;
	while (q->front) {
		temp = q->front;
		q->front = q->front->next;
		free(temp);
	}
}
Treenode *dequeue(Queue *q) {
	if (is_empty_queue(q)) {
		printf("Queue Underflow\n");
		return NULL;
	}
	Listnode *temp = q->front;
	Treenode *ret_data = temp->data;
	q->front = q->front->next;
	if (q->front == NULL)
		q->rear = NULL;
	q->size --;
	free(temp);
	return ret_data;
}
void level_order_traverse(Treenode *root) {
	Queue q;
	init_queue(&q);
	enqueue(&q, root);
	while (!is_empty_queue(&q)) {
		root = dequeue(&q);
		printf("%d\n", root->data);
		if (root->left)
			enqueue(&q, root->left);
		if (root->right)
			enqueue(&q, root->right);
	}
	delete_queue(&q);
}
int main() {
	/* Add test code */
	return 0;
}
