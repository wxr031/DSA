#include <iostream>

typedef enum color {red, black} Color;
typedef struct treenode {
	int data;
	Color color;
	struct treenode *left, *right, *parent;
	
	treenode(int D, Color C): data(D), color(C) {
		left = right = parent = nullptr;
	}
} Treenode;

class red_black_tree {
	Treenode *root;
	void single_left_rotation(Treenode *);
	void single_right_rotation(Treenode *);
	void BST_insertion(Treenode *);
	void fix_violation(Treenode *);
	void inorder_aux(Treenode *curr) {
		if (curr == nullptr) return;
		inorder_aux(curr->left);
		std::cout << curr->data << "-->" << curr->color << std::endl;
		inorder_aux(curr->right);
	}
	void preorder_aux(Treenode *curr) {
		if (curr == nullptr) return;
		std::cout << curr->data << "-->" << curr->color << std::endl;
		preorder_aux(curr->left);
		preorder_aux(curr->right);
	}
	void postorder_aux(Treenode *curr) {
		if (curr == nullptr) return;
		postorder_aux(curr->left);
		postorder_aux(curr->right);
		std::cout << curr->data << "-->" << curr->color << std::endl;
	}
public:
	red_black_tree() {
		root = nullptr;
	}
	void insertion(int);
	void inorder();
	void preorder();
	void postorder();
};
void red_black_tree::single_left_rotation(Treenode *curr) {
	Treenode *temp = curr->right;
	curr->right = temp->left;
	if (curr->right != nullptr)
		curr->right->parent = curr;
	temp->parent = curr->parent;
	if (curr->parent == nullptr)
		root = temp;
	else if (curr->parent->left == curr)
		curr->parent->left = temp;
	else if (curr->parent->right == curr)
		curr->parent->right = temp;
	temp->left = curr;
	curr->parent = temp;
}
void red_black_tree::single_right_rotation(Treenode *curr) {
	Treenode *temp = curr->left;
	curr->left = temp->right;
	if (curr->left != nullptr)
		curr->left->parent = curr;
	temp->parent = curr->parent;
	if (curr->parent == nullptr)
		root = temp;
	else if (curr->parent->left == curr)
		curr->parent->left = temp;
	else if (curr->parent->right == curr)
		curr->parent->right = temp;
	temp->right = curr;
	curr->parent = temp;
}
void red_black_tree::fix_violation(Treenode *curr) {
	Treenode *parent_node = nullptr, *grandparent_node = nullptr;
	while (curr != root && curr->parent != root && curr->color == red && curr->parent->color == red) {
		parent_node = curr->parent;
		grandparent_node = parent_node->parent;
		if (grandparent_node->left == parent_node) {
			Treenode *uncle_node = grandparent_node->right;
			if (uncle_node != nullptr && uncle_node->color == red) {
				grandparent_node->color = red;
				parent_node->color = black;
				uncle_node->color = black;
				curr = grandparent_node;
			}
			else {
				if (parent_node->right == curr) {
					single_left_rotation(parent_node);
					std::swap(parent_node, curr);
				}
				single_right_rotation(grandparent_node);
				parent_node->color = black;
				grandparent_node->color = red;
				curr = parent_node;
			}
		}
		if (grandparent_node->right == parent_node) {
			Treenode *uncle_node = grandparent_node->left;
			if (uncle_node != nullptr && uncle_node->color == red) {
				grandparent_node->color = red;
				parent_node->color = black;
				uncle_node->color = black;
				curr = grandparent_node;
			}
			else {
				if (parent_node->left == curr) {
					single_right_rotation(parent_node);
					std::swap(parent_node, curr);
				}
				single_left_rotation(grandparent_node);
				parent_node->color = black;
				grandparent_node->color = red;
				curr = parent_node;
			}
		}
	}
	root->color = black;
}
void red_black_tree::BST_insertion(Treenode *new_node) {
	if (root == nullptr) {
		root = new_node;
		return;
	}
	Treenode *curr = root, *prev = nullptr;
	while (curr != nullptr) {
		prev = curr;
		if (new_node->data < curr->data)
			curr = curr->left;
		else curr = curr->right;
	}
	new_node->parent = prev;
	if (new_node->data < prev->data)
		prev->left = new_node;
	else prev->right = new_node;
	fix_violation(new_node);
}
void red_black_tree::insertion(int D) {
	Treenode *new_node = new Treenode(D, red);
	BST_insertion(new_node);
}
void red_black_tree::deletion(int D) {
	
}
void red_black_tree::inorder() {
	inorder_aux(root);
}
void red_black_tree::preorder() {
	preorder_aux(root);
}
void red_black_tree::postorder() {
	postorder_aux(root);
}
int main() {
	
}
