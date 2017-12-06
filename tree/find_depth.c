#include <stdio.h>
#include <stdlib.h>
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
void find_depth(Treenode *root, int depth_temp, int *depth) {
	if (!root) {
		*depth = (depth_temp > *depth)? depth_temp: *depth;
		return;
	}
	find_depth(root->left, depth_temp + 1, depth);
	find_depth(root->right, depth_temp + 1, depth);
}
int main() {
	/* Add test code */
	return 0;
}
