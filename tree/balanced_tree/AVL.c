#include <stdio.h>
#include <stdlib.h>
typedef struct treenode {
	int data;
	struct treenode *left, *right;
	int height; // Add height as a part of declaration
} Treenode;
int max(int a, int b) {
	return (a > b)? a: b;
}
int get_height(Treenode *root) {
	if (!root) return -1;
	else return root->height;
}
Treenode *LLrotation(Treenode *root) {
	Treenode *temp = root->left;
	root->left = temp->right;
	temp->right = root;
	root->height = max(get_height(root->left), get_hight(root->right)) + 1;
	height->height = max(get_height(height->left), get_hight(height->right)) + 1;
	return temp;
}
Treenode *RRrotation(Treenode *root) {
	Treenode *temp = root->right;
	root->left = temp->left;
	temp->left = root;
	root->height = max(get_height(root->left), get_hight(root->right)) + 1;
	height->height = max(get_height(height->left), get_hight(height->right)) + 1;
	return temp;
}
Treenode *LRrotation(Treenode *root) {
	root->left = RRrotation(root->left);
	return LLrotation(root);
}
Treenode *RLrotation(Treenode *root) {
	root->right = LLrotation(root->right);
	return RRrotation(root);
}
Treenode *insert(Treenode *root, int data) {
	if (root->data == data) {
		/* Add code */
	}
	else if (data < root->data)
		root->left = insert(root->left, data);
	else
		root->right = insert(root->right, data);
	root->height = max(height(root->left), height(root->right)) + 1;
	return root;
}

