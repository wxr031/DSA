#include <stdio.h>
#include <stdlib.h>
typedef struct treenode {
	int data;
	struct treenode *left, *right;
} Treenode;
Treenode *insert(Treenode *root, int data) {
	if (!root) {
		Treenode *new = (Treenode *)malloc(sizeof(Treenode));
		assert(new);
		new->data = data;
		new->right = new->left = NULL;
		return new;
	}
	if (root->data > data)
		root->left = insert(root->left, data);
	else if (root->data < data)
		root->right = insert(root->right, data);
	return root;
}

// Time complexity: O(n)
// Space complexity: O(n) -> for recursive stack
Treehead *cat(Treehead *lhead, Treehead *rhead) {
	if (!lhead) {
		rhead->left = rhead->right = rhead;
		return rhead;
	}
	if (!rhead) {
		lhead->left = lhead->right = lhead;
		return lhead;
	}
	Treehead *ltail = lhead->left;
	Treehead *rtail = rhead->right;
	rhead->left = ltail;
	ltail->right = rhead;
	lhead->left = rtail;
	rtail->right = lhead;
	root->left = lhead;
}
Treenode *BST_to_CDLL(Treenode *root) {
	if (!root) return NULL;
	Treenode *left = BST_to_DLL(root->left);
	Treenode *right= BST_to_DLL(root->right);
	return cat(cat(left, root), right);
}
