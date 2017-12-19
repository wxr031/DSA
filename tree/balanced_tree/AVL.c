#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
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
	return root->height;
}
Treenode *LLrotation(Treenode *root) {
	Treenode *temp = root->left;
	root->left = temp->right;
	temp->right = root;
	root->height = max(get_height(root->left, get_height(root->right))) + 1;
	temp->height = max(get_height(temp->left), root->height) + 1;
	return temp;
}
Treenode *RRrotation(Treenode *root) {
	Treenode *temp = root->right;
	root->right = temp->left;
	temp->left = root;
	root->height = max(get_height(root->left, get_height(root->right))) + 1;
	temp->height = max(get_height(temp->right), root->height) + 1;
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
	if (!root) {
		Treenode *newnode = (Treenode *)malloc(sizeof(Treenode));
		assert(newnode);
		newnode->data = data;
		newnode->left = newnode->right = NULL;
		newnode->height = 0;
		return newnode;
	}
	else if (data < root->data) {
		root->left = insert(root->left, data);
		if (get_height(root->left) > get_height(root->right) + 1) {
			if (data < root->left->data)
				root = LLrotation(root);
			else
				root = LRrotation(root);
		}
	}
	else if (data > root->data) {
		root->right = insert(root->right, data);
		if (get_height(root->right) > get_height(root->left) + 1) {
			if (data > root->right->data)
				root = RRrotation(root);
			else
				root = RLrotation(root);
		}
	}
	root->height = max(get_height(root->left), get_height(root->right)) + 1;
	return root;
}
Treenode *delete(Treenode *root, int data) {
	if (!root) return root;
	if (root->data == data) {
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
		}
	}
	else if (data < root->data)
		root->left = delete(root->left, data);
	else if (data > root->data)
		root->right = delete(root->right, data);
	if (get_height(root->left) > get_height(root->right) + 1) {
		if (get_height(root->left->left) >= get_height(root->left->right))
			root = LLrotation(root);
		else
			root = LRrotation(root);
	}
	if (get_height(root->right) > get_height(root->left) + 1) {
		if (get_height(root->right->right) >= get_height(root->right->left))
			root = RRrotation(root);
		else 
			root = RLrotation(root);
	}
	root->height = max(get_height(root->left), get_height(root->right)) + 1;
	return root;
}
void inorder(Treenode *root) {
	if (!root) return;
	inorder(root->left);
	printf("%d\n", root->data);
	inorder(root->right);
}
void preorder(Treenode *root) {
	if (!root) return;
	printf("%d\n", root->data);
	preorder(root->left);
	preorder(root->right);
}
int main() {
	Treenode *root = NULL;
	root = insert(root, 3);
	root = insert(root, 2);
	root = insert(root, 4);
	root = insert(root, 5);
	root = insert(root, 1);
	root = insert(root, 6);
	root = insert(root, 7);
	root = delete(root, 1);
	root = delete(root, 3);
	root = delete(root, 5);
	inorder(root);
	printf("----------------\n");
	preorder(root);
	return 0;
}
