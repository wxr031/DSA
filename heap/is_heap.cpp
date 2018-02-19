#include <queue>
bool isHeap(Node *tree) {
	std::queue<Node *> nqueue;
	Node *curr = nullptr;
	nqueue.push(tree);
	bool cont = true;
	while(!nqueue.empty()) {
		curr = nqueue.front();
		nqueue.pop();
		if(cont) {
			if(curr->left) {
				if(curr->left->data > curr->data) {
					return false;
				}
				nqueue.push(curr->left);
			}
			else {
				cont = false;
			}
		}
		else if(curr->left) {
			return false;
		}
		if(cont) {
			if(curr->right) {
				if(curr->right->data > curr->data) {
					return false;
				}
				nqueue.push(curr->right);
			}
			else {
				cont = false;
			}
		}
		else if(curr->right) {
			return false;
		}
	}
	return true;
}
