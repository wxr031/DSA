#include <iostream>
struct Node {
	int data;
	Node *left, *right;
	Node(int);
};
Node::Node(int val) {
	data = val;
	left = right = nullptr;
}
class Tree {
public:
	Node *root;
	Tree();
	Node *constructTree(int *, int *, int);
	void printInorder(Node *);
};
Tree::Tree() {
	root = nullptr;
}
Node *Tree::constructTree(int *pre, int *post, int size) {
	if(size <= 0)
		return nullptr;
	Node *newNode = new Node(pre[0]);
	if(size == 1)
		return newNode;
	int *ptr = std::find(post, post + size, pre[1]);
	int lnum = ptr - post + 1;
	newNode->left = constructTree(pre + 1, post, lnum);
	newNode->right = constructTree(pre + lnum + 1, post + lnum, size - lnum - 1);
	return newNode;
}
void Tree::printInorder(Node *root) {
	if(!root) return;
	printInorder(root->left);
	std::cout << root->data << std::endl;
	printInorder(root->right);
}
int main () {
    int pre[] = {1, 2, 4, 8, 9, 5, 3, 6, 7};
    int post[] = {8, 9, 4, 5, 2, 6, 7, 3, 1};
    int size = sizeof( pre ) / sizeof( pre[0] );
	Tree tree; 
    tree.root = tree.constructTree(pre, post, size);
    printf("Inorder traversal of the constructed tree: \n");
    tree.printInorder(tree.root);
    return 0;
}
