#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
typedef struct treenode {
	int data;
	struct treenode *left, *right;
} Treenode;
Treenode *insert_node(Treenode *root, int data) {
	Treenode *new = (Treenode *)malloc(sizeof(Treenode));
	new->data = data;
	new->left = new->right = NULL;
	return new;
}

/* QUEUE */
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

/* Find depth */
int find_depth_iteration(Treenode *root) {
	if (!root) return INT_MIN;
	Queue q;
	init_queue(&q);
	enqueue(&q, root);
	enqueue(&q, NULL);
	int depth = 0;
	while (1) {
		root = dequeue(&q);
		if (root) {
			if (root->left) enqueue(&q, root->left);
			if (root->right) enqueue(&q, root->right);
		} else {
			depth ++;
			if (!is_empty_stack(&s))
				enqueue(&q, NULL);
		}
	}
	return level;
}
int main() {
	/* Add test code */
	return 0;
}
