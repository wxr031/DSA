#include <iostream>
#include <vector>

struct Node {
	int data;
	Node *left, *right;
	Node(int val): data(val) {
		left = right = nullptr;
	}
};
Node *find_mid_prev(Node *root) {
	if(!root || !root->right || !root->right->right)
		return root;
	Node *slow = root, *fast = root;
	while(fast->right->right && fast->right->right->right) {
		fast = fast->right->right;
		slow = slow->right;
	}
	return slow;
}
Node *sll2bst(Node *root) {
	if(!root || !root->right) 
		return root;
	/* In order to get the middle node of 'root', we seek for
		its previous node so that we can access its previous node */
	Node *mid_prev = find_mid_prev(root);
	Node *mid = mid_prev->right;

	/* Split the linked list into two halves by making
		mid_prev's right pointer points to null pointer. */
	mid_prev->right = nullptr;

	/* recursively construct the binary tree with the two
		splitted linked lists */
	mid->left = sll2bst(root);
	mid->right = sll2bst(mid->right);

	return mid;
}
void inorder(Node *root) {
	if(!root) return;
	inorder(root->left);
	std::cout << root->data << " ";
	inorder(root->right);
}
void preorder(Node *root) {
	if(!root) return;
	std::cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);
}
int main() {
	/* get the total number of elements in the linked list */
	int num;
	std::cin >> num;
	Node *root = nullptr, *trace = nullptr;
	/* construct the linked list iteratively */
	for(int i = 0; i < num; ++i) {
		int ele;
		std::cin >> ele;
		if(!root) {
			root = trace = new Node(ele);
		}
		else {
			trace->right = new Node(ele);
			trace = trace->right;
		}
	}
	root = sll2bst(root);

	/* check the sll2bst function by examining the inorder and
		preorder traversal of the root */
	inorder(root);
	std::cout << "\n-------------\n";
	preorder(root);
	std::cout << "\n";
	
	return 0;
}
