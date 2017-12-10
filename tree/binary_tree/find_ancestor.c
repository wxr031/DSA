#include <stdio.h>
#include <stdlib.h>
typedef struct treenode {
	int data;
	struct treenode *left, *right;
} Treenode;
Treenode *insert(Treenode *root, int data) {
	Treenode *new = (Treenode *)malloc(sizeof(Treenode));
	new->data = data;
	new->left = new->right = NULL;
	return new;
}
Treenode *find_ancestor(Treenode *root, int data) {
	if (!root)
		return NULL;
	if ((root->left && root->left->data == data) || (root->right && root->right->data == data))
		return root;
	Treenode *temp;
	if (temp = find_ancestor(root->left, data))
		return temp;
	return find_ancestor(root->right, data); 
}
int main() {
	Treenode *root = NULL;
	root = insert(root, 1);
	root->left = insert(root, 2);
	root->right = insert(root, 3);
	root->left->left = insert(root, 4);
	root->left->right = insert(root, 5);
	root->right->left = insert(root, 6);
	root->right->right = insert(root, 7);
	root->right->right->right = insert(root, 8);
	root->right->right->right->right = insert(root, 9);
	int get;
	scanf("%d", &get);
	Treenode *ancestor = find_ancestor(root, get);
	if (ancestor)
		printf("%d\n", ancestor->data);
	else printf("no ancestor\n");
	return 0;
}
