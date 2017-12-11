#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef struct treenode {
	int data;
	struct treenode *left, *right;
} Treenode;
Treenode *insert(Treenode *root, int data) {
	Treenode *new = (Treenode *)malloc(sizeof(Treenode));
	new->data = data;
	new->left = new->right = NULL;
	if (!root) return new;
	Treenode *temp = root;
	while (temp->right) temp = temp->right;
	temp->right = new;
	new->left = temp;
	return root;
}
Treenode *find_mid(Treenode *head) {
	Treenode *slow = head, *fast = head;
	while (fast && fast->right) {
		fast = fast->right->right;
		slow = slow->right;
	}
	return slow;
}
Treenode *convert(Treenode *head) {
	if (!head || !head->left && !head->right)
		return head;
	Treenode *mid = find_mid(head);
	Treenode *alt_head = mid->right;
	if (mid->left) mid->left->right = NULL;
	if (mid->right) mid->right->left = NULL;
	mid->left = convert(head);
	mid->right = convert(alt_head);
	return mid;
}
void inorder(Treenode *root) {
	if (!root) return;
	inorder(root->left);
	printf("%d\n", root->data);
	inorder(root->right);
}
int main() {
	/* Add test code */
	return 0;
}
