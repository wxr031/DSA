#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef struct treenode {
	int data;
	struct treenode *left, *right;
} Treenode;
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
Treenode *LCA(Treenode *root, int num1, int num2) {
	if (!root) return NULL;
	if (num1 > root->data && num2 > root->data)
		return LCA(root->right, num1, num2);
	if (num1 < root->data && num2 < root->data)
		return LCA(root->left, num1, num2);
	return root;
}
int main() {
	Treenode *root = NULL;
	root = insert(root, 4);
	root = insert(root, 3);
	root = insert(root, 9);
	root = insert(root, 1);
	root = insert(root, 8);
	root = insert(root, 13);
	root = insert(root, 2);
	root = insert(root, 6);
	int num1, num2;
	scanf("%d%d", &num1, &num2);
	printf("%d\n", LCA(root, num1, num2)->data);
	return 0;
}
