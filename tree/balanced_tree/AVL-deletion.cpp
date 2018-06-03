#include <iostream>
#include <algorithm>

struct Node {
	int data, height;
	Node *left, *right;
	Node(int data, int height): data(data), height(height), left(nullptr), right(nullptr) {}
};

class AVL {
	Node *root, *nil;
	Node *insert_util(int, Node *);
	void inorder_util(Node *);
	void preorder_util(Node *);
public:
	AVL() {
		root = nil = new Node(std::numeric_limits<int>::min(), -1);
	};
	Node *new_nil_end_node(int, int);
	Node *single_left_rotate(Node *);
	Node *single_right_rotate(Node *);
	Node *left_right_rotate(Node *);
	Node *right_left_rotate(Node *);
	void insert(int);
	void inorder();
	void preorder();
};

Node *AVL::new_nil_end_node(int data, int height) {
	Node *node = new Node(data, height);
	node->left = node->right = nil;
	return node;
}

Node *AVL::single_right_rotate(Node *root) {
	Node *child = root->right;
	root->right = child->left;
	child->left = root;
	root->height = std::max(root->left->height, root->right->height) + 1;
	child->height = std::max(child->left->height, child->right->height) + 1;
	return child;
}

Node *AVL::single_left_rotate(Node *root) {
	Node *child = root->left;
	root->left = child->right;
	child->right = root;
	root->height = std::max(root->left->height, root->right->height) + 1;
	child->height = std::max(child->left->height, child->right->height) + 1;
	return child;
}

Node *AVL::right_left_rotate(Node *root) {
	root->right = single_right_rotate(root->right);
	return single_left_rotate(root);
}

Node *AVL::left_right_rotate(Node *root) {
	root->left = single_left_rotate(root->left);
	return single_right_rotate(root);
}

Node *AVL::insert_util(int value, Node *root) {
	if(root == nil) return new_nil_end_node(value, 0);
	if(value < root->data) {
		root->left = insert_util(value, root->left);
		if(std::abs(root->left->height - root->right->height) == 2) {
			if(root->data < root->left->data)
				root = single_right_rotate(root);
			else root = left_right_rotate(root);
		}
	}
	else if(value > root->data) {
		root->right = insert_util(value, root->right);
		if(std::abs(root->left->height - root->right->height) == 2) {
			if(root->data > root->right->data)
				root = single_left_rotate(root);
			else root = right_left_rotate(root);
		}
	}
	root->height = std::max(root->left->height, root->right->height) + 1;
	return root;
}

void AVL::insert(int value) {
	root = insert_util(value, root);
}

void AVL::inorder_util(Node *root) {
	if(root == nil) return;
	inorder_util(root->left);
	std::cout << root->data << " ";
	inorder_util(root->right);
}

void AVL::inorder() {
	inorder_util(root);
	std::cout << "\n";
}


void AVL::preorder_util(Node *root) {
	if(root == nil) return;
	std::cout << root->data << " ";
	preorder_util(root->left);
	preorder_util(root->right);
}

void AVL::preorder() {
	preorder_util(root);
	std::cout << "\n";
}

int main() {
	int test;
	std::cin >> test;
	AVL tree;
	while(test--) {
		int node_num, node;
		std::cin >> node_num;
		for(int i = 0; i < node_num; i++) {
			std::cin >> node;
			tree.insert(node);
		}
#ifdef DEBUGGING
		tree.inorder();
		tree.preorder();
#endif
	}
}
