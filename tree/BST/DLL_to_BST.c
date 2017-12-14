(Treenode *root) {
	if (!root) return;
	inorder(root->left);
	printf("%d\n", root->data);
	inorder(root->right);
}
int main() {
	/* Add test code */
	return 0;
}
