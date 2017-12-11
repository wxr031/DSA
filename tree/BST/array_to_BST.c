#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef struct treenode {
	int data;
	struct treenode *left, *right;
} Treenode;
Treenode *array_to_BST(int array[], int L_id, int R_id) {
	if (L_id > R_id) return NULL;
	int mid = (L_id + R_id + 1) / 2;
	Treenode *new = (Treenode *)malloc(sizeof(Treenode));
	new->data = array[mid];
	new->left = array_to_BST(array, L_id, mid - 1);
	new->right = array_to_BST(array, mid + 1, R_id);
	return new;
}
int main() {
	/* Add test code */
	return 0;
}
