#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef struct treenode {
	int data;
	struct treenode *left, *right, *cousin;
} Treenode;
Treenode *insert(int data) {
	Treenode *new = (Treenode *)malloc(sizeof(Treenode));
	assert(new);
	new->data = data;
	new->left = new->right = new->cousin = NULL;
	return new;
}
void find_child_cousin(Treenode *root) {
	if (!root) return;
	if (root->left)
		root->left->cousin = root->right;
	if (root->right && root->cousin)
		root->right->cousin = root->cousin->left;
	find_child_cousin(root->left);
	find_child_cousin(root->right);
}
void find_cousin(Treenode *root) {
	if (!root) return;
	root->cousin = NULL;
	find_child_cousin(root);
}
void inorder(Treenode *root) {
	if (!root) return;
	inorder(root->left);
	if (root->cousin) printf("%d\n", root->cousin->data);
	else printf("No cousin\n");
	inorder(root->right);
}
int main() {
	Treenode *root = NULL;
	root = insert(1);
	root->left = insert(2);
	root->right = insert(3);
	root->left->left = insert(4);
	root->left->right = insert(5);
	root->right->left = insert(6);
	root->right->right = insert(7);
	find_cousin(root);
	inorder(root);
	return 0;
}
