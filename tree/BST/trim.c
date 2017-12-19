#include <stdio.h>
typedef struct treenode {
	int data;
	struct treenode *left, *right;
} Treenode;
Treenode *trim(Treenode *root, int r1, int r2) {
	if (!root) return NULL;
	root->left = trim(root->left, r1, r2);
	root->right = trim(root->right, r1, r2);
	if (root->data >= r1 && root->data <= r2)
		return root;
	if (root->data < r1)
		return root->right;
	return root->left;
}
int main() {
	/* Add test code */
	return 0;
}
