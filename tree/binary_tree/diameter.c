#include <stdio.h>
#include <stdlib.h>
typedef struct treenode {
	int data;
	struct treenode *left, *right;
} Treenode;
Treenode *newnode(int data) {
	Treenode *root = (Treenode *)malloc(sizeof(Treenode));
	root->data = data;
	root->left = root->right = NULL;
	return root;
}
int Max(int a, int b) {
	return (a > b)? a: b;
}
int diameter(Treenode *root, int *diam) {
	if (!root) return 0;
	int left = diameter(root->left, diam);
	int right = diameter(root->right, diam);
	if (left + right > *diam)
		*diam = left + right;
	return Max(right, left) + 1;
}
int main() {
	/* Add test code */
	Treenode *root = NULL;
	root = newnode(1);
	root->left = newnode(1);
	root->left->left = newnode(1);
	root->right = newnode(1);
	root->right->right = newnode(1);
	root->right->left= newnode(1);
	root->right->left->right= newnode(1);
	root->right->left->left= newnode(1);
	root->right->left->left->right= newnode(1);
	root->right->left->left->right->right = newnode(1);
	root->right->left->left->right->left = newnode(1);
	root->right->left->left->right->left->right = newnode(1);
	int D;
	diameter(root, &D);
	printf("%d\n", D);
	return 0;
}
