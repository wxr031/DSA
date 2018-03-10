#include <iostream>
#include <limits>
struct Node {
	int data;
	Node *left, *right;
	Node(int val);
};
Node::Node(int val) {
	data = val;
	left = right = nullptr;
}
Node *pre_to_bst_aux(int lrange, int rrange, int pre[], int &c) {
	if(pre[c] > rrange || pre[c] < lrange)
		return nullptr;
	int val = pre[c++];
	Node *node = new Node(val);
	node->left = pre_to_bst_aux(lrange, val, pre, c);
	node->right = pre_to_bst_aux(val, rrange, pre, c);
	return node;
}
Node *pre_to_bst(int pre[]) {
	int c = 0;
	return pre_to_bst_aux(std::numeric_limits<int>::min(),
			std::numeric_limits<int>::max(), pre, c);
}
void inorder(Node *root) {
	if(!root) return;
	inorder(root->left);
	std::cout << root->data << std::endl;
	inorder(root->right);
}
void preorder(Node *root) {
	if(!root) return;
	std::cout << root->data << std::endl;
	preorder(root->left);
	preorder(root->right);
}
int main() {
	int pre[] = {10, 5, 1, 7, 40, 50};
	Node *root = pre_to_bst(pre);
	inorder(root);
	std::cout << "-----\n";
	preorder(root);
	return 0;
}
