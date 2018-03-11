#include <iostream>
#include <vector>
struct Node {
	int begin, end;
	std::vector<Node *> *child;
};
class suffix_tree {
	Node *root;
public:
	Node();
	
};
Node::Node() {
	root = nullptr;
}
