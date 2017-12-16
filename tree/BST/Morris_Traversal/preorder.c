#include <stdio.h>
#include <stdlib.h>
typedef struct treenode {
	int data;
	struct treenode *left, *right;
} Treenode;
Treenode *insert(Treenode *root, int data) {
	if (!root) {
		Treenode *newnode = (Treenode *)malloc(sizeof(Treenode));
		newnode->data = data;
		newnode->left = newnode->right = NULL;
		return newnode;
	}
	if (data < root->data)
		root->left = insert(root->left, data);
	else if (data > root->data)
		root->right = insert(root->right, data);
	return root;
}
void preorder(Treenode *root) {
	Treenode *prev = NULL;
	while (root) {
		prev = root->left;
		if (prev) {
			while (prev->right && prev->right != root)
				prev = prev->right;
			if (prev->right) {
				prev->right = NULL;
				root = root->right;
			}
			else {
				printf("%d\n", root->data);
				prev->right = root;
				root = root->left;
			}
		}
		else {
			printf("%d\n", root->data);
			root = root->right;
		}
	}
}
int main() {
	/* Add test data */
	return 0;
}
