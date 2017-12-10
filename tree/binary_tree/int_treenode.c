#include <stdio.h>
typedef struct treenode {
	int data;
	struct treenode *left, *right;
} Treenode;
Treenode *insert_node(Treenode *root, int data) {
	if (!root) {
		Treenode *new_node = (Treenode *)malloc(sizeof(Treenode));
		if (!new_node) {
			perror("Memory Allocation Error\n");
			exit(EXIT_FAILURE);
		}
		new_node->data = data;
		new_node->left = new_node->right = NULL;
		return new_node;
	}
	if (data < root->data)
		root->left = insert_node(root->left, data);
	else if (data > root->data)
		root->right = insert_node(root->right, data);
	return root;
}
