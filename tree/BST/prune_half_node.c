#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef struct treenode {
	int data;
	struct treenode *left, *right;
} Treenode;
Treenode *prune(Treenode *root) {
	if (!root) return NULL;
	if (!root->left && !root->right)
		return root;
	root->left = prune(root->left);
	root->right = prune(root->right);
	if (!root->left) {
		Treenode *temp = root->right;
		free(root);
		return temp;
	}
	else if (!root->right) {
		Treenode *temp = root->left;
		free(root);
		return temp;
	}
	else return root;
}
int main() {
	/* Add test code */
	return 0;
}
