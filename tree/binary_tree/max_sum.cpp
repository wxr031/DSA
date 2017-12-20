#include <iostream>
#include <climits>
#include <cstdlib>
#include <ctime>
class treenode {
public:
	int data;
	treenode *left, *right;
	treenode(int num): data(num), left(nullptr), right(nullptr) {}
	treenode(): data(0), left(nullptr), right(nullptr) {}

	friend class tree;
};
class tree {
public:
	treenode *root;
	treenode *insert(treenode *, int);
	void inorder(treenode *);
	void preorder(treenode *);

	friend void max_sum(tree *, int &);
};
int max_sum(treenode *root, int &max_val) {
	if (root == nullptr) return 0;
	int left_sum = max_sum(root->left, max_val);
	int right_sum = max_sum(root->right, max_val);
	if (left_sum <= 0 && right_sum <= 0) {
		max_val = std::max(max_val, root->data);
		return root->data;
	}
	if (left_sum > 0 && right_sum > 0) {
		max_val = std::max(max_val, root->data + left_sum + right_sum);
		return std::max(left_sum, right_sum) + root->data;
	}
	int max_val_cmp = std::max(left_sum, right_sum);
	int max_val_return = max_val_cmp + root->data;
	max_val = std::max(max_val, ((root->data < 0)? max_val_cmp: max_val_return));
	return max_val_return;
}
int main() {
	/* Add test code */
	return 0;
}
