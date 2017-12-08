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
Treenode *LCA(Treenode *root, Treenode *node1, Treenode *node2) {
	if (!root)
		return NULL;
	if (root == node1 || root == node2)
		return root;
	Treenode *left_node = LCA(root->left, node1, node2);
	Treenode *right_node = LCA(root->right, node1, node2);
	if (left_node && right_node)
		return root;
	return (left_node)? left_node: right_node;
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
	Treenode *lca = LCA(root, root->right->left->left->right->left, root->right->left->right);
	printf("%p %p\n", lca, root->right->left);
	return 0;
}
