#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "treenode_queue.h"
Treenode *insert(int data) {
	Treenode *new = (Treenode *)malloc(sizeof(Treenode));
	new->data = data;
	new->left = new->right = new->cousin = NULL;
	return new;
}
void find_next_cousin(Treenode *root) {
	if (!root) return;
	Queue q;
	init_queue(&q);
	enqueue(&q, NULL);
	while (!is_empty_queue(&q)) {
		if (root) {
			root->cousin = top(&q);
			if (root->left)
				enqueue(&q, root->left);
			if (root->right)
				enqueue(&q, root->right);
		}
		else enqueue(&q, NULL);
		root = dequeue(&q);
	}
}
void inorder(Treenode *root) {
	if (!root) return;
	inorder(root->left);
	printf("%d\n", (root->cousin)? root->cousin->data: INT_MIN);
	inorder(root->right);
}
int main() {
	Treenode *root = NULL;
	find_next_cousin(root);
	inorder(root);
	return 0;
}
