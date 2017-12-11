#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef struct treenode {
	int data;
	struct treenode *left, *right;
} Treenode;
typedef struct DLL {
int data;
	struct DLL *prev, *next;
} DLL;
Treenode *insert(Treenode *root, int data) {
	if (!root) {
		Treenode *new = (Treenode *)malloc(sizeof(Treenode));
		assert(new);
		new->data = data;
		new->right = new->left = NULL;
		return new;
	}
	if (root->data > data)
		root->left = insert(root->left, data);
	else if (root->data < data)
		root->right = insert(root->right, data);
	return root;
}
#ifdef CONVERT_TO_REAL_DLL
void BST_to_DLL1(Treenode *root, DLL **prev_DLL, DLL **head) {
	if (!root) return;
	BST_to_DLL1(root->left, prev_DLL, head);
	DLL *new = (DLL *)malloc(sizeof(DLL));
	new->data = root->data;
	new->prev = *prev_DLL;
	new->next = NULL;
	if (*prev_DLL) (*prev_DLL)->next = new;
	else *head = new;
	*prev_DLL = new;
	BST_to_DLL1(root->right, prev_DLL, head);
}
#endif

/* Functions below regard treenode as a kind of DLL */

/* First version */
/* Do inorder travel and fix pointer simultaneously */
Treenode *inorder(Treenode *root, Treenode **prev) {
	if (!root) return NULL;
	inorder(root->left, prev);
	root->left = (*prev);
	if (*prev) (*prev)->right = root;
	*prev = root;
	inorder(root->right, prev);
}
Treenode *BST_to_DLL(Treenode *root) {
	Treenode *prev = NULL;
	inorder(root, &prev);
	while (root->left)
		root = root->left;
	return root;
}
/* Second version */
void build_DLL(Treenode *root) {
	if (!root) return;
	if (root->left) {
		Treenode *left_node = root->left;
		build_DLL(root->left);
		while (left_node->right)
			left_node = left_node->right;
		root->left = left_node;
		left_node->right = root;
	}
	if (root->right) {
		Treenode *right_node = root->right;
		build_DLL(root->right);
		while (right_node->left)
			right_node = right_node->left;
		root->right = right_node;
		right_node->left = root;
	}
}
/* The function above does not change the head of the double linked list */
/* Thus, we need to construct a function that set root to the left most node */
Treenode *BST_to_DLL2(Treenode *root) {
	if (!root) return NULL;
	build_DLL(root);
	while (root->left)
		root = root->left;
	return root;
}
/* Third Version */
/* Use Threaded Binary Tree */


/* Fourth Version */
/* Fix left pointer first, then fix right pointer */
void build_left(Treenode *root, Treenode **prev) {
	if (!root) return;
	build_left(root->left, prev);
	root->left = *prev;
	*prev = root;
	build_left(root->right, prev);
}
Treenode *build_right(Treenode *head, Treenode *next) {
	while (head) {
		head->right = next;
		next = head;
		head = head->left;
	}
	return next;
}
Treenode *BST_to_DLL3(Treenode *root) {
	if (!root) return NULL;
	Treenode *prev = NULL;
	build_left(root, &prev);
	Treenode *head = root;
	while (head->right)
		head = head->right;
	return build_right(head, NULL);
}

int main() {
	Treenode *root = NULL;
	root = insert(root, 4);
	root = insert(root, 2);
	root = insert(root, 8);
	root = insert(root, 1);
	root = insert(root, 3);
	root = insert(root, 7);
	root = insert(root, 9);
	root = BST_to_DLL(root);
	while (root) {
		printf("%d\n", root->data);
		root = root->right;
	}
	return 0;
}
