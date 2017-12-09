#include <stdio.h>
#include <stdlib.h>
typedef struct treenode {
	int data;
	struct treenode *left, *right;
} Treenode;
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
}
Treenode *delete(Treenode *root, int data) {
	if (!root) return NULL;
	if (root->data > data)
		root->left = delete(root->left, data);
	else if (root->data < data)
		root->right = delete(root->right, data);
	else {
		if (!root->left || !root->right) {
			Treenode *temp = NULL;
			if (root->left)
				temp = root->left;
			if (root->right)
				temp = root->right;
			free(root);
			return temp;
		}
		else {
			Treenode *max = root->left;
			while (max->right) max = max->right;
			root->data = max->data;
			root->left = delete(root->left, max->data);
		}
	}
	return root;
}
void inorder(Treenode *root) {
	if (!root) return;
	inorder(root->left);
	printf("%d\n", root->data);
	inorder(root->right);
}
int main() {
	/* Add test code */
	return 0;
}
