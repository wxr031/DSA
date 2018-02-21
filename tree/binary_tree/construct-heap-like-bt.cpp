#include <iostream>
#include <vector>

struct Node {
	int data;
	Node *left, *right;
	Node(int);
};
Node::Node(int val) {
	data = val;
	left = right = nullptr;
}

Node *convert_util(std::vector<int> in, int num, int st) {
	Node *curr = new Node(in[st]);
	for(int i = st + 1; i < num; ++i) {
		if(in[i] > in[i - 1]) {
			Node *node = new Node(in[i]);
			node->left = curr;
			curr = node;
		}
		else {
			curr->right = convert_util(in, num, i);
			break;
		}
	}
	return curr;
}
Node *convert(std::vector<int> in, int num) {
	if(num <= 0)
		return nullptr;
	Node *root = convert_util(in, num, 0);
	return root;
}
void inorder(Node *root) {
	if (!root) return;
	inorder(root->left);
	std::cout << root->data << std::endl;
	inorder(root->right);
}
void preorder(Node *root) {
	if (!root) return;
	std::cout << root->data << std::endl;
	preorder(root->left);
	preorder(root->right);
}
int main() {
	int num = 0;
	std::vector<int> in;
	for(int val; std::cin >> val;) {
		in.push_back(val);
		++num;
	}

	Node *root = convert(in, num);

	inorder(root);
	std::cout << "---\n";
	preorder(root);

	return 0;
}
