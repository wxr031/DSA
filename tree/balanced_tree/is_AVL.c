#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef struct treenode {
	int data;
	struct treenode *left, *right;
} Treenode;
int max(int a, int b) {
	return (a > b)? a: b;
}
// if root is not AVL, return 0.
// else, return a nonzero positive number
int is_AVL(Treenode *root) {
	if (!root) return 1;
	if ((root->left && root->left->data > root->data) || (root->right && root->right->data < root->data))
		return 0;
	int Lheight = is_AVL(root->left);
	if (Lheight == 0) return 0;
	int Rheight = is_AVL(root->right);
	if (Rheight == 0) return 0;
	if (abs(Lheight - Rheight) > 1)
		return 0;
	return max(Lheight, Rheight) + 1;
}
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
int main() {
	Treenode *root = NULL;
	root = insert(root, 4);
	root = insert(root, 2);
	root = insert(root, 6);
	root = insert(root, 5);
	root = insert(root, 1);
	root = insert(root, 3);
	root = insert(root, 7);
	printf("%d\n", is_AVL(root));
	return 0;
}
