#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef struct treenode {
	int data;
	struct treenode *left, *right;
} Treenode;

/* Version 1 */
void print(Treenode *root, int a, int b) {
	if (!root) return;
	if (root->data > a)
		add(root->left, a, b);
	if (a <= root->data && root->data <= b)
		printf("%d\n", root->data);
	if (root->data < b)
		add(root->right, a, b);
}

/* Version 2 */
/* Use threaded binary tree */
typedef struct threaded {
	int data;
	int Lbit, int Rbit;
	struct threaded *left, *right;
} Threaded;
Threaded *init(void) {
	Threaded *dummy = (Threaded)malloc(sizeof(Threaded));
	dummy->data = INT_MAX;
	dummy->Lbit = 0;
	dummy->Rbit = 1;
	dummy->left = dummy->right = dummy;
	return dummy;
}
Threaded insert(Threaded *root, int data) {
	if (!root->left && !root->right) {
		Threaded *newnode = (Threaded *)malloc(sizeof(Threaded));
		newnode->data = data;
		if (data < root->data) {
			new->Lbit = newnode->Rbit = 0;
			new->left = root->left;
			new->right = root;
			root->left = newnode;
			root->Lbit = 1;
		}
		else if (data > root->data) {
			new->Lbit = newnode->Rbit = 0;
			new->right = root->right;
			new->left = root;
			root->right = newnode;
			root->Rbit = 1;
		}
		return newnode;
	}
	if (data < root->data)
		root->left = insert(root->left, data);
	else if (data > root->data)
		root->right = insert(root->right, data);
	return root;
}
Threaded delete(Threaded *root, int data, Treenode *prev) {
	if (root->data == data) {
		Threaded *temp;
		if (!root->left && !root->right) {
			if (prev->right == root) {
				prev->right = root->right;
				prev->Rbit = 0;
				free(root);
				temp = NULL;
			}
			else if (prev->left == root) {
				prev->left = root->left;
				prev->Lbit = 0;
				free(root);
				temp = NULL;
			}
		}
		else if (!root->left) {
			root = root->right;
			temp = root;
			while (root->left)
				root = root->left;
			root->left = prev
		}
	}
}
