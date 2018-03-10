#include <iostream>
#include <utility>
#include <vector>

struct Node {
	int data;
	Node *left, *right;
	Node(int);
};
Node::Node(int val) {
	data = val;
	left = right = nullptr;
}

struct compare {
	bool operator() (std::pair<int, int> p1, std::pair<int, int> p2) {
		return p1.second < p2.second;
	}
} cmp;
Node *convert(std::vector<std::vector<int> > matrix, int num) {
	std::vector<std::pair<int, int> > child;
	for(int i = 0; i < num; ++i) {
		int counter = 0;
		for(int j = 0; j < num; ++j)
			counter += matrix[i][j];
		child.push_back(std::make_pair(i, counter));
	}
	std::sort(child.begin(), child.end(), cmp);
#ifdef DEBUG
	for(auto p = child.begin(); p != child.end(); ++p) {
		std::cout << p->first << " " << p->second << std::endl;
	}
#endif
	std::vector<Node *> narr(num);
	std::vector<bool> visited(num, false);
	for(int i = 0; i < num; ++i) {
		int curr = child[i].first;
		narr[curr] = new Node(curr);
		if(child[i].second) {
			bool lflag = true;
			for(int j = 0; j < num; ++j) {
				if(matrix[curr][j] && !visited[j]) {
					if(lflag) {
						narr[curr]->left = narr[j];;
						lflag = false;
					}
					else {
						narr[curr]->right = narr[j];
					}
					visited[j] = true;
				}
			}
		}
	}
	return narr[child[num - 1].first];
}
void inorder(Node* root) {
	if(!root) return;
	inorder(root->left);
	std::cout << root->data << std::endl;
	inorder(root->right);
}
void preorder(Node *root) {
	if(!root) return;
	std::cout << root->data << std::endl;
	preorder(root->left);
	preorder(root->right);
}
int main() {
	int num;
	std::cin >> num;
	std::vector<std::vector<int> > matrix(num);
	for(int i = 0; i < num; ++i) {
		matrix[i].resize(num);
		for(int j = 0; j < num; ++j) {
			std::cin >> matrix[i][j];
		}
	}
#ifdef DEBUG
	for(int i = 0; i < num; ++i) {
		for(int j = 0; j < num; ++j) {
			std::cout << matrix[i][j] << " \n"[j == num - 1];
		}
	}
#endif
	Node *root = convert(matrix, num);
	inorder(root);
	std::cout << "-------\n";
	preorder(root);
	return 0;
}
