#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef struct treenode {
	int data;
	struct treenode *left, *right;
} Treenode;
Treenode *insert_node(Treenode *root, int data) {
	Treenode *new = (Treenode *)malloc(sizeof(Treenode));
	new->data = data;
	new->left = new->right = NULL;
	return new;
}
int max(int a, int b, int c) {
	return (a > b)? (a > c)? a: c: (b > c)? b: c;
}
int find_max(Treenode *root) {
	if (root == NULL)
		return INT_MIN;
	int maxL = find_max(root->left), maxR = find_max(root->right);
	return max(maxL, maxR, root->data);
}
int main() {
	/* Add test code */
	return 0;
}
