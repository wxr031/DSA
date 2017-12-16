#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef struct treenode {
	int data, element;
	struct treenode *left, *right;
} Treenode;
void convert(Treenode *root) {
	if (!root) return;
	Treenode *temp = root->left, *prev = NULL;
	if (temp) {
		while (temp->right) {
			prev = temp;
			temp = temp->right;
		}
		if (prev) {
			prev->right = NULL;
			root->element = temp->data;
			free(temp);
		}
		else root->left = NULL;
	}
	else root->element = INT_MIN;
	convert(root->left);
	convert(root->right);
}
// O(nlog(n))
Treenode *delete(Treenode *root, int data) {
	if (!root) return NULL;
	if (data == root->data) {
		if (!root->left || !root->right) {
			Treenode *temp = (root->left)? root->left: root->right;
			free(root);
			return temp;
		}
		else {
			Treenode *temp = root->left;
			while (temp->right)
				temp = temp->right;
			root->data = temp->data;
			root->left = delete(root->left, root->data);
			return root;
		}
	}
	else if (data < root->data)
		root->left = delete(root->left, data);
	else if (data > root->data)
		root->right = delete(root->right, data);
	return root;
}
void convert2(Treenode *root, Treenode *par, Treenode **prev, Treenode **prev_par, int *change) {
	if (!root) return;
	convert2(root->left, root, prev, prev_par, change);
	if (*change) {
		*change = 0;
		root->element = (*prev)->data;
		(*prev_par) = delete(*prev_par, root->element);
	}
	else {
		*change = 1;
		root->element = INT_MIN;
		*prev = root;
		*prev_par = par;
	}
	convert2(root->right, root, prev, prev_par, change);
}
void inorder(Treenode *root) {
	if (!root) return;
	inorder(root->left);
	printf("%d %d\n", root->data, root->element);
	inorder(root->right);
}
int main() {
	Treenode *root = (Treenode *)malloc(sizeof(Treenode));
	root->data = 6; root->element = 6;
	root->left = (Treenode *)malloc(sizeof(Treenode));
	root->left->data = 4; root->left->element = 2;
	root->left->left = (Treenode *)malloc(sizeof(Treenode));
	root->left->left->data = 2; root->left->left->element = 0;
	root->left->left->left = root->left->left->right = NULL;
	root->left->right = (Treenode *)malloc(sizeof(Treenode));
	root->left->right->data = 5; root->left->right->element = 0;
	root->left->right->left = root->left->right->right = NULL;
	root->right = (Treenode *)malloc(sizeof(Treenode));
	root->right->data = 9; root->right->element = 2;
	root->right->right = NULL;
	root->right->left = (Treenode *)malloc(sizeof(Treenode));
	root->right->left->data = 7; root->right->left->element = 1;
	root->right->left->left = NULL;
	root->right->left->right = (Treenode *)malloc(sizeof(Treenode));
	root->right->left->right->data = 8; root->right->left->right->element = 0;
	root->right->left->right->left = root->right->left->right->right = NULL;
	inorder(root);
	printf("----------\n");
	Treenode *prev = NULL, *prev_par = NULL;
	int change = 0;
	convert(root);
	inorder(root);
}
