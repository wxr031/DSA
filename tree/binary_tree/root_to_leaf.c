#include <stdio.h>
#include <stdlib.h>
typedef struct treenode {
	int data;
	struct treenode *left, *right;
} Treenode;
Treenode *newnode(int data) {
	Treenode *new = (Treenode *)malloc(sizeof(Treenode));
	new->data = data;
	new->left = new->right = NULL;
	return new;
}
void print_path(Treenode *root, int pos, int* path) {
	if (!root) return;
	if (!root->left && !root->right) {
		for (int i = 0; i < pos; i ++)
			printf("%d ", path[i]);
		printf("%d\n", root->data);
		return;
	}
	path[pos] = root->data;
	print_path(root->left, pos + 1, path);
	print_path(root->right, pos + 1, path);
}
int main() {
	/* Add test code */
	Treenode *root = NULL;
	root = newnode(1);
	root->left = newnode(2);
	root->left->left = newnode(3);
	root->right = newnode(4);
	root->right->right = newnode(5);
	root->right->left= newnode(6);
	root->right->left->right= newnode(7);
	root->right->left->left= newnode(8);
	root->right->left->left->right= newnode(9);
	root->right->left->left->right->right = newnode(10);
	root->right->left->left->right->left = newnode(11);
	root->right->left->left->right->left->right = newnode(12);
	int path[1024];
	print_path(root, 0, path);
	return 0;
}
