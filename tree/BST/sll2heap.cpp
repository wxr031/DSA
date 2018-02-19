#include <iostream>
#include <queue>

struct Node {
	int data;
	Node *left, *right;
	Node(int val): data(val) {
		left = right = nullptr;
	}
};

Node *sll2heap(Node *root) {
	if(!root)
		return nullptr;
	std::queue<Node *> pqueue;
	pqueue.push(root);
	Node *curr(nullptr);
	Node *track(root->right);
	while(track) {
		/* pop element from the queue */
		curr = pqueue.front();
		pqueue.pop();

		/* insert left node */
		pqueue.push(track);
		curr->left = track;
		track = track->right;
		curr->left->right = nullptr;
		
		/* if track reaches the end of the list
			break the loop immediately */
		if(!track) break;
		
		/* insert right node */
		pqueue.push(track);
		curr->right = track;
		track = track->right;
		curr->right->right = nullptr;
	}
	return root;
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
	Node *root(nullptr), *trace(nullptr);
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
	root = sll2heap(root);

	/* check the sll2bst function by examining the inorder and
		preorder traversal of the root */
	inorder(root);
	std::cout << "\n-------------\n";
	preorder(root);
	std::cout << "\n";
	
	return 0;
}
