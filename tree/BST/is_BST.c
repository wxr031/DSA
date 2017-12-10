#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <assert.h>
typedef struct treenode {
	int data;
	struct treenode *left, *right;
} Treenode;
Treenode *insert(Treenode *root, int data) {
	if (!root) {
		Treenode *new = (Treenode *)malloc(sizeof(Treenode));
		assert(new);
		new->data = data;
		new->right = new->left = NULL;
		return new;
	}
	if (root->data > data)
		root->left = insert(root->left, data);
	else if (root->data < data)
		root->right = insert(root->right, data);
	return root;
}
int is_BST1(Treenode *root, int *prev) {
	if (!root) return 1;
	if (!is_BST1(root->left, prev))
		return 0;
	if (root->data < *prev)
		return 0;
	*prev = root->data;
	return is_BST1(root->right, prev);
}
int is_BST2(Treenode *root, int max, int min) {
	if (!root) return 1;
	return root->data > max && root->data < min && is_BST2(root->left, max, root->data) && is_BST2(root->right, root->data, min);
}
int main() {
	/* Add test code */
	return 0;
}
