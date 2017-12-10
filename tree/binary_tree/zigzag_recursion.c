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
void zigzag_traversal(Treenode *root, int state, int array[], int *count) {
	if (!root) return;
	if (state == 0) {
		array[*count] = root->data;
		++ *count;
		zigzag_traversal(root->right, state ^ 1, array, count);
		zigzag_traversal(root->left, state, array, count);
	}
	else {
		array[*count] = root->data;
		++ *count;
		zigzag_traversal(root->left, state ^ 1, array, count);
		zigzag_traversal(root->right, state, array, count);
	}
}
void zigzag(Treenode *root) {
	int array[1024];
	int count = 0;
	zigzag_traversal(root, 1, array, &count);
	for (int n = 0; n < count; n ++)
		printf("%d%c", array[n], " \n"[n == count - 1]);
}
int main() {
	/* Add test code */
	Treenode *root = NULL;
	root = insert_node(root, 1);
	root->left = insert_node(root, 2);
	root->right = insert_node(root, 3);
	root->left->left = insert_node(root, 4);
	root->left->right = insert_node(root, 5);
	root->right->left = insert_node(root, 6);
	root->right->right = insert_node(root, 7);
	zigzag(root);
	return 0;
}
