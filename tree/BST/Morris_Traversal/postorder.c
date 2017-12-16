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
void reverse_print(Treenode *start, Treenode *end) {
	Treenode *prev = NULL, *curr = start, *next = NULL;
	while (prev != end) {
		next = curr->right;
		curr->right = prev;
		prev = curr;
		curr = next;
	}
	curr = prev;
	prev = NULL;
	while (prev != start) {
		printf("%d\n", curr->data);
		next = curr->right;
		curr->right = prev;
		prev = curr;
		curr = next;
	}
}
void postorder(Treenode *root) {
	Treenode *dummy = (Treenode *)malloc(sizeof(Treenode));
	dummy->left = root;
	dummy->right = NULL;
	Treenode *prev = NULL;
	root = dummy;
	while (root) {
		prev = root->left;
		if (prev) {
			while (prev->right && prev->right != root)
				prev = prev->right;
			if (prev->right) {
				reverse_print(root->left, prev);
				prev->right = NULL;
				root = root->right;
			}
			else {
				prev->right = root;
				root = root->left;
			}
		}
		else root = root->right;
	}
}
int main() {
	/* Add test data */
	return 0;
}
