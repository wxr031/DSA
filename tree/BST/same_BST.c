#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <assert.h>
#include "treenode_stack.h"
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
int compare(Treenode *root1, Treenode *root2) {
	Stack s1, s2;
	init_stack(&s1);
	init_stack(&s2);
	while (root1) {
		push(&s1, root1);
		root1 = root1->left;
	}
	while (root2) {
		push(&s2, root2);
		root2 = root2->left;
	}
	while (1) {
		if (!root1 && !root2) {
			root1 = pop(&s1);
			root2 = pop(&s2);
			if (root1->data != root2->data)
				return 0;
			root1 = root1->right;
			root2 = root2->right;
		}
		else if (!root1) {
			root1 = pop(&s1);
			push(&s2, root2);
			if (root2->data != root1->data)
				return 0;
			root2 = root2->left;
			root1 = root1->right;
		}
		else if (!root2) {
			root2 = pop(&s2);
			push(&s1, root1);
			if (root1->data != root2->data)
				return 0;
			root1 = root1->left;
			root2 = root2->right;
		}
		else if (!is_empty_stack(&s1) && !is_empty_stack(&s2)){
			push(&s1, root1);
			root1 = root1->left;
			push(&s2, root2);
			root2 = root2->left;
		}
		else break;
	}
	return is_empty_stack(&s1) && is_empty_stack(&s2);
}
int main() {
	Treenode *root1 = NULL;
	root1 = insert(root1, 4);
	root1 = insert(root1, 2);
	root1 = insert(root1, 8);
	root1 = insert(root1, 1);
	root1 = insert(root1, 3);
	root1 = insert(root1, 7);
	root1 = insert(root1, 9);

	Treenode *root2 = NULL;
	root2 = insert(root2, 4);
	root2 = insert(root2, 8);
	root2 = insert(root2, 9);
	root2 = insert(root2, 3);
	root2 = insert(root2, 2);
	root2 = insert(root2, 1);
	root2 = insert(root2, 7);

	printf("%d\n", compare(root1, root2));
}
