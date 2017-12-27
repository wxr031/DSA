#include <iostream>
using namespace std;

class Treenode;
class BT;

class Treenode {
	int data;
	Treenode *left, *right;
public:
	Treenode(int data): data(data), left(nullptr), right(nullptr){};
	~Treenode();

	friend class BT;
};
class BT {
public:
	Treenode *root;
	BT(): root(nullptr){};

	Treenode *insert(Treenode *, int);

	void inorder(Treenode *);
	void preorder(Treenode *);
	void postorder(Treenode *);
	void levelorder(Treenode *);
};
Treenode *BT::insert(Treenode *root, int data) {
	if (root == nullptr) {
		Treenode *newnode = new Treenode(data);
		return newnode;
	}
	if (data < root->data)
		root->left = insert(root->left, data);
	else if (data > root->data)
		root->right = insert(root->right, data);
	return root;
}
void BT::inorder(Treenode *root) {
	if (root == nullptr) return;
	inorder(root->left);
	cout << root->data << endl;
	inorder(root->right);
}
void BT::preorder(Treenode *root) {
	if (root == nullptr) return;
	cout << root->data << endl;
	preorder(root->left);
	preorder(root->right);
}
void BT::postorder(Treenode *root) {
	if (root == nullptr) return;
	postorder(root->left);
	postorder(root->right);
	cout << root->data << endl;
}
int main() {
	BT root;
	root.root = root.insert(root.root, 4);
	root.root = root.insert(root.root, 5);
	root.root = root.insert(root.root, 2);
	root.root = root.insert(root.root, 7);
	root.root = root.insert(root.root, 6);
	root.root = root.insert(root.root, 1);
	root.root = root.insert(root.root, 8);
	root.root = root.insert(root.root, 3);
	root.root = root.insert(root.root, 9);
	root.inorder(root.root);
	cout << "-----" << endl;
	root.preorder(root.root);
	cout << "-----" << endl;
	root.postorder(root.root);
	cout << "-----" << endl;
	return 0;
}
