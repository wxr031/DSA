#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct treenode {
	char data;
	struct treenode *left, *right;
} Treenode;
Treenode *insert(Treenode *root, char data) {
	Treenode *new = (Treenode *)malloc(sizeof(Treenode));
	new->data = data;
	new->left = new->right = NULL;
	return new;
}
Treenode *newnode(char c) {
	Treenode *new = (Treenode *)malloc(sizeof(Treenode));
	new->data = c;
	new->left = new->right = NULL;
	return new;
}
// 'I' represent internal node
// 'L' represent leaf
Treenode *IL_tree(char pre_str[], int N, int *curr) {
	if (N == *curr) return NULL;
	Treenode *new = newnode(pre_str[*curr]);
	++ *curr;
	if (pre_str[*curr] == 'I') {
		new->left = IL_tree(pre_str, N, curr);
		new->right = IL_tree(pre_str, N, curr);
	}
	return new;
}
void inorder(Treenode *root) {
	if (!root) return;
	inorder(root->left);
	printf("%c\n", root->data);
	inorder(root->right);
}
int main() {
	char str[1024];
	Treenode *root = NULL;
	scanf("%s", str);
	int count = -1;
	root = IL_tree(str, strlen(str), &count);
	inorder(root);
	return 0;
}
