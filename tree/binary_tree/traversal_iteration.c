#include <stdio.h>
#include <stdlib.h>
#include "treenode_stack.h"
Treenode *insert_node(Treenode *root, int data) {
	Treenode *new_node = (Treenode *)malloc(sizeof(Treenode));
	if (!new_node) {
		perror("Memory Allocation Error\n");
		exit(EXIT_FAILURE);
	}
	new_node->data = data;
	new_node->left = new_node->right = NULL;
	return new_node;
}
// For Preorder and Inorder Traversal, the algorithm is similar.
// The only difference is when exactly should we print the data.

// Algorithm:
// 1. push left node into the stack until left node reaches NULL pointer.
// 2. pop the stack in order to get its parent.
// 3. make root points to the right node of its parent node (AKA: its sibling).

/* Preorder Traversal */
/* Version one */
void preorder1(Treenode *root) {
	if (!root) return;
	Stack s;
	init_stack(&s);
	while (1) {
		while (root) {
			printf("%d\n", root->data);
			push(&s, root);
			root = root->left;
		}
		if (is_empty_stack(&s))
			break;
		root = pop(&s);
		root = root->right;
	}
	delete_stack(&s);
}
/* Version two */
void preorder2(Treenode *root) {
	if (!root) return;
	Stack s;
	init_stack(&s);
	while (1) {
		if (root) {
			printf("%d\n", root->data);
			push(&s, root);
			root = root->left;
		} else if (!is_empty_stack(&s)) {
			root = pop(&s);
			root = root->right;
		} else break;
	}
	delete_stack(&s);
}

/* Inorder */
/* Version one */
void inorder1(Treenode *root) {
	if (!root) return;
	Stack s;
	init_stack(&s);
	while (1) {
		while (root) {
			push(&s, root);
			root = root->left;
		}
		if (is_empty_stack(&s))
			break;
		root = pop(&s);
		printf("%d\n", root->data);
		root = root->right;
	}
	delete_stack(&s);
}
/* Version 2 */
void inorder2(Treenode *root) {
	Stack s;
	init_stack(&s);
	while (1) {
		if (root) {
			push(&s, root);
			root = root->left;
		} else if (!is_empty_stack(&s)) {
			root = pop(&s);
			printf("%d\n", root->data);
			root = root->right;
		} else break;
	}
	delete_stack(&s);
}

/* Postorder */
/* Version 1 */
/* Using two stacks */
// Algorithm:
// 1. push the root into stack 1
// 2. while stack 1 is not empty:
//	pop a node from stack 1 and push it to stack 2
//	push the left and the right node from the popped stack to stack 1. (left node first, right node next).
// 3. pop every node from stack 2 and print its data until the stack is empty.
void postorder1(Treenode *root) {
	if (!root) return;
	Stack s1, s2;
	init_stack(&s2);
	init_stack(&s1);
	push(&s1, root);
	while (!is_empty_stack(&s1)) {
		root = pop(&s1);
		push(&s2, root);
		if (root->left) // We shouldn't push NULL pointer into the stack
			push(&s1, root->left);
		if (root->right) // We shouldn't push NULL pointer into the stack
			push(&s1, root->right);
	}
	while (!is_empty_stack(&s2))
		printf("%d\n", pop(&s2)->data);
}
/* Version 2 */
/* Using one stack */
// Algorithm:
// 1. push the root first, then the root's right child to the stack.
// 2. make root points to its left child.
// 3. while the stack is not empty:
//    if root is NULL:
//    (1) pop the stack and make root points to the popped element.
//    (2) if root is the right child of the stack's top element:
//            remove the right child from stack, push the root back into the stack
//            and make root points to its right child.
//        else:
//            print the root's data and pop the stack until the former condition occurs.
void postorder2(Treenode *root) {
	if (!root) return;
	Stack s;
	init_stack(&s);
	do {
		while (root) {
			if (root->right)
				push(&s, root->right);
			push(&s, root);
			root = root->left;
		}
		root = pop(&s);
		while (!is_empty_stack(&s) && root->right != top(&s)) {
			printf("%d\n", root->data);
			root = pop(&s);
		}
		if (!is_empty_stack(&s)) {
			pop(&s);
			push(&s, root);
			root = root->right;
		} else printf("%d\n", root->data);
	} while (!is_empty_stack(&s));
}
/* Version 3 */
void postorder3(Treenode *root) {
	if (!root) return;
	Stack s;
	init_stack(&s);
	do {
		while (root) {
			if (root->right)
				push(&s, root->right);
			push(&s, root);
			root = root->left;
		}
		root = pop(&s);
		if (!is_empty_stack(&s) && root->right == top(&s)) {
			pop(&s);
			push(&s, root);
			root = root->right;
		} else {
			printf("%d\n", root->data);
			root = NULL;
		}
	} while (!is_empty_stack(&s));
}
int main() {
	/* Add test code */
	return 0;
}
