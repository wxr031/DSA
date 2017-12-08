#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct treenode {
	int data;
	struct treenode *left, *right;
} Treenode;
Treenode *New_Node(int data) {
	Treenode *new_node = (Treenode *)malloc(sizeof(Treenode));
	new_node->left = new_node->right = NULL;
	new_node->data = data;
	return new_node;
}
Treenode *reconstruct(int n, int preorder[], int inorder[]) {
	if (!n) return NULL;
	int left = strchr(inorder, preorder[0]) - preorder;
	int right = n - left - 1;
	Treenode *new_node = New_Node(preorder[0]);
	new_node->data = preorder[0];
	new_node->left = reconstruct(left, preorder + 1, inorder);
	new_node->right = reconstruct(right, preorder + left + 1, inorder + left + 1);
	return new_node;
}
