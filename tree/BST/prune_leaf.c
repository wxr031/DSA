#include <stdio.h>
#include <stdlib.h>
typedef struct treenode {
	int data;
	struct treenode *left, *right;
} Treenode;
Treenode *prune_leaf(Treenode *root) {
	if (!root) return NULL;
	if (!root->left && !root->right) {
		free(root);
		return NULL;
	}
	root->left = prune_leaf(root->left);
	root->right = prune_leaf(root->right);
	return root;
}
Treenode *insert(Treenode *root, int data) {
	if (!root) {
		Treenode *new = (Treenode *)malloc(sizeof(Treenode));
		new->data = data;
		new->left = new->right = NULL;
		return new;
	}
	if (root->data > data)
		root->left = insert(root->left, data);
	else if (root->data < data)
		root->right = insert(root->right, data);
	return root;
}
void inorder(Treenode *root) {
	if (!root) return;
	inorder(root->left);
	printf("%d\n", root->data);
	inorder(root->right);
}
int main() {
	/* Add test data */
	return 0;
}
