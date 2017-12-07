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
int adjust(Treenode *root) {
	if (!root) return 0;
	int res = 0;
	while (root->left) {
		root = root->left;
		res ++;
	}
	return res;
}
void vertical_sum(Treenode *root, int column, int rem[]) {
	if (!root) return;
	vertical_sum(root->left, column - 1, rem);
	vertical_sum(root->right, column + 1, rem);
	rem[column] += root->data;
}
int main() {
	/* Add test code */
	return 0;
}
