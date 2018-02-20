#include <iostream>

class Node;
class BT;

struct Node {
	int data;
	Node *left, *right;

	Node(int data): data(data), left(nullptr), right(nullptr){};
};
class BT {
	Node *root;

	void deconstruct_util(Node *);

	Node *insert_util(Node *, int);
	Node *remove_util(Node *, int, bool &);
	Node *find_successor(Node *, int &);

	void inorder_util(Node *);
	void preorder_util(Node *);
	void postorder_util(Node *);

public:
	BT();
	~BT();

	void insert(int);
	bool remove(int);

	void inorder();
	void preorder();
	void postorder();
	void levelorder();
};

/* constructor */
BT::BT() {
	root = nullptr;
}

/* deconstructor */
void BT::deconstruct_util(Node *curr) {
	if(!curr) return;
	deconstruct_util(curr->left);
	deconstruct_util(curr->right);
	delete curr;
}
BT::~BT() {
	deconstruct_util(root);
}

/* insert node */
Node *BT::insert_util(Node *curr, int data) {
	if (curr == nullptr) {
		Node *node = new Node(data);
		return node;
	}
	if (data < curr->data)
		curr->left = insert_util(curr->left, data);
	else if (data > curr->data)
		curr->right = insert_util(curr->right, data);
	return curr;
}
void BT::insert(int data) {
	root = insert_util(root, data);
}

/* remove node */
Node *BT::find_successor(Node *curr, int &successor) {
	if(!curr->right) {
		successor = curr->data;
		Node *ret = curr->left;
		delete curr;
		return ret;
	}
	curr->right = find_successor(curr->right, successor);
	return curr;
}
Node *BT::remove_util(Node *curr, int data, bool &flag) {
	if (!curr) {
		flag = false;
		return curr;
	}
	else if (data < curr->data) {
		curr->left = remove_util(curr->left, data, flag);
		return curr;
	}
	else if (data > curr->data) {
		curr->right = remove_util(curr->right, data, flag);
		return curr;
	}
	else {
		if(!curr->left) {
			Node *ret = curr->right;
			delete curr;
			return ret;
		}
		else if(!curr->right) {
			Node *ret = curr->left;
			delete curr;
			return ret;
		}
		else {
			int successor;
			curr->left = find_successor(curr->left, successor);
			curr->data = successor;
			return curr;
		}
	}
}

bool BT::remove(int data) {
	bool flag = true;
	root = remove_util(root, data, flag);
	return flag;
}

/* inorder traversal */
void BT::inorder_util(Node *root) {
	if (root == nullptr) return;
	inorder_util(root->left);
	std::cout << root->data << " ";
	inorder_util(root->right);
}
void BT::inorder() {
	inorder_util(root);
	std::cout << "\n";
}
void BT::preorder_util(Node *root) {
	if (root == nullptr) return;
	std::cout << root->data << " ";
	preorder_util(root->left);
	preorder_util(root->right);
}
void BT::preorder() {
	preorder_util(root);
	std::cout << "\n";
}
void BT::postorder_util(Node *root) {
	if (root == nullptr) return;
	postorder_util(root->left);
	postorder_util(root->right);
	std::cout << root->data << " ";
}
void BT::postorder() {
	postorder_util(root);
	std::cout << "\n";
}
int main() {
	char cmd;
	BT tree;
	while(std::cin >> cmd) {
		switch(cmd) {
			case 'a': {
				int num;
				std::cin >> num;
				tree.insert(num);
				break;
			}
			case 'r': {
				int num;
				std::cin >> num;
				std::cout << tree.remove(num) << std::endl;
				break;
			}
			case 'i':
				tree.inorder();
				break;
			case 'p':
				tree.preorder();
				break;
			case 'o':
				tree.postorder();
				break;
			default:
				break;
		}
		std::cin.ignore();
	}
	return 0;
}
