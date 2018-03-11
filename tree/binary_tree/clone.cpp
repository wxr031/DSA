#include <map>
#include <utility>

Node *copy_left_right(Node *tree, std::map<Node *, Node *> &hash) {
	if(!tree) return nullptr;
	Node *cp = new Node;
	hash.insert(std::make_pair(tree, cp));
	cp->left = copy_left_right(tree->left);
	cp->right = copy_left_right(tree->right);
	return cp;
}
void link_random(Node *tree, Node *cp, std::map<Node *, Node *> &hash) {
	if(!cp) return;
	cp->random = hash[tree->random];
	link_random(tree->left, cp->left, hash);
	link_random(tree->right, cp->right, hash);
}
Node *cloneTree(Node *tree) {
	std::map<Node *, Node *> hash;
	Node *cp = copy_left_right(tree);
	link_random(tree, cp);
	return tree;
}
