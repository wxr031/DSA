#include <stdio.h>
#include <stdlib.h>
#include "treenode_stack.h"
Treenode *insert_node(Treenode *root, int data) {
	Treenode *new_node = (Treenode *)malloc(sizeof(Treenode));
	if (!new_node) {
		perror("Memory Allocation Error\n");
		exit(EXIT_FAILURE);
	}
	new_node->data = data;
	new_node->left = new_node->right = NULL;
	return new_node;
}
void swap(Stack *s0, Stack *s1) {
	Stack temp = *s0;
	*s0 = *s1;
	*s1 = temp;
}
void zigzag(Treenode *root) {
	if (!root) return;
	Stack s0, s1;
	init_stack(&s0);
	init_stack(&s1);
	int state = 0; // 0: first right then left | 1: first left then right
	push(&s0, root);
	while (!is_empty_stack(&s0)) {
		root = pop(&s0);
		printf("%d\n", root->data);
		if (state == 0) {
			if (root->left)
				push(&s1, root->left);
			if (root->right)
				push(&s1, root->right);
		}
		else if (state == 1) {
			if (root->right)
				push(&s1, root->right);
			if (root->left)
				push(&s1, root->left);
		}

		if (is_empty_stack(&s0)) {
			state ^= 1;
			swap(&s0, &s1);
		}
	}
}
int main() {
	/* Add test code */
	return 0;
}
