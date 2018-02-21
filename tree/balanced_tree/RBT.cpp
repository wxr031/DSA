#include <iostream>
struct Node {
	int data;
	bool color;
	Node *left, *right, *parent;
	Node(int, bool);
};
Node::Node(int val, bool col) {
	data = val;
	color = col;
	left = right = parent = nullptr;
}
class RBT {
	Node *root;
	
	/* Define color black as true, color re as false */
	const bool black = true, red = false;

	/* Utilities */
	void left_rotate(Node *);
	void right_rotate(Node *);
	Node *insert_node(int);
	void adjustment(Node *);

	void inorder_util(Node *);
	void preorder_util(Node *);
public:
	RBT();
	void insert(int);
	void inorder();
	void preorder();
};
RBT::RBT() {
	root = nullptr;
}

/* Rotation */
void RBT::right_rotate(Node *curr) {
	Node *child = curr->left, *parent = curr->parent;
	/* First, make the left child of 'curr' node points to 
	   the right child of 'child' node. */
	curr->left = child->right;
	if(child->right) {
		child->right->parent = curr;
	}

	/* Next, make the parent of 'child' points to the parent of 
	   'curr' node */
	if(!parent) {
		/* if curr is root itself, make 'child' node new root */
		root = child;
	}
	else if(parent->left == curr) {
		parent->left = child;
	}
	else {
		parent->right = child;
	}
	child->parent = parent;
	/* Finally, make the right child of 'child' node points to curr */
	child->right = curr;
	curr->parent = child;
}
void RBT::left_rotate(Node *curr) {
	Node *child = curr->right, *parent = curr->parent;
	/* First, make the right child of 'curr' node points to 
	   the left child of 'child' node. */
	curr->right = child->left;
	if(child->left) {
		child->left->parent = curr;
	}

	/* Next, make the parent of 'child' points to the parent of 
	   'curr' node */
	if(!parent) {
		/* if curr is root itself, make 'child' node new root */
		root = child;
	}
	else if(parent->right == curr) {
		parent->right = child;
	}
	else {
		parent->left = child;
	}
	child->parent = parent;
	/* Finally, make the left child of 'child' node points to curr */
	child->left = curr;
	curr->parent = child;
}

/* Insert node */
/* The implementation of inserting a node is nearly the same as the
   insertion of binary search tree */
Node *RBT::insert_node(int val) {
	if(!root) {
		return root = new Node(val, black);
	}
	Node *curr = root, *prev = nullptr;
	
	/* Find proper position */
	while(curr) {
		prev = curr;
		if(val < curr->data) {
			curr = curr->left;
		}
		else if(val > curr->data) {
			curr = curr->right;
		}
	}
	
	/* Insert new node */
	Node *temp = new Node(val, red);
	if(val < prev->data) {
		prev->left = temp;
	}
	else if(val > prev->data) {
		prev->right = temp;
	}
	temp->parent = prev;

	return temp;
}

/* Adjustment */
void RBT::adjustment(Node *curr) {
	/* continue the loop while curr is not root and
	   both the color of root and its parent are red */
	while(curr->parent && curr->color == red
			&& curr->parent->color == red) {
		Node *parent = curr->parent, *grand = parent->parent;

		/* First Case */
		/* if the 'parent' node is the left child of 'grand' */
		if(grand->left == parent) {
			Node *uncle = grand->right;
			
			/* Case 1 */
			/* uncle is red, only recoloring required */
			if(uncle && uncle->color == red) {
				parent->color = uncle->color = black;
				grand->color = red;
				curr = grand;
			}
			
			/* uncle is black, rotation and recoloring required */
			else {
				
				/* Case 2 */
				/* 'curr' node is the outside grandchild of 'grand' node */
				/* right rotation and recoloring required */
				grand->color = red;
				if(parent->left == curr) {
					parent->color = black;
					right_rotate(grand);
					curr = parent;
				}
				/* Case 3 */
				/* 'curr' node is the inside grandchild of 'grand' node */
				/* do left rotation on 'parent' node first, 
				   then do right rotation on grand node  */
				else {
					curr->color = black;
					left_rotate(parent);
					right_rotate(grand);
				}
			}
		}

		/* Second Case */
		/* if the 'parent' node is the right child of 'grand' */
		/* Implementation is similar to the First Case */
		else {
			Node *uncle = grand->left;
			if(uncle && uncle->color == red) {
				parent->color = uncle->color = black;
				grand->color = red;
				curr = grand;
			}
			else {
				grand->color = red;
				if(parent->right == curr) {
					parent->color = black;
					left_rotate(grand);
					curr = parent;
				}
				else {
					curr->color = black;
					right_rotate(parent);
					left_rotate(grand);
				}
			}
		}
	}

	/* Always render the color of root node black */
	root->color = black;
}

/* Full Insertion */
void RBT::insert(int val) {
	adjustment(insert_node(val));
}
void RBT::inorder_util(Node *curr) {
	if(!curr) return;
	inorder_util(curr->left);
	std::cout << curr->data << " " << 
		((curr->color == red) ? "red" : "black") << std::endl;
	inorder_util(curr->right);
}
void RBT::inorder() {
	inorder_util(root);
}
void RBT::preorder_util(Node *curr) {
	if(!curr) return;
	std::cout << curr->data << " " << 
		((curr->color == red) ? "red" : "black") << std::endl;
	preorder_util(curr->left);
	preorder_util(curr->right);
}
void RBT::preorder() {
	preorder_util(root);
}
int main() {
	int num;
	RBT tree;
	while(std::cin >> num) {
		tree.insert(num);
		std::cout << "*******\n";
		tree.inorder();
		std::cout << "-------\n";
		tree.preorder();
		std::cout << "*******\n\n\n";
	}
	return 0;
}
