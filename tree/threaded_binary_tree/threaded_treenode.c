#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef struct threaded_treenode {
	int data;
	struct threaded_treenode *left, *right;
	int Lthread, Rthread;
} Threaded_Treenode;
Threaded_Treenode *inorder_successor(Threaded_Treenode *root) {
	if (root->Rthread) 
		return root->right;
	root = root->right;
	while (!root->Lthread)
		root = root->left;
	return root;
}
void inorder(Threaded_Treenode *root) {
	Threaded_Treenode *temp = inorder_successor(root);
	while (temp != root) {
		printf("%d\n", temp->data);
		temp = inorder_successor(temp);
	}
}
Threaded_Treenode *preorder_successor(Threaded_Treenode *root) {
	if (!root->Lthread)
		return root->left;
	while (root->Rthread)
		root = root->right;
	return root->right;
}
void preorder(Threaded_Treenode *root) {
	Threaded_Treenode *temp = preorder_successor(root);
	while (temp != root) {
		printf("%d\n", temp->data);
		temp = preorder_successor(temp);
	}
}
Threaded_Treenode *newnode(void) {
	Threaded_Treenode *new = (Threaded_Treenode *)malloc(sizeof(Threaded_Treenode));
	new->data = INT_MAX;
	new->Lthread = 1;
	new->Rthread = 0;
	new->right = new;
	new->left = new;
	return new;
}
void insert(Threaded_Treenode *root, int data) {
	if (data <= root->data) {
		if (root->Lthread) {
			Threaded_Treenode *new = (Threaded_Treenode *)malloc(sizeof(Threaded_Treenode));
			new->data = data;
			new->Lthread = new->Rthread = 1;
			new->left = root->left;
			new->right = root;
			root->Lthread = 0;
			root->left = new;
			return;
		}
		else insert(root->left, data);
	}
	else if (data > root->data) {
		if (root->Rthread) {
			Threaded_Treenode *new = (Threaded_Treenode *)malloc(sizeof(Threaded_Treenode));
			new->data = data;
			new->Rthread = new->Lthread = 1;
			new->right = root->right;
			new->left = root;
			root->Rthread = 0;
			root->right = new;
			return;
		}
		insert(root->right, data);
	}
}
int main() {
	Threaded_Treenode *root = newnode(); // construct dummy node
	insert(root, 6);
	insert(root, 2);
	insert(root, 7);
	insert(root, 1);
	insert(root, 4);
	insert(root, 3);
	insert(root, 5);
	printf("success\n");
	preorder(root);
	return 0;
}
