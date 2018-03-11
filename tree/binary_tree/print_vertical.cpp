#include <iostream>
#include <vector>
#include <map>
using Map = std::map<int, std::vector<int> >;
struct node {
	int data;
	node *left, *right;
	node(int val): data(val), left(nullptr), right(nullptr) {}
};
class tree {
	void get_vertical(node *, int, Map &);
public:
	node *root;
	void print_vertical();
	friend node *newNode(int);
};
void tree::get_vertical(node *curr, int hor_dist, Map &vmap) {
	if(!curr) return;
	vmap[hor_dist].push_back(curr->data);
	get_vertical(curr->left, hor_dist - 1, vmap);
	get_vertical(curr->right, hor_dist + 1, vmap);
}
void tree::print_vertical() {
	Map vmap;
	get_vertical(root, 0, vmap);
	Map::iterator it;
	for(it = vmap.begin(); it != vmap.end(); ++it) {
		for(int i = 0; i < it->second.size(); ++i)
			std::cout << it->second[i] << " ";
		std::cout << "\n";
	}
}
node *newNode(int data) {
	node *N = new node(data);
	return N;
}
int main() {
	tree T;
	T.root = newNode(1);
	T.root->left = newNode(2);
	T.root->right = newNode(3);
	T.root->left->left = newNode(4);
	T.root->left->right = newNode(5);
	T.root->right->left = newNode(6);
	T.root->right->right = newNode(7);
	T.root->right->left->right = newNode(8);
	T.root->right->right->right = newNode(9);
	std::cout << "Vertical order traversal is \n";
	T.print_vertical();
	return 0;
}
