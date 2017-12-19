#include <stdio.h>
#include <stdlib.h>
typedef struct treenode {
	int data;
	struct treenode *left, *right;
} Treenode;
Treenode *kth_smallest_element(Treenode *root, int k, int *count) {
	if (!root) return NULL;
	int left_node = kth_smallest_element(root->left);
	if (left_node) return left_node;
	if (++ *count == k) return root;
	return kth_smallest_element(root->right);
}
int main() {
	/* Add test code */
	return 0;
}
