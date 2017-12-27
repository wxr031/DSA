#include <stdio.h>
#include <stdlib.h>
typedef struct listnode {
	int data;
	struct listnode *next;
} Listnode;
typedef struct treenode {
	int data;
	struct treenode *left, *right;
} Treenode;
Treenode *SLL_to_BST(Listnode *head, int left, int right) {
	if (left > right) return NULL;
	Treenode *new = (Treenode *)malloc(sizeof(Treenode));
	int mid = (left + right + 1) / 2;
	new->left = SLL_to_BST(head, left, mid - 1);
	new->data = head->data;
	head = head->next;
	new->right = SLL_to_BST(head, mid + 1, right);
}
void inorder(Treenode *root) {
	if (!root) return
	inorder(root->left);
	printf("%d\n", root->data);
	inorder(root->right);
}
int main() {
	
}
