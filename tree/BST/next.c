#include <stdio.h>
#include <stdlib.h>
typedef struct treenode {
	int data;
	struct treenode *left, *right, *next;
} Treenode;
void link(Treenode *root) {
	Treenode *right_most = NULL, *next_level_head = NULL;
	Treenode *track = root;
	do {
		if (track->left) {
			if (next_level_head == NULL) {
				next_level_head = track->left;
				right_most = track->left;
			}
			else {
				right_most->next = track->left;
				right_most = right_most->next;
			}
		}
		if (track->right) {
			if (next_level_head == NULL) {
				next_level_head = track->right;
				right_most = track->right;
			}
			else {
				right_most->next = track->right;
				right_most = right_most->next;
			}
		}
		track = track->next;
	} while (track != root);
	if (!right_most) return;
	right_most->next = next_level_head;
	link(next_level_head);
}
void link_next(Treenode *root) {
	if (!root) return;
	root->next = root;
	link(root);
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
Treenode *insert(Treenode *root, int data) {
	if (!root) {
		Treenode *new = (Treenode *)malloc(sizeof(Treenode));
		new->data = data;
		new->left = new->right = new->next = NULL;
		return new;
	}
	if (root->data > data)
		root->left = insert(root->left, data);
	else if (root->data < data)
		root->right = insert(root->right, data);
	return root;
}
void print(Treenode *root) {
	if (!root) return;
	Treenode *next_level_head = NULL, *track = root;
	do {
		printf("%d\n", track->data);
		if (!next_level_head && track->left)
			next_level_head = track->left;
		if (!next_level_head && track->right)
			next_level_head = track->right;
		track = track->next;
	} while (track != root);
	print(next_level_head);
}
int main() {
	Treenode *root = NULL;
	root = insert(root, 4);
	root = insert(root, 8);
	root = insert(root, 2);
	root = insert(root, 6);
	root = insert(root, 3);
	root = insert(root, 0);
	root = insert(root, 9);
	root = insert(root, 1);
	root = insert(root, 7);
	inorder(root);
	puts("----");
	preorder(root);
	puts("----");
	link_next(root);
	inorder(root);
	puts("----");
	preorder(root);
	puts("----");
	print(root);
	return 0;
}
