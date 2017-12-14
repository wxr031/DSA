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
void inorder(Treenode *root) {
	if (!root) return;
	inorder(root->left);
	printf("%d\n", root->data);
	inorder(root->right);
}
void preorder(Treenode *root) {
	if (!root) return;
	printf("%d\n", root->data);
	preorder(root->left);
	preorder(root->right);
}
int main() {
	/* Add test code */
	int num, i;
	int array[1024];
	scanf("%d", &num);
	for (i = 0; i < num; i ++)
		scanf("%d", array + i);
	Treenode *root = array_to_BST(array, 0, num - 1);
	inorder(root);
	preorder(root);
	return 0;
}
