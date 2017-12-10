#include <stdio.h>
#include <stdlib.h>
typedef struct treenode {
	int data;
	struct treenode *left, *right;
} Treenode;
Treenode *mirror(Treenode *root) {
	if (!root) return NULL;
	Treenode *new_root;
	mirror(root->left);
	mirror(root->right);
	Treenode *temp = root->left;
	root->left = root->right;
	root->right = temp;
	return root;
}
int main() {
	/* Add test code */
	return 0;
}
